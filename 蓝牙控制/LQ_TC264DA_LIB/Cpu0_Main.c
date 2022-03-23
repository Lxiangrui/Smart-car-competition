/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
【平    台】北京龙邱智能科技TC264DA核心板
【编    写】chiusir
【E-mail】chiusir@163.com
【软件版本】V1.1 版权所有，单位使用请先联系授权
【最后更新】2021年6月16日
【相关信息参考下列地址】
【网    站】http://www.lqist.cn
【淘宝店铺】http://longqiu.taobao.com
------------------------------------------------
【dev.env.】AURIX Development Studio1.4及以上版本
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
程序配套视频地址：https://space.bilibili.com/95313236
=================================================================
摄像头接口                  龙邱神眼或者OV7725模块
● 数据端口：P02.0-P02.7口，共8位，接摄像头的数据端口；
● 时钟像素：外部中断第0组：P00_4；
● 场信号：外部中断第3组：P15_1；
-----------------------------------------------------------------
推荐GPT12模块，共可以实现5路正交解码增量编码器（兼容带方向编码器）信号采集，任意选择四路即可；
P33_7, P33_6   龙邱TC母板编码器1
P02_8, P33_5   龙邱TC母板编码器2
P10_3, P10_1   龙邱TC母板编码器3
P20_3, P20_0   龙邱TC母板编码器4
-----------------------------------------------------------------
电感电压采集模块或者麦克风模块
推荐使用AN0-7，共八路ADC，可以满足chirp声音信号及电磁车电感电压采集；
AN0-3          龙邱TC接四个麦克风模块或者电感
-----------------------------------------------------------------
默认电机接口
使用GTM模块，ATOM四个通道可产生4*8共32路PWM，而且各自频率和占空比可调，推荐使用ATOM0的0-7通道；
第一组双路全桥驱动
P23_1         龙邱TC母板MOTOR1_P
P32_4         龙邱TC母板MOTOR1_N
P21_2         龙邱TC母板MOTOR2_P
P22_3         龙邱TC母板MOTOR2_N
第二组双路全桥驱动
P21_4         龙邱TC母板MOTOR3_P
P21_3         龙邱TC母板MOTOR3_N
P20_8         龙邱TC母板MOTOR4_P
P21_5         龙邱TC母板MOTOR4_N
-----------------------------------------------------------------
默认舵机接口
使用GTM模块，ATOM四个通道可产生4*8共32路PWM，而且各自频率和占空比可调，推荐使用ATOM2；
P33_10        龙邱TC母板舵机1
P33_13        龙邱TC母板舵机2
-----------------------------------------------------------------
 默认屏幕显示接口，用户可以使用TFT或者OLED模块
TFTSPI_CS     P20_14     龙邱TC母板 CS管脚 默认拉低，可以不用
TFTSPI_SCK    P20_11     龙邱TC母板 SPI SCK管脚
TFTSPI_SDI    P20_10     龙邱TC母板 SPI MOSI管脚
TFTSPI_DC     P20_12     龙邱TC母板 D/C管脚
TFTSPI_RST    P20_13     龙邱TC母板 RESET管脚
-----------------------------------------------------------------
OLED_CK       P20_14     龙邱TC母板OLED CK管脚
OLED_DI       P20_11     龙邱TC母板OLED DI管脚
OLED_RST      P20_10     龙邱TC母板OLED RST管脚
OLED_DC       P20_12     龙邱TC母板OLED DC管脚
OLED_CS       P20_13     龙邱TC母板OLED CS管脚 默认拉低，可以不用
----------------------------------------------------------------
默认按键接口
KEY0p         P22_0      龙邱TC母板上按键0
KEY1p         P22_1      龙邱TC母板上按键1
KEY2p         P22_2      龙邱TC母板上按键2
DSW0p         P33_9      龙邱TC母板上拨码开关0
DSW1p         P33_11     龙邱TC母板上拨码开关1
-----------------------------------------------------------------
默认LED接口
LED0p         P10_6      龙邱TC母板核心板上LED0 翠绿
LED1p         P10_5      龙邱TC母板核心板上LED1 蓝灯
LED2p         P20_6      龙邱TC母板上LED0
LED3p         P20_7      龙邱TC母板上LED1
-----------------------------------------------------------------
默认蜂鸣器接口
BEEPp         P33_8      龙邱TC母板上蜂鸣器接口
-----------------------------------------------------------------
定时器
有两个CCU6模块  每个模块有两个独立定时器  触发定时器中断
推荐使用CCU6模块，STM用作系统时钟或者延时；
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/

