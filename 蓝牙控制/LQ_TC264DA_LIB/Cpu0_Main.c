/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
��ƽ    ̨�������������ܿƼ�TC264DA���İ�
����    д��chiusir
��E-mail��chiusir@163.com
������汾��V1.1 ��Ȩ���У���λʹ��������ϵ��Ȩ
�������¡�2021��6��16��
�������Ϣ�ο����е�ַ��
����    վ��http://www.lqist.cn
���Ա����̡�http://longqiu.taobao.com
------------------------------------------------
��dev.env.��AURIX Development Studio1.4�����ϰ汾
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
����������Ƶ��ַ��https://space.bilibili.com/95313236
=================================================================
����ͷ�ӿ�                  �������ۻ���OV7725ģ��
�� ���ݶ˿ڣ�P02.0-P02.7�ڣ���8λ��������ͷ�����ݶ˿ڣ�
�� ʱ�����أ��ⲿ�жϵ�0�飺P00_4��
�� ���źţ��ⲿ�жϵ�3�飺P15_1��
-----------------------------------------------------------------
�Ƽ�GPT12ģ�飬������ʵ��5·�����������������������ݴ�������������źŲɼ�������ѡ����·���ɣ�
P33_7, P33_6   ����TCĸ�������1
P02_8, P33_5   ����TCĸ�������2
P10_3, P10_1   ����TCĸ�������3
P20_3, P20_0   ����TCĸ�������4
-----------------------------------------------------------------
��е�ѹ�ɼ�ģ�������˷�ģ��
�Ƽ�ʹ��AN0-7������·ADC����������chirp�����źż���ų���е�ѹ�ɼ���
AN0-3          ����TC���ĸ���˷�ģ����ߵ��
-----------------------------------------------------------------
Ĭ�ϵ���ӿ�
ʹ��GTMģ�飬ATOM�ĸ�ͨ���ɲ���4*8��32·PWM�����Ҹ���Ƶ�ʺ�ռ�ձȿɵ����Ƽ�ʹ��ATOM0��0-7ͨ����
��һ��˫·ȫ������
P23_1         ����TCĸ��MOTOR1_P
P32_4         ����TCĸ��MOTOR1_N
P21_2         ����TCĸ��MOTOR2_P
P22_3         ����TCĸ��MOTOR2_N
�ڶ���˫·ȫ������
P21_4         ����TCĸ��MOTOR3_P
P21_3         ����TCĸ��MOTOR3_N
P20_8         ����TCĸ��MOTOR4_P
P21_5         ����TCĸ��MOTOR4_N
-----------------------------------------------------------------
Ĭ�϶���ӿ�
ʹ��GTMģ�飬ATOM�ĸ�ͨ���ɲ���4*8��32·PWM�����Ҹ���Ƶ�ʺ�ռ�ձȿɵ����Ƽ�ʹ��ATOM2��
P33_10        ����TCĸ����1
P33_13        ����TCĸ����2
-----------------------------------------------------------------
 Ĭ����Ļ��ʾ�ӿڣ��û�����ʹ��TFT����OLEDģ��
