/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
 【平    台】北京龙邱智能科技TC264DA核心板
 【编    写】chiusir
 【E-mail】chiusir@163.com
 【软件版本】V1.1 版权所有，单位使用请先联系授权
 【最后更新】2020年10月28日
 【相关信息参考下列地址】
 【网    站】http:// www.lqist.cn
 【淘宝店铺】http:// longqiu.taobao.com
 ------------------------------------------------
 【dev.env.】AURIX Development Studio1.2.2及以上版本
 【Target 】 TC264DA/TC264D
 【Crystal】 20.000Mhz
 【SYS PLL】 200MHz
 ________________________________________________________________
 基于iLLD_1_0_1_11_0底层程序,

 使用例程的时候，建议采用没有空格的英文路径，
 除了CIF为TC264DA独有外，其它的代码兼容TC264D
 本库默认初始化了EMEM：512K，如果用户使用TC264D，注释掉EMEM_InitConfig()初始化函数。
 工程下\Libraries\iLLD\TC26B\Tricore\Cpu\CStart\IfxCpu_CStart0.c第164行左右。
 =================================================================
 程序配套视频地址：https:// space.bilibili.com/95313236
 =================================================================*/

#include "LQ_Balance.h"
#include "../APP/LQ_MPU6050_DMP.h"
#include <Platform_Types.h>
#include <stdio.h>
#include "../User/LQ_MotorServo.h"
#include "../APP/LQ_GPIO_KEY.h"
#include "../APP/LQ_TFT18.h"
#include "../Driver/LQ_ADC.h"
#include "../Driver/LQ_CCU6.h"
#include "../Driver/LQ_STM.h"
#include "LQ_MotorServo.h"
#include "../APP/LQ_IIC_Gyro.h"
#include "../Driver/LQ_SOFTI2C.h"
#include "../Driver/LQ_STM.h"
#include "../Driver/LQ_GPT12_ENC.h"
#include "../Driver/LQ_GTM.h"
#include "../User/LQ_PID.h"
uint8  Start_Flag=1;                    //启动标志
//float X_Balance_KP=2000.001,X_Balance_KI=3.0001,X_Balance_KD=30.001;  // 平衡环PID  Pitch轴角度环PID参数 动量轮
//float X_Balance_KP=4000.001,X_Balance_KI=4.0001,X_Balance_KD=60.001;  // 平衡环PID  Pitch轴角度环PID参数 动量轮
//float X_Velocity_KP=90,X_Velocity_KI=90;//动量轮电机速度环PI参数
float X_Balance_KP= 1900.001,X_Balance_KI=-51.801,X_Balance_KD=15;
float X_Velocity_KP=32,X_Velocity_KI=1.00;

//float Pitch_Zero=6.9,Pitch_error=0.00;//设置Pitch轴角度零点
float Pitch_Zero=-0.7,Pitch_error=0.00;
float Zero_error = 0.00;              // Pitch偏差值
int PWM_X,PWM_accel;                  // PWM中间量
sint16 MotorDutyA = 0;                // 飞轮电机驱动占空比数值
sint16 MotorDutyB = 0;                // 后轮电机驱动占空比数值

#define Balance_Kp  32                // 舵机PID参数
#define Balance_Kd   0.03             // 舵机PID参数
#define Balance_Ki   0.0020           // 舵机PID参数

#define Motor_Kp     12               // 后轮电机PID参数
#define Motor_Ki     20               // 后轮电机PID参数

short  Velocity = 30;                 // 速度，定时周期内为60个脉冲，龙邱带方向512编码器
short  PWMMotor, PWMServo;            // 电机舵机PMW变量中值
short  Motor_Bias, Motor_Last_Bias, Motor_Integration; // 电机所用参数
float   Integration;
int  Servo_PWM;
unsigned char Flag_Stop = 0, Flag_Show, Flag_Imu;          // 停车，显示，IMU完成标志位
extern int Vat;
extern int Vbat;
extern sint16 TempAngle;
extern sint16 OFFSET0;      //最远处，赛道中心值综合偏移量
extern sint16 OFFSET1;      //第二格
extern sint16 OFFSET2;      //最近，第三格
extern sint16 TXV;          //梯形的左高度，右高度
int motohoulun = 600;
extern int  Servo_PWM11;
void Balance(void)
{
    int  Servo_PWM;                             // 舵机PID
    Servo_PWM = Servo_PWM11;
    /* 获取编码器值 */
    ECPULSE1 = ENC_GetCounter(ENC2_InPut_P33_7); // 动量轮反馈 母板编码器1
    ECPULSE2 = ENC_GetCounter(ENC4_InPut_P02_8); // 后轮反馈     母板编码器2
    LQ_DMP_Read();//pitch 左负右正
    Seek_Road();  // 获取赛道颜色偏差
    TempAngle = OFFSET2+OFFSET1+OFFSET1;    // 计算赛道颜色偏差值
    Zero_error = Pitch_Zero+TempAngle/800;  // 计算倾斜角度偏差值
    /////// 动量轮控制//////////
    PWM_X = X_balance_Control(Pitch,Pitch_Zero,gyro[0]);// 动量轮电机控制左右倾角
    PWM_accel = - Velocity_Control(-ECPULSE1);          // 动量轮电机速度环正反馈
    MotorDutyA = -(PWM_X-PWM_accel);
    if(MotorDutyA>8000) MotorDutyA=8000;        // 动量轮电机限幅
    else if(MotorDutyA<-8000) MotorDutyA=-8000; // 动量轮电机限幅
    else if(MotorDutyA<-0) MotorDutyA -=-3;    // 死区
    else if(MotorDutyA>0) MotorDutyA+=-3;      // 死区
    if((MotorDutyA<1000)&&(MotorDutyA>-1000))
            MotorDutyA=0;
    ///////// 舵机电机控制///////
    //Servo_PWM = Zero_error；

    //Servo_PWM = SBB_Get_BalancePID(Pitch, gyro[0]);               // PID计算单车平衡的PWM数值
    if( Servo_PWM < - Servo_Delta)    Servo_PWM = - Servo_Delta;  // 舵机角度限制
    else if(Servo_PWM > Servo_Delta)  Servo_PWM =   Servo_Delta;  // 舵机角度限制

    PWMServo = Servo_Center_Mid + Servo_PWM;                      // 转换为舵机控制PWM
    MotorDutyB = SBB_Get_MotorPI(ECPULSE2, Velocity)/5;           // 电机增量式PI控制


    if(Vbat<2500) Flag_Stop = 1;            // 电压低于约11V，停止输出，防止电池过放
    else Flag_Stop = 0;

    if((Pitch > 20) || (Pitch < -20))       // 摔倒停车判断
       Flag_Stop = 1;

    if(Flag_Stop == 1)                       // 停车
    {
        MotorDutyA=0;
        MotorDutyB = 0;                      // 电机关闭
        Integration = 0;                     // 积分参数归零
    }
    ServoCtrl(PWMServo);                    // 舵机控制
    MotorCtrl(MotorDutyA,motohoulun);       // 电机控制
}


