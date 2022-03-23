/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
 ��ƽ    ̨�������������ܿƼ�TC264DA���İ�
 ����    д��chiusir
 ��E-mail��chiusir@163.com
 ������汾��V1.1 ��Ȩ���У���λʹ��������ϵ��Ȩ
 �������¡�2020��10��28��
 �������Ϣ�ο����е�ַ��
 ����    վ��http:// www.lqist.cn
 ���Ա����̡�http:// longqiu.taobao.com
 ------------------------------------------------
 ��dev.env.��AURIX Development Studio1.2.2�����ϰ汾
 ��Target �� TC264DA/TC264D
 ��Crystal�� 20.000Mhz
 ��SYS PLL�� 200MHz
 ________________________________________________________________
 ����iLLD_1_0_1_11_0�ײ����,

 ʹ�����̵�ʱ�򣬽������û�пո��Ӣ��·����
 ����CIFΪTC264DA�����⣬�����Ĵ������TC264D
 ����Ĭ�ϳ�ʼ����EMEM��512K������û�ʹ��TC264D��ע�͵�EMEM_InitConfig()��ʼ��������
 ������\Libraries\iLLD\TC26B\Tricore\Cpu\CStart\IfxCpu_CStart0.c��164�����ҡ�
 =================================================================
 ����������Ƶ��ַ��https:// space.bilibili.com/95313236
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
uint8  Start_Flag=1;                    //������־
//float X_Balance_KP=2000.001,X_Balance_KI=3.0001,X_Balance_KD=30.001;  // ƽ�⻷PID  Pitch��ǶȻ�PID���� ������
//float X_Balance_KP=4000.001,X_Balance_KI=4.0001,X_Balance_KD=60.001;  // ƽ�⻷PID  Pitch��ǶȻ�PID���� ������
//float X_Velocity_KP=90,X_Velocity_KI=90;//�����ֵ���ٶȻ�PI����
float X_Balance_KP= 1900.001,X_Balance_KI=-51.801,X_Balance_KD=15;
float X_Velocity_KP=32,X_Velocity_KI=1.00;

//float Pitch_Zero=6.9,Pitch_error=0.00;//����Pitch��Ƕ����
float Pitch_Zero=-0.7,Pitch_error=0.00;
float Zero_error = 0.00;              // Pitchƫ��ֵ
int PWM_X,PWM_accel;                  // PWM�м���
sint16 MotorDutyA = 0;                // ���ֵ������ռ�ձ���ֵ
sint16 MotorDutyB = 0;                // ���ֵ������ռ�ձ���ֵ

#define Balance_Kp  32                // ���PID����
#define Balance_Kd   0.03             // ���PID����
#define Balance_Ki   0.0020           // ���PID����

#define Motor_Kp     12               // ���ֵ��PID����
#define Motor_Ki     20               // ���ֵ��PID����

short  Velocity = 30;                 // �ٶȣ���ʱ������Ϊ60�����壬���������512������
short  PWMMotor, PWMServo;            // ������PMW������ֵ
short  Motor_Bias, Motor_Last_Bias, Motor_Integration; // ������ò���
float   Integration;
int  Servo_PWM;
unsigned char Flag_Stop = 0, Flag_Show, Flag_Imu;          // ͣ������ʾ��IMU��ɱ�־λ
extern int Vat;
extern int Vbat;
extern sint16 TempAngle;
extern sint16 OFFSET0;      //��Զ������������ֵ�ۺ�ƫ����
extern sint16 OFFSET1;      //�ڶ���
extern sint16 OFFSET2;      //�����������
extern sint16 TXV;          //���ε���߶ȣ��Ҹ߶�
int motohoulun = 600;
extern int  Servo_PWM11;
void Balance(void)
{
    int  Servo_PWM;                             // ���PID
    Servo_PWM = Servo_PWM11;
    /* ��ȡ������ֵ */
    ECPULSE1 = ENC_GetCounter(ENC2_InPut_P33_7); // �����ַ��� ĸ�������1
    ECPULSE2 = ENC_GetCounter(ENC4_InPut_P02_8); // ���ַ���     ĸ�������2
    LQ_DMP_Read();//pitch ������
    Seek_Road();  // ��ȡ������ɫƫ��
    TempAngle = OFFSET2+OFFSET1+OFFSET1;    // ����������ɫƫ��ֵ
    Zero_error = Pitch_Zero+TempAngle/800;  // ������б�Ƕ�ƫ��ֵ
    /////// �����ֿ���//////////
    PWM_X = X_balance_Control(Pitch,Pitch_Zero,gyro[0]);// �����ֵ�������������
    PWM_accel = - Velocity_Control(-ECPULSE1);          // �����ֵ���ٶȻ�������
    MotorDutyA = -(PWM_X-PWM_accel);
    if(MotorDutyA>8000) MotorDutyA=8000;        // �����ֵ���޷�
    else if(MotorDutyA<-8000) MotorDutyA=-8000; // �����ֵ���޷�
    else if(MotorDutyA<-0) MotorDutyA -=-3;    // ����
    else if(MotorDutyA>0) MotorDutyA+=-3;      // ����
    if((MotorDutyA<1000)&&(MotorDutyA>-1000))
            MotorDutyA=0;
    ///////// ����������///////
    //Servo_PWM = Zero_error��

    //Servo_PWM = SBB_Get_BalancePID(Pitch, gyro[0]);               // PID���㵥��ƽ���PWM��ֵ
    if( Servo_PWM < - Servo_Delta)    Servo_PWM = - Servo_Delta;  // ����Ƕ�����
    else if(Servo_PWM > Servo_Delta)  Servo_PWM =   Servo_Delta;  // ����Ƕ�����

    PWMServo = Servo_Center_Mid + Servo_PWM;                      // ת��Ϊ�������PWM
    MotorDutyB = SBB_Get_MotorPI(ECPULSE2, Velocity)/5;           // �������ʽPI����


    if(Vbat<2500) Flag_Stop = 1;            // ��ѹ����Լ11V��ֹͣ�������ֹ��ع���
    else Flag_Stop = 0;

    if((Pitch > 20) || (Pitch < -20))       // ˤ��ͣ���ж�
       Flag_Stop = 1;

    if(Flag_Stop == 1)                       // ͣ��
    {
        MotorDutyA=0;
        MotorDutyB = 0;                      // ����ر�
        Integration = 0;                     // ���ֲ�������
    }
    ServoCtrl(PWMServo);                    // �������
    MotorCtrl(MotorDutyA,motohoulun);       // �������
}