TFTSPI_CS     P20_14     ����TCĸ�� CS�ܽ� Ĭ�����ͣ����Բ���
TFTSPI_SCK    P20_11     ����TCĸ�� SPI SCK�ܽ�
TFTSPI_SDI    P20_10     ����TCĸ�� SPI MOSI�ܽ�
TFTSPI_DC     P20_12     ����TCĸ�� D/C�ܽ�
TFTSPI_RST    P20_13     ����TCĸ�� RESET�ܽ�
-----------------------------------------------------------------
OLED_CK       P20_14     ����TCĸ��OLED CK�ܽ�
OLED_DI       P20_11     ����TCĸ��OLED DI�ܽ�
OLED_RST      P20_10     ����TCĸ��OLED RST�ܽ�
OLED_DC       P20_12     ����TCĸ��OLED DC�ܽ�
OLED_CS       P20_13     ����TCĸ��OLED CS�ܽ� Ĭ�����ͣ����Բ���
----------------------------------------------------------------
Ĭ�ϰ����ӿ�
KEY0p         P22_0      ����TCĸ���ϰ���0
KEY1p         P22_1      ����TCĸ���ϰ���1
KEY2p         P22_2      ����TCĸ���ϰ���2
DSW0p         P33_9      ����TCĸ���ϲ��뿪��0
DSW1p         P33_11     ����TCĸ���ϲ��뿪��1
-----------------------------------------------------------------
Ĭ��LED�ӿ�
LED0p         P10_6      ����TCĸ����İ���LED0 ����
LED1p         P10_5      ����TCĸ����İ���LED1 ����
LED2p         P20_6      ����TCĸ����LED0
LED3p         P20_7      ����TCĸ����LED1
-----------------------------------------------------------------
Ĭ�Ϸ������ӿ�
BEEPp         P33_8      ����TCĸ���Ϸ������ӿ�
-----------------------------------------------------------------
��ʱ��
������CCU6ģ��  ÿ��ģ��������������ʱ��  ������ʱ���ж�
�Ƽ�ʹ��CCU6ģ�飬STM����ϵͳʱ�ӻ�����ʱ��
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
IfxCpu_mutexLock mutexCpu0InitIsOk = 1;   // CPU0 ��ʼ����ɱ�־λ
volatile char mutexCpu0TFTIsOk=0;         // CPU1 0ռ��/1�ͷ� TFT
extern sint16 MotorDutyA;      //�������ռ�ձ���ֵ
extern sint16 MotorDutyB;      //�������ռ�ձ���ֵ
extern float Zero_error;
extern float Pitch_Zero,Pitch_error;//����Pitch��Ƕ����
extern short  Velocity;                 // �ٶȣ���ʱ������Ϊ60�����壬���������512������
extern sint16 TempAngle;        // ���ݵ��ƫ�������������ʱ���ֵ
int Vat=0;
int Vbat=0;
extern float X_Balance_KP,X_Balance_KI,X_Balance_KD;
extern float X_Velocity_KP,X_Velocity_KI;
int chang_pid = 5;
int  Servo_PWM11;
char get_usart;
extern int motohoulun;  //�Զ������
extern short PWMServo;
/*************************************************************************
*  �������ƣ�int core0_main (void)
*  ����˵����CPU0������
*  ����˵������
*  �������أ���
*  �޸�ʱ�䣺2020��3��10��
*  ��    ע��
*************************************************************************/
int core0_main (void)
{

    unsigned char res;
    char txt[30];
    unsigned char  cnt=0;
	// �ر�CPU���ж�
	IfxCpu_disableInterrupts();
	// �رտ��Ź�����������ÿ��Ź�ι����Ҫ�ر�
	IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
	IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());
	// ��ȡ����Ƶ��
	g_AppCpu0.info.pllFreq = IfxScuCcu_getPllFrequency();
	g_AppCpu0.info.cpuFreq = IfxScuCcu_getCpuFrequency(IfxCpu_getCoreIndex());
	g_AppCpu0.info.sysFreq = IfxScuCcu_getSpbFrequency();
	g_AppCpu0.info.stmFreq = IfxStm_getFrequency(&MODULE_STM0);
	TFTSPI_Init(1);               // TFT1.8��ʼ��0:����  1������
	TFTSPI_CLS(u16BLACK);         // ����
	TFTSPI_Show_Logo(0,37);       // ��ʾ����LOGO
	TFTSPI_P16x16Str(0,0,(unsigned char*)"�����������ܿƼ�",u16RED,u16BLUE);// �ַ�����ʾ
	// ������ʼ��
	GPIO_KEY_Init();
	// LED������P10.6��P10.5��ʼ��
	GPIO_LED_Init();
	TFTSPI_CLS(u16BLACK);         // ����
	 ADC_InitConfig(ADC7, 80000); // ��Դ��ѹ����ʼ��
    // 6050�����ǳ�ʼ��
    IIC_Init();                  //IIC��ʼ��//IIC��ʼ��
    delayms(100);
    res = Gyro_Chose();                //�ж��������ͺ�
    MPU6050_Init();
    LQ_DMP_Init();
    MotorInit();
    EncInit();
    ServoInit();
   // CAMERA_Init(50);
	// ����P14.0�ܽ����,P14.1���룬������115200
	UART_InitConfig(UART0_RX_P14_1,UART0_TX_P14_0, 9600);
	// ����CPU���ж�
	IfxCpu_enableInterrupts();
	// ֪ͨCPU1��CPU0��ʼ�����
	IfxCpu_releaseMutex(&mutexCpu0InitIsOk);
	// �м�CPU0,CPU1...������ͬʱ������Ļ��ʾ�������ͻ����ʾ
	mutexCpu0TFTIsOk=0;         // CPU1�� 0ռ��/1�ͷ� TFT
	TFTSPI_P8X16Str(1, 0, "LQ_DDC6050TEST",u16GREEN,u16BLACK);      //�ַ�����ʾ
	CCU6_InitConfig(CCU61, CCU6_Channel0, 5000);// 50ms
	//TestServo();
	 //________________________________________________________________________________
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // ���к����жϵĲ��Զ�Ĭ����CPU0��ִ�У������Ҫ��CPU1��ο�����Bվ��Ƶ��
    // ����������Ƶ��ַ��https://space.bilibili.com/95313236
    while (1)	//��ѭ��
    {


//        if(Camera_Flag == 2)
//          {
//              // ��ȡ����ʹ�õ�����
//              Get_Use_Image();
//              //�������ͷ�ɼ���ɱ�־λ  �����������򲻻��ٴβɼ�����
//              Camera_Flag = 0;
//              Get_Bin_Image(1);
//          }
        Vbat = ADC_Read(ADC7);  // ����Դ��ѹ
        Vat = Vbat * 11 / 25;   // ��ѹת��
        //LQ_DMP_Read();//pitch ������
//        sprintf((char*)txt,"P:%.02f PP:%.02f",Pitch,Zero_error);
//        TFTSPI_P8X16Str(0,1,txt,u16RED,u16BLACK);// �ַ�����ʾ
//        sprintf((char*)txt,"V:%05d, ER:%03d",Velocity,TempAngle);
//        TFTSPI_P8X16Str(0,4,txt,u16RED,u16BLACK);// �ַ�����ʾ
//
//        sprintf((char*)txt,"E1:%04d E2:%04d",ECPULSE1,ECPULSE2);
//        TFTSPI_P8X16Str(0,2,txt,u16RED,u16BLACK);// �ַ�����ʾ
//        sprintf((char*)txt,"M1:%05d M2:%05d",MotorDutyA,MotorDutyB);
//        TFTSPI_P8X16Str(0,3,txt,u16RED,u16BLACK);// �ַ�����ʾ
//        sprintf(txt, "Bat:%d.%02dV V:%04d", Vat / 100, Vat % 100,Vbat);  // ��ʾ��ص�ѹ
//        TFTSPI_P8X16Str(0,5,txt,u16RED,u16BLACK);// �ַ�����ʾ















        sprintf((char*)txt,"P7:%.02f Po:%.02f",Pitch,Pitch_Zero);
                TFTSPI_P8X16Str(0,1,txt,u16RED,u16BLACK);// ��?��???????
                sprintf((char*)txt,"E1:%04d",ECPULSE1);
                TFTSPI_P8X16Str(0,2,txt,u16RED,u16BLACK);// ��?��???????
                sprintf((char*)txt,"M:%05d",MotorDutyA);
                TFTSPI_P8X16Str(0,3,txt,u16RED,u16BLACK);// ��?��???????
                sprintf(txt, "Bat:%d.%02dV V:%04d", Vat / 100, Vat % 100,Vbat);  // ????????????
                TFTSPI_P8X16Str(0,4,txt,u16RED,u16BLACK);// ��?��???????

        //Pitch_Zero
        //
                sprintf(txt, "Pitch_Zero:%.1f", Pitch_Zero);  // ??????????kp
                TFTSPI_P8X16Str(0,5,txt,u16RED,u16BLACK);// ��?��???????
                sprintf(txt, "Servo_PWM:%c", get_usart);  // ??????????ki
                TFTSPI_P8X16Str(0,6,txt,u16RED,u16BLACK);// ��?��???????
                sprintf(txt, "Pkd:%.1f", X_Balance_KD);  // ??????????kd
                TFTSPI_P8X16Str(0,7,txt,u16RED,u16BLACK);// ��?��???????

                sprintf(txt, "Pkd:%.1f", X_Velocity_KP);  // ?????????��kd
                TFTSPI_P8X16Str(0,8,txt,u16RED,u16BLACK);// ��?��???????
                sprintf(txt, "Pkd:%.1f", X_Velocity_KI);  // ????kd
                TFTSPI_P8X16Str(0,9,txt,u16RED,u16BLACK);// ��?��???????


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