/**************************************************************************
X轴平衡PID控制,角度环
**************************************************************************/
float X_balance_Control(float Angle,float Angle_Zero,float Gyro)
{
     float PWM,Bias;
     static float error;
     Bias=Angle-Pitch_Zero;                                            //获取偏差
     error+=Bias;                                                      //偏差累积
     if(error>+30) error=+30;                                          //积分限幅
     if(error<-30) error=-30;                                          //积分限幅
     PWM=X_Balance_KP*Bias + X_Balance_KI*error + Gyro*X_Balance_KD;   //获取最终数值
     return PWM;
}

/**************************************************************************
动量轮速度PI控制,速度正反馈环
**************************************************************************/
float Velocity_Control(int encoder)
{
    static float Encoder,Encoder_Integral;
    float Velocity,Encoder_Least;

    Encoder_Least = encoder;                                  //速度滤波
    Encoder *= 0.7;                                           //一阶低通滤波器
    Encoder += Encoder_Least*0.3;                             //一阶低通滤波器
    Encoder_Integral += Encoder;                              //积分出位移
    if(Encoder_Integral > +2000) Encoder_Integral = +2000;    //积分限幅
    if(Encoder_Integral < -2000) Encoder_Integral = -2000;    //积分限幅
    Velocity = Encoder * X_Velocity_KP + Encoder_Integral * X_Velocity_KI/100;
                                                              //获取最终数值
    if(Start_Flag==0) Encoder_Integral=0,Encoder=0,Velocity=0;//停止时参数清零
      return Velocity;
}


/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
【函数名】int SBB_Get_BalancePID(float Angle,float Gyro)
【功  能】舵机打角控制PID
【参数值】float Angle,电单车左右倾角
【参数值】float Gyro 电单车左右角速度
【返回值】小车平衡，舵机转向PID
【作  者】chiusir
【最后更新】2021年1月22日
【软件版本】V1.0
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/
int SBB_Get_BalancePID(float Angle,float Gyro)
{
    float  Bias;
    int SBB_BalancePID;
    Bias = Angle - Zero_error;     // 求出平衡的角度中值和此时横滚角的偏差
    Integration += Bias;           // 积分
    if(Integration<-380)      Integration=-380; //限幅
    else if(Integration>380)  Integration= 380; //限幅
    //===计算平衡控制的舵机PWM  PID控制 kp是P系数 ki式I系数 kd是D系数
    SBB_BalancePID = Balance_Kp * Bias + Balance_Ki*Integration + Balance_Kd*Gyro;
    return SBB_BalancePID;
}
/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
【函数名】int SBB_Get_MotorPI (int Encoder,int Target)
【功  能】电机控制增量式PI
【参数值】int Encoder 编码器脉采集的冲数
【参数值】int Target  期望脉冲数
【返回值】电机PWM
【作  者】chiusir
【最后更新】2021年1月22日
【软件版本】V1.0
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/
int SBB_Get_MotorPI (int Encoder,int Target)
{
    static int Pwm;
    Motor_Bias = Encoder - Target;            // 计算偏差
    Pwm += Motor_Kp * (Motor_Bias - Motor_Last_Bias) + Motor_Ki * Motor_Bias;
    // ==增量式PI控制器
    if(Pwm > 7000) Pwm = 7000;               // 限幅
    else if(Pwm < -7000)Pwm = -7000;         // 限幅
    Motor_Last_Bias = Motor_Bias;            // 保存上一次偏差
    return Pwm;                              // 增量输出
}