/**************************************************************************
X��ƽ��PID����,�ǶȻ�
**************************************************************************/
float X_balance_Control(float Angle,float Angle_Zero,float Gyro)
{
     float PWM,Bias;
     static float error;
     Bias=Angle-Pitch_Zero;                                            //��ȡƫ��
     error+=Bias;                                                      //ƫ���ۻ�
     if(error>+30) error=+30;                                          //�����޷�
     if(error<-30) error=-30;                                          //�����޷�
     PWM=X_Balance_KP*Bias + X_Balance_KI*error + Gyro*X_Balance_KD;   //��ȡ������ֵ
     return PWM;
}

/**************************************************************************
�������ٶ�PI����,�ٶ���������
**************************************************************************/
float Velocity_Control(int encoder)
{
    static float Encoder,Encoder_Integral;
    float Velocity,Encoder_Least;

    Encoder_Least = encoder;                                  //�ٶ��˲�
    Encoder *= 0.7;                                           //һ�׵�ͨ�˲���
    Encoder += Encoder_Least*0.3;                             //һ�׵�ͨ�˲���
    Encoder_Integral += Encoder;                              //���ֳ�λ��
    if(Encoder_Integral > +2000) Encoder_Integral = +2000;    //�����޷�
    if(Encoder_Integral < -2000) Encoder_Integral = -2000;    //�����޷�
    Velocity = Encoder * X_Velocity_KP + Encoder_Integral * X_Velocity_KI/100;
                                                              //��ȡ������ֵ
    if(Start_Flag==0) Encoder_Integral=0,Encoder=0,Velocity=0;//ֹͣʱ��������
      return Velocity;
}


/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
����������int SBB_Get_BalancePID(float Angle,float Gyro)
����  �ܡ������ǿ���PID
������ֵ��float Angle,�絥���������
������ֵ��float Gyro �絥�����ҽ��ٶ�
������ֵ��С��ƽ�⣬���ת��PID
����  �ߡ�chiusir
�������¡�2021��1��22��
������汾��V1.0
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/
int SBB_Get_BalancePID(float Angle,float Gyro)
{
    float  Bias;
    int SBB_BalancePID;
    Bias = Angle - Zero_error;     // ���ƽ��ĽǶ���ֵ�ʹ�ʱ����ǵ�ƫ��
    Integration += Bias;           // ����
    if(Integration<-380)      Integration=-380; //�޷�
    else if(Integration>380)  Integration= 380; //�޷�
    //===����ƽ����ƵĶ��PWM  PID���� kp��Pϵ�� kiʽIϵ�� kd��Dϵ��
    SBB_BalancePID = Balance_Kp * Bias + Balance_Ki*Integration + Balance_Kd*Gyro;
    return SBB_BalancePID;
}
/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
����������int SBB_Get_MotorPI (int Encoder,int Target)
����  �ܡ������������ʽPI
������ֵ��int Encoder ���������ɼ��ĳ���
������ֵ��int Target  ����������
������ֵ�����PWM
����  �ߡ�chiusir
�������¡�2021��1��22��
������汾��V1.0
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/
int SBB_Get_MotorPI (int Encoder,int Target)
{
    static int Pwm;
    Motor_Bias = Encoder - Target;            // ����ƫ��
    Pwm += Motor_Kp * (Motor_Bias - Motor_Last_Bias) + Motor_Ki * Motor_Bias;
    // ==����ʽPI������
    if(Pwm > 7000) Pwm = 7000;               // �޷�
    else if(Pwm < -7000)Pwm = -7000;         // �޷�
    Motor_Last_Bias = Motor_Bias;            // ������һ��ƫ��
    return Pwm;                              // �������
}