#include <IfxCpu.h>
#include <IfxScuCcu.h>
#include <IfxScuWdt.h>
#include <IfxStm.h>
#include <IfxStm_reg.h>
#include <stdio.h>
#include "LQ_IIC_Gyro.h"
#include "src/APP/LQ_ADC_test.h"
#include "src/APP/LQ_Atom_Motor.h"
#include "src/APP/LQ_CAMERA.h"
#include "src/APP/LQ_EEPROM_TEST.h"
#include "src/APP/LQ_FFT_TEST.h"
#include "src/APP/LQ_GPIO_ExInt.h"
#include "src/APP/LQ_GPIO_KEY.h"
#include "src/APP/LQ_GPIO_LED.h"
#include "src/APP/LQ_GPT_mini512.h"
#include "src/APP/LQ_I2C_9AX.h"
#include "LQ_MPU6050_DMP.h"
#include "src/APP/LQ_I2C_VL53.h"
#include "src/APP/LQ_ICM20602.h"
#include "src/APP/LQ_OLED096.h"
#include "src/APP/LQ_STM_Timer.h"
#include "src/APP/LQ_TFT18.h"
#include "src/APP/LQ_Tim_InputCature.h"
#include "src/APP/LQ_Tom_Servo.h"
#include "src/APP/LQ_UART_Bluetooth.h"
#include "src/Driver/include.h"
#include "src/Driver/LQ_STM.h"
#include "src/Driver/LQ_UART.h"
#include "src/User/LQ_MotorServo.h"
#include "src/User/LQ_Balance.h"
#include "LQ_CCU6.h"
#include "../Driver/LQ_ADC.h"
#include "LQ_CAMERA.h"
App_Cpu0 g_AppCpu0;                       // brief CPU 0 global data
IfxCpu_mutexLock mutexCpu0InitIsOk = 1;   // CPU0 初始化完成标志位
volatile char mutexCpu0TFTIsOk=0;         // CPU1 0占用/1释放 TFT
extern sint16 MotorDutyA;      //电机驱动占空比数值
extern sint16 MotorDutyB;      //电机驱动占空比数值
extern float Zero_error;
extern float Pitch_Zero,Pitch_error;//设置Pitch轴角度零点
extern short  Velocity;                 // 速度，定时周期内为60个脉冲，龙邱带方向512编码器
extern sint16 TempAngle;        // 根据电感偏移量计算出的临时打角值
int Vat=0;
int Vbat=0;
extern float X_Balance_KP,X_Balance_KI,X_Balance_KD;
extern float X_Velocity_KP,X_Velocity_KI;
int chang_pid = 5;
int  Servo_PWM11;
char get_usart;
extern int motohoulun;  //自定义后轮
extern short PWMServo;
/*************************************************************************
*  函数名称：int core0_main (void)
*  功能说明：CPU0主函数
*  参数说明：无
*  函数返回：无
*  修改时间：2020年3月10日
*  备    注：
*************************************************************************/
int core0_main (void)
{

    unsigned char res;
    char txt[30];
    unsigned char  cnt=0;
	// 关闭CPU总中断
	IfxCpu_disableInterrupts();
	// 关闭看门狗，如果不设置看门狗喂狗需要关闭
	IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
	IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());
	// 读取总线频率
	g_AppCpu0.info.pllFreq = IfxScuCcu_getPllFrequency();
	g_AppCpu0.info.cpuFreq = IfxScuCcu_getCpuFrequency(IfxCpu_getCoreIndex());
	g_AppCpu0.info.sysFreq = IfxScuCcu_getSpbFrequency();
	g_AppCpu0.info.stmFreq = IfxStm_getFrequency(&MODULE_STM0);
	TFTSPI_Init(1);               // TFT1.8初始化0:横屏  1：竖屏
	TFTSPI_CLS(u16BLACK);         // 清屏
	TFTSPI_Show_Logo(0,37);       // 显示龙邱LOGO
	TFTSPI_P16x16Str(0,0,(unsigned char*)"北京龙邱智能科技",u16RED,u16BLUE);// 字符串显示
	// 按键初始化
	GPIO_KEY_Init();
	// LED灯所用P10.6和P10.5初始化
	GPIO_LED_Init();
	TFTSPI_CLS(u16BLACK);         // 清屏
	 ADC_InitConfig(ADC7, 80000); // 电源电压检测初始化
    // 6050陀螺仪初始化
    IIC_Init();                  //IIC初始化//IIC初始化
    delayms(100);
    res = Gyro_Chose();                //判断陀螺仪型号
    MPU6050_Init();
    LQ_DMP_Init();
    MotorInit();
    EncInit();
    ServoInit();
   // CAMERA_Init(50);
	// 串口P14.0管脚输出,P14.1输入，波特率115200
	UART_InitConfig(UART0_RX_P14_1,UART0_TX_P14_0, 9600);
	// 开启CPU总中断
	IfxCpu_enableInterrupts();
	// 通知CPU1，CPU0初始化完成
	IfxCpu_releaseMutex(&mutexCpu0InitIsOk);
	// 切记CPU0,CPU1...不可以同时开启屏幕显示，否则冲突不显示
	mutexCpu0TFTIsOk=0;         // CPU1： 0占用/1释放 TFT
	TFTSPI_P8X16Str(1, 0, "LQ_DDC6050TEST",u16GREEN,u16BLACK);      //字符串显示
	CCU6_InitConfig(CCU61, CCU6_Channel0, 5000);// 50ms
	//TestServo();
	 //________________________________________________________________________________
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // 所有含有中断的测试都默认在CPU0中执行，如果需要用CPU1请参考龙邱B站视频。
    // 程序配套视频地址：https://space.bilibili.com/95313236
    while (1)	//主循环
    {


//        if(Camera_Flag == 2)
//          {
//              // 提取部分使用的数据
//              Get_Use_Image();
//              //清除摄像头采集完成标志位  如果不清除，则不会再次采集数据
//              Camera_Flag = 0;
//              Get_Bin_Image(1);
//          }
        Vbat = ADC_Read(ADC7);  // 检测电源电压
        Vat = Vbat * 11 / 25;   // 电压转换
        //LQ_DMP_Read();//pitch 左负右正
//        sprintf((char*)txt,"P:%.02f PP:%.02f",Pitch,Zero_error);
//        TFTSPI_P8X16Str(0,1,txt,u16RED,u16BLACK);// 字符串显示
//        sprintf((char*)txt,"V:%05d, ER:%03d",Velocity,TempAngle);
//        TFTSPI_P8X16Str(0,4,txt,u16RED,u16BLACK);// 字符串显示
//
//        sprintf((char*)txt,"E1:%04d E2:%04d",ECPULSE1,ECPULSE2);
//        TFTSPI_P8X16Str(0,2,txt,u16RED,u16BLACK);// 字符串显示
//        sprintf((char*)txt,"M1:%05d M2:%05d",MotorDutyA,MotorDutyB);
//        TFTSPI_P8X16Str(0,3,txt,u16RED,u16BLACK);// 字符串显示
//        sprintf(txt, "Bat:%d.%02dV V:%04d", Vat / 100, Vat % 100,Vbat);  // 显示电池电压
//        TFTSPI_P8X16Str(0,5,txt,u16RED,u16BLACK);// 字符串显示















        sprintf((char*)txt,"P7:%.02f Po:%.02f",Pitch,Pitch_Zero);
                TFTSPI_P8X16Str(0,1,txt,u16RED,u16BLACK);// ×?·???????
                sprintf((char*)txt,"E1:%04d",ECPULSE1);
                TFTSPI_P8X16Str(0,2,txt,u16RED,u16BLACK);// ×?·???????
                sprintf((char*)txt,"M:%05d",MotorDutyA);
                TFTSPI_P8X16Str(0,3,txt,u16RED,u16BLACK);// ×?·???????
                sprintf(txt, "Bat:%d.%02dV V:%04d", Vat / 100, Vat % 100,Vbat);  // ????????????
                TFTSPI_P8X16Str(0,4,txt,u16RED,u16BLACK);// ×?·???????

        //Pitch_Zero
        //
                sprintf(txt, "Pitch_Zero:%.1f", Pitch_Zero);  // ??????????kp
                TFTSPI_P8X16Str(0,5,txt,u16RED,u16BLACK);// ×?·???????
                sprintf(txt, "Servo_PWM:%c", get_usart);  // ??????????ki
                TFTSPI_P8X16Str(0,6,txt,u16RED,u16BLACK);// ×?·???????
                sprintf(txt, "Pkd:%.1f", X_Balance_KD);  // ??????????kd
                TFTSPI_P8X16Str(0,7,txt,u16RED,u16BLACK);// ×?·???????

                sprintf(txt, "Pkd:%.1f", X_Velocity_KP);  // ?????????·kd
                TFTSPI_P8X16Str(0,8,txt,u16RED,u16BLACK);// ×?·???????
                sprintf(txt, "Pkd:%.1f", X_Velocity_KI);  // ????kd
                TFTSPI_P8X16Str(0,9,txt,u16RED,u16BLACK);// ×?·???????


                if(get_usart == '1')        Servo_PWM11+=60;
                else if(get_usart == '2')   Servo_PWM11-=60;

                if(Servo_PWM11<-260)    Servo_PWM11 = -260;
                else if(Servo_PWM11>260)    Servo_PWM11 = 260;

                if(get_usart == 'g')        motohoulun+=200;
                else if(get_usart == 'j')   motohoulun-=200;

                get_usart = 0;




                if(KEY_Read(KEY0) == 0)
                {   UART_PutChar(UART0, 'a');
                    chang_pid++;
                    if(chang_pid>9) chang_pid = 5;
//                    get_usart = UART_GetChar(UART0);
                }
                if(chang_pid == 5){
                    TFTSPI_Draw_Rectangle(0, 82, 30, 95, u16YELLOW);
                    if(KEY_Read(KEY1) == 0)         Pitch_Zero+=0.1;
                    else if(KEY_Read(KEY2) == 0)    Pitch_Zero-=0.1;
                }

                else if(chang_pid == 6){
                    TFTSPI_Draw_Rectangle(0, 82+15, 30, 95+15, u16YELLOW);
                    if(KEY_Read(KEY1) == 0)         Servo_PWM11+=10;
                    else if(KEY_Read(KEY2) == 0)    Servo_PWM11-=10;

                }
                else if(chang_pid == 7){
                    TFTSPI_Draw_Rectangle(0, 82+15*2, 30, 95+15*2, u16YELLOW);
                    if(KEY_Read(KEY1) == 0)         X_Balance_KD++;
                    else if(KEY_Read(KEY2) == 0)    X_Balance_KD--;
                }
                else if(chang_pid == 8){
                    TFTSPI_Draw_Rectangle(0, 82+15*3+3, 30, 95+15*3+3, u16YELLOW);
                    if(KEY_Read(KEY1) == 0)         X_Velocity_KP++;
                    else if(KEY_Read(KEY2) == 0)    X_Velocity_KP--;
                }
                else if(chang_pid == 9){
                    TFTSPI_Draw_Rectangle(0, 82+15*4+3, 30, 95+15*4+3, u16YELLOW);
                    if(KEY_Read(KEY1) == 0)         X_Velocity_KI++;
                    else if(KEY_Read(KEY2) == 0)    X_Velocity_KI--;
                }

    }
}
