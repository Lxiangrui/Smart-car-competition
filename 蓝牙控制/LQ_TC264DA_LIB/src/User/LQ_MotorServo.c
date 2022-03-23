/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
 ��ƽ    ̨�������������ܿƼ�TC264DA���İ�
 ����    д��chiusir
 ��E-mail  ��chiusir@163.com
 ������汾��V1.1 ��Ȩ���У���λʹ��������ϵ��Ȩ
 �������¡�2020��10��28��
 �������Ϣ�ο����е�ַ��
 ����    վ��http://www.lqist.cn
 ���Ա����̡�http://longqiu.taobao.com
 ------------------------------------------------
 ��dev.env.��AURIX Development Studio1.2.2�����ϰ汾
 ��Target �� TC264DA/TC264D
 ��Crystal�� 20.000Mhz
 ��SYS PLL�� 200MHz
 ________________________________________________________________
 ����iLLD_1_0_1_11_0�ײ����,
 ʹ�����̵�ʱ�򣬽������û�����ļ��ո��Ӣ��·����
 ����CIFΪTC264DA�����⣬�����Ĵ������TC264D
 QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/

#include "LQ_MotorServo.h"

#include <IfxCpu.h>
#include <IfxGtm_PinMap.h>
#include <Platform_Types.h>
#include <stdio.h>

#include "../APP/LQ_GPIO_KEY.h"
#include "../APP/LQ_GPIO_LED.h"
#include "../APP/LQ_TFT18.h"
#include "../Driver/LQ_CCU6.h"
#include "../Driver/LQ_GPT12_ENC.h"
#include "../Driver/LQ_GTM.h"
#include "../Driver/LQ_STM.h"
#include "../Driver/LQ_UART.h"
#include "LQ_Inductor.h"

volatile uint8 Game_Over = 0; // С�����ȫ������ͣ��
sint16 ServoDuty = Servo_Center_Mid;
sint16 MotorDuty1 = 500;      // �������ռ�ձ���ֵ
sint16 MotorDuty2 = 500;      // �������ռ�ձ���ֵ
sint32 NowTime = 0;
uint16 BatVolt = 0;           // ��ص�ѹ�ɼ�

//���Ƶ��
#define MOTOR_FREQUENCY    12500

//���PWM �궨��
#define MOTOR1_P          IfxGtm_ATOM0_6_TOUT42_P23_1_OUT
#define MOTOR1_N          IfxGtm_ATOM0_5_TOUT40_P32_4_OUT

#define MOTOR2_P          IfxGtm_ATOM0_0_TOUT53_P21_2_OUT
#define MOTOR2_N          IfxGtm_ATOM0_4_TOUT50_P22_3_OUT


#define MOTOR3_P          IfxGtm_ATOM0_7_TOUT64_P20_8_OUT
#define MOTOR3_N          IfxGtm_ATOM0_3_TOUT56_P21_5_OUT


#define MOTOR4_P          IfxGtm_ATOM0_2_TOUT55_P21_4_OUT
#define MOTOR4_N          IfxGtm_ATOM0_1_TOUT54_P21_3_OUT


#define ATOMSERVO1       IfxGtm_ATOM2_0_TOUT32_P33_10_OUT
#define ATOMSERVO2       IfxGtm_ATOM2_5_TOUT35_P33_13_OUT

//#define USE7843or7971   //USEDRV8701 ʹ������ͬ������ģ�飬ѡ���Ӧ�ĺ궨��
#define USEDRV8701

/*************************************************************************
 *  �������ƣ�void MotorInit(void)
 *  ����˵�������PWM��ʼ��
 *  ����˵������
 *  �������أ���
 *  �޸�ʱ�䣺2020��4��1��
 *  ��    ע������2�����
 *************************************************************************/
void MotorInit (void)
{
    ATOM_PWM_InitConfig(MOTOR1_P, 0, MOTOR_FREQUENCY);
    ATOM_PWM_InitConfig(MOTOR1_N, 0, MOTOR_FREQUENCY);
    ATOM_PWM_InitConfig(MOTOR2_P, 0, MOTOR_FREQUENCY);
    ATOM_PWM_InitConfig(MOTOR2_N, 0, MOTOR_FREQUENCY);
    ATOM_PWM_InitConfig(MOTOR3_P, 0, MOTOR_FREQUENCY);
    ATOM_PWM_InitConfig(MOTOR3_N, 0, MOTOR_FREQUENCY);
    ATOM_PWM_InitConfig(MOTOR4_P, 0, MOTOR_FREQUENCY);
    ATOM_PWM_InitConfig(MOTOR4_N, 0, MOTOR_FREQUENCY);
}

/*************************************************************************
 *  �������ƣ�void EncInit (void)
 *  ����˵������������ʼ������
 *  ����˵������
 *  �������أ���
 *  �޸�ʱ�䣺2020��4��1��
 *  ��    ע������2��������
 *************************************************************************/
void EncInit (void)
{
    ENC_InitConfig(ENC2_InPut_P33_7, ENC2_Dir_P33_6);
    ENC_InitConfig(ENC4_InPut_P02_8, ENC4_Dir_P33_5);
}

/*************************************************************************
 *  �������ƣ�void MotorCtrl(float motor1, float motor2)
 *  ����˵�������ת�Ǻ���������С�����˷�Χ���ƣ���С
 *  ����˵����   @param    motor1   �� ���1ռ�ձ�
 @param    motor2   �� ���2ռ�ձ�
 *  �������أ���
 *  �޸�ʱ�䣺2020��4��1��
 *  ��    ע������2���������ͨ����ֻ��Ҫһ���������
 *************************************************************************/
#ifdef USE7843or7971
void MotorCtrl (sint32 motor1, sint32 motor2)
{
    if (motor1 > 0)
    {
        ATOM_PWM_SetDuty(MOTOR1_P, motor1, MOTOR_FREQUENCY);
        ATOM_PWM_SetDuty(MOTOR1_N, 0, MOTOR_FREQUENCY);
    }
    else
    {
        ATOM_PWM_SetDuty(MOTOR1_P, 0, MOTOR_FREQUENCY);
        ATOM_PWM_SetDuty(MOTOR1_N, (-motor1), MOTOR_FREQUENCY);
    }

    if (motor2 > 0)
    {
        ATOM_PWM_SetDuty(MOTOR2_P, motor2, MOTOR_FREQUENCY);
        ATOM_PWM_SetDuty(MOTOR2_N, 0, MOTOR_FREQUENCY);
    }
    else
    {
        ATOM_PWM_SetDuty(MOTOR2_P, 0, MOTOR_FREQUENCY);
        ATOM_PWM_SetDuty(MOTOR2_N, (-motor2), MOTOR_FREQUENCY);
    }
}
void MotorCtrl4w(sint32 motor1, sint32 motor2,sint32 motor3, sint32 motor4)
{
    if (motor1 > 0)
       {
           ATOM_PWM_SetDuty(MOTOR1_P, motor1, MOTOR_FREQUENCY);
           ATOM_PWM_SetDuty(MOTOR1_N, 0, MOTOR_FREQUENCY);
       }
       else
       {
           ATOM_PWM_SetDuty(MOTOR1_P, 0, MOTOR_FREQUENCY);
           ATOM_PWM_SetDuty(MOTOR1_N, (-motor1), MOTOR_FREQUENCY);
       }

    if (motor2 > 0)
       {
           ATOM_PWM_SetDuty(MOTOR2_P, motor2, MOTOR_FREQUENCY);
           ATOM_PWM_SetDuty(MOTOR2_N, 0, MOTOR_FREQUENCY);
       }
       else
       {
           ATOM_PWM_SetDuty(MOTOR2_P, 0, MOTOR_FREQUENCY);
           ATOM_PWM_SetDuty(MOTOR2_N, (-motor2), MOTOR_FREQUENCY);
       }
    if (motor3 > 0)
       {
           ATOM_PWM_SetDuty(MOTOR3_P, motor3, MOTOR_FREQUENCY);
           ATOM_PWM_SetDuty(MOTOR3_N, 0, MOTOR_FREQUENCY);
       }
       else
       {
           ATOM_PWM_SetDuty(MOTOR3_P, 0, MOTOR_FREQUENCY);
           ATOM_PWM_SetDuty(MOTOR3_N, (-motor3), MOTOR_FREQUENCY);
       }

       if (motor4 > 0)
       {
           ATOM_PWM_SetDuty(MOTOR4_P, motor4, MOTOR_FREQUENCY);
           ATOM_PWM_SetDuty(MOTOR4_N, 0, MOTOR_FREQUENCY);
       }
       else
       {
           ATOM_PWM_SetDuty(MOTOR4_P, 0, MOTOR_FREQUENCY);
           ATOM_PWM_SetDuty(MOTOR4_N, (-motor4), MOTOR_FREQUENCY);
       }
}
#else   //USEDRV8701
void MotorCtrl (sint32 motor1, sint32 motor2)
{
    if (motor1 > 0)
    {
        ATOM_PWM_SetDuty(MOTOR1_P, motor1, MOTOR_FREQUENCY);
        ATOM_PWM_SetDuty(MOTOR1_N, 0, MOTOR_FREQUENCY);
    }
    else
    {
        ATOM_PWM_SetDuty(MOTOR1_P, (0-motor1),  MOTOR_FREQUENCY);
        ATOM_PWM_SetDuty(MOTOR1_N, (motor1), MOTOR_FREQUENCY);
    }

    if (motor2 > 0)
    {
        ATOM_PWM_SetDuty(MOTOR2_P, motor2, MOTOR_FREQUENCY);
        ATOM_PWM_SetDuty(MOTOR2_N, 0,MOTOR_FREQUENCY);
    }
    else
    {
        ATOM_PWM_SetDuty(MOTOR2_P, (0-motor2), MOTOR_FREQUENCY);
        ATOM_PWM_SetDuty(MOTOR2_N, motor2,MOTOR_FREQUENCY);
    }
}

void MotorCtrl4w(sint32 motor1, sint32 motor2,sint32 motor3, sint32 motor4)
{
    if (motor1 > 0)
       {
           ATOM_PWM_SetDuty(MOTOR1_P, motor1, MOTOR_FREQUENCY);
           ATOM_PWM_SetDuty(MOTOR1_N, 0, MOTOR_FREQUENCY);
       }
       else
       {
           ATOM_PWM_SetDuty(MOTOR1_P, (0-motor1),  MOTOR_FREQUENCY);
           ATOM_PWM_SetDuty(MOTOR1_N, (motor1), MOTOR_FREQUENCY);
       }

       if (motor2 > 0)
       {
           ATOM_PWM_SetDuty(MOTOR2_P, motor2, MOTOR_FREQUENCY);
           ATOM_PWM_SetDuty(MOTOR2_N, 0,MOTOR_FREQUENCY);
       }
       else
       {
           ATOM_PWM_SetDuty(MOTOR2_P, (0-motor2), MOTOR_FREQUENCY);
           ATOM_PWM_SetDuty(MOTOR2_N, motor2,MOTOR_FREQUENCY);
       }
    if (motor3 > 0)
       {
           ATOM_PWM_SetDuty(MOTOR3_P, motor3, MOTOR_FREQUENCY);
           ATOM_PWM_SetDuty(MOTOR3_N, 0, MOTOR_FREQUENCY);
       }
       else
       {
           ATOM_PWM_SetDuty(MOTOR3_P, (0-motor3),  MOTOR_FREQUENCY);
           ATOM_PWM_SetDuty(MOTOR3_N, motor3,MOTOR_FREQUENCY);
       }

       if (motor4 > 0)
       {
           ATOM_PWM_SetDuty(MOTOR4_P, motor4, MOTOR_FREQUENCY);
           ATOM_PWM_SetDuty(MOTOR4_N, 0, MOTOR_FREQUENCY);
       }
       else
       {
           ATOM_PWM_SetDuty(MOTOR4_P, (0-motor4), MOTOR_FREQUENCY);
           ATOM_PWM_SetDuty(MOTOR4_N, motor4, MOTOR_FREQUENCY);
       }
}


#endif
/*************************************************************************
 *  �������ƣ�TestMotor(void)
 *  ����˵�������Ա궨���PWM���Ƶ��
 *  ����˵������
 *  �������أ���
 *  �޸�ʱ�䣺2020��4��1��
 *  ��    ע������2�����
 ��ע�����ע�⣬һ��Ҫ�Զ����ǽ�������
 ʹ������ĸ��������̣�
 1.��ʹ�����ñ������ص�ѹ����ر�֤��ص�ѹ��7V���ϣ�������������Ӧ��
 2.�Ӻ�ĸ�嵽��������ź��߼���Դ�ߣ�
 3.�Ӻ������嵽����ĵ��ߣ�
 4.��д�������У�ȷ�����������ת���󣬿����������Դ���أ�
 5.����K0/K1ȷ�����ת���ٶȼ�����
 6.������ַ�ת������K2�����ص���ģʽ������ֱ�ӹر��������Դ��
 *************************************************************************/
void TestMotor (void)
{
    short duty = 1500;
    char txt[16];

    TFTSPI_CLS(u16BLUE);          //����
    TFTSPI_P8X16Str(2, 0, "LQ Motor Test", u16RED, u16BLUE);
    MotorInit();


    while (1)
    {
        if (KEY_Read(KEY0) == 0)      //����KEY0����ռ�ձȼ�С
        {
            if (duty > -ATOM_PWM_MAX)
                duty -= 100;
        }
        if (KEY_Read(KEY2) == 0)      //����KEY2����ռ�ձȼӴ�
        {
            if (duty < ATOM_PWM_MAX)      //��ռ�ձ�Ϊ12500
                duty += 100;
        }
        if (KEY_Read(KEY1) == 0)      //����KEY1����ռ�ձ���ֵ
        {
            duty = 1500;
        }

        //MotorCtrl(duty, duty);
        MotorCtrl4w(duty,duty,duty,duty);
        sprintf(txt, "PWM: %05d;", duty);
        TFTSPI_P8X16Str(0, 5, txt, u16WHITE, u16BLACK);       //�ַ�����ʾ
        UART_PutStr(UART0, txt);

        LED_Ctrl(LED0, RVS);       //��ƽ��ת,LED��˸
        delayms(200);              //��ʱ�ȴ�
    }
}
/*************************************************************************
 *  �������ƣ�void ServoInit(void)
 *  ����˵�������PWM��ʼ��
 *  ����˵������
 *  �������أ���
 *  �޸�ʱ�䣺2020��4��1��
 *  ��    ע������2�����
 *************************************************************************/
void ServoInit (void)
{
    ATOM_PWM_InitConfig(ATOMSERVO1, Servo_Center_Mid, 50);  //���Ƶ��Ϊ100HZ����ʼֵΪ1.5ms��ֵ
    ATOM_PWM_InitConfig(ATOMSERVO2, Servo_Center_Mid, 50);  //������۷�ΧΪ��0.5ms--2.5ms�������ʵ�ʱ������ΧС
}

/*************************************************************************
 *  �������ƣ�void ServoCtrl(uint32 duty)
 *  ����˵�������ת�Ǻ���������С�����˷�Χ���ƣ���С
 *  ����˵����short duty��ռ�ձ�
 *  �������أ���
 *  �޸�ʱ�䣺2020��4��1��
 *  ��    ע������2���������ͨ����ֻ��Ҫһ���������
 *************************************************************************/
void ServoCtrl (uint32 duty)
{
    if (duty >= Servo_Left_Max)                  //���Ʒ�ֵ
        duty = Servo_Left_Max;
    else if (duty <= Servo_Right_Min)            //���Ʒ�ֵ
        duty = Servo_Right_Min;

    ATOM_PWM_InitConfig(ATOMSERVO1, duty, 50);  //���Ƶ��Ϊ100HZ����ʼֵΪ1.5ms��ֵ
    ATOM_PWM_InitConfig(ATOMSERVO2, duty, 50);  //������۷�ΧΪ��0.5ms--2.5ms�������ʵ�ʱ������ΧС
}

/*************************************************************************
 *  �������ƣ�Test_Servo(void)
 *  ����˵�������PWM��ʼ�������Ա궨���PWM����SD5/S3010���
 *  ����˵������
 *  �������أ���
 *  �޸�ʱ�䣺2020��4��1��
 *  ��    ע������2�����
 ��ע�����ע�⣬һ��Ҫ�Զ����ǽ�������
 ʹ������ĸ��������̣�
 1.��ʹ�����ñ������ص�ѹ����ر�֤��ص�ѹ��7V���ϣ�������������Ӧ��
 2.Ȼ��ȷ����������ѹ��SD5�����5V���磬S3010��6-7V���磡����
 3.�Ѷ���Ķ���ȥ�����ö����������ת����
 4.��д�������У��ö��ת������ֵ���������û��Ӧ�ظ�1-2�������ߵ��������PWMƵ�ʼ�ռ�ձȣ����ܿ�Ϊ׼��
 5.����ܿغ�������ת�������֨֨�죬�Կ�ת������ʱ����װ�϶��̣�
 6.����K0/K1ȷ�����������ת�����ޣ�������������Ϊ�����޷���ֹ�����ת�ջ٣�
 *************************************************************************/
void TestServo (void)
{
    char txt[16] = "X:";
    signed short duty = Servo_Center_Mid;

    TFTSPI_CLS(u16BLUE);          //����
    TFTSPI_P8X16Str(2, 0, "LQ Servo Test", u16RED, u16BLUE);
    ServoInit();
    ServoCtrl(Servo_Center_Mid);      //��ֵ
    while (1)
    {
        if (!KEY_Read(KEY0))
        {
            if (duty > 10)  //��ֹduty��
            {
                duty -= 10;
            }
        }
        if (!KEY_Read(KEY1))
        {
            duty = Servo_Center_Mid;
        }
        if (!KEY_Read(KEY2))
        {
            duty += 10;
        }

        ATOM_PWM_SetDuty(ATOMSERVO2, duty, 50);
        ATOM_PWM_SetDuty(ATOMSERVO1, duty, 50);
        sprintf(txt, "Servo duty:%04d ", duty);
        TFTSPI_P8X16Str(1, 2, txt, u16BLACK, u16GREEN); //��ʾ����ʵ�����������Ա�������
        LED_Ctrl(LEDALL, RVS);        //�ĸ�LEDͬʱ��˸;
        delayms(100);
    }
}

/*************************************************************************
 *  �������ƣ�void TestEncoder(void)
 *  ����˵�������Գ���TFT1.8��ʾ
 *  ����˵������
 *  �������أ���
 *  �޸�ʱ�䣺2020��4��10��
 *  ��    ע��
 *************************************************************************/
void TestEncoder(void)
{
    char txt[32];

    TFTSPI_CLS(u16BLUE);   //��ɫ��Ļ
    TFTSPI_P8X16Str(0, 0, "Test Encoder", u16WHITE, u16BLACK);      //�ַ�����ʾ
    EncInit();
    while (1)
    {
        /* ��ȡ������ֵ */
        ECPULSE1 = ENC_GetCounter(ENC2_InPut_P33_7); //���� ĸ���ϱ�����1��С��ǰ��Ϊ��ֵ
        ECPULSE2 = ENC_GetCounter(ENC4_InPut_P02_8); //�ҵ�� ĸ���ϱ�����2��С��ǰ��Ϊ��ֵ

        sprintf(txt, "Enc1: %05d;", ECPULSE1);
        TFTSPI_P8X16Str(0, 3, txt, u16WHITE, u16BLACK);       //�ַ�����ʾ
        sprintf(txt, "Enc2: %05d;", ECPULSE2);
        TFTSPI_P8X16Str(0, 5, txt, u16WHITE, u16BLACK);       //�ַ�����ʾ

        LED_Ctrl(LED0, RVS);        //��ƽ��ת,LED��˸
        delayms(200);              //��ʱ�ȴ�
    }
}

/*************************************************************************
 *  �������ƣ�uint8 SetCircleNum (void)
 *  ����˵����������Ҫ����Բ���ĸ�����
 *  ����˵������
 *  �������أ���
 *  �޸�ʱ�䣺2020��11��18��
 *  ��    ע��
 *************************************************************************/
uint8 SetCircleNum (void)
{
    char txt[16] = " ";
    uint8 num = 1;

    TFTSPI_CLS(u16BLACK);            // ����
    TFTSPI_P8X16Str(2, 1, "LQ Smart Car", u16RED, u16BLUE);
    TFTSPI_P8X16Str(2, 3, "K2 num +", u16RED, u16BLUE);
    TFTSPI_P8X16Str(2, 4, "K1 set OK", u16RED, u16BLUE);
    TFTSPI_P8X16Str(2, 5, "K0 num -", u16RED, u16BLUE);
    TFTSPI_P8X16Str(2, 7, "Ring num:  ", u16RED, u16BLUE);

    while (KEY_Read(KEY1))
    {
        if (KEY_Read(KEY2) == 0)
        {
            if (num < 10)
                num++;
        }
        else if (KEY_Read(KEY0) == 0)
        {
            if (num > 0)
                num--;
        }
        sprintf(txt, "Ring num: %d ", num);
        TFTSPI_P8X16Str(2, 7, txt, u16WHITE, u16BLUE);

        delayms(100);
    }
    return num;
}

/*************************************************************************
 *  �������ƣ�void OutInGarage(uint8 inout, uint8 lr)
 *  ����˵���������
 *  ����˵����uint8 inout:0���⣬1��⣻
 *          uint8 lr��0�����⣻1�ҳ����
 *  �������أ���
 *  �޸�ʱ�䣺2020��11��18��
 *  ��    ע��   OutInGarage(1,0); // �Ҳ����
 *************************************************************************/
void OutInGarageTft (uint8 inout, uint8 lr)// �����ã�����Ļ��ʾ����Ҫ��ͻ
{
    char txt[16];
    sint32 ps = 0;
    // �м�CPU0,CPU1...������ͬʱ������Ļ��ʾ�������ͻ����ʾ
    mutexCpu0TFTIsOk = 0;         // CPU1�� 0ռ��/1�ͷ� TFT
    delayms(10);
    TFTSPI_CLS(u16BLACK);         // ����
    if (lr)           // 1�ҳ����
    {
        if (inout)    // 1�����
        {
            NowTime = (STM_GetNowUs(STM0) - NowTime) / 1000;  // ��ȡSTM0 ��ǰʱ�䣬�õ�����
            // 2020���¼ӳ���Ԫ�أ��˴�Ϊä�����
            ps = RAllPulse;
            ServoCtrl(Servo_Center_Mid);  // ���е���
            MotorCtrl(-2500, -2500);      // ��󵹳�
            while (RAllPulse > ps - 1500) //
            {
                // �ҵ�� ĸ���ϱ�����2��С��ǰ��Ϊ��ֵ�����ۼ�
                sprintf(txt, "Enc1:%04d ", (sint16)(RAllPulse - ps));
                TFTSPI_P8X16Str(2, 4, txt, u16BLACK, u16BLUE); // ��ʾ����ʵ�����������Ա�������
                delayms(10);
            }

            ps = RAllPulse;
            ServoCtrl(Servo_Right_Min);    // ������Ҵ���Ϊ������׼��
            MotorCtrl(-3000, -2000);       // �Һ󵹳������ֿ죬��������
            while (RAllPulse > ps - 2000)  // ��ͣ��λ���⣬��ԼҪ512������2000�����壬����512�����������1��5790������
            {
                // �ҵ�� ĸ���ϱ�����1��С������Ϊ��ֵ�����ۼӵ�����Ϊֹ
                sprintf(txt, "Enc1:%04d ", (sint16)(RAllPulse - ps));
                TFTSPI_P8X16Str(2, 4, txt, u16BLACK, u16BLUE); // ��ʾ����ʵ�����������Ա�������
                delayms(10);
            }
            ps = RAllPulse;
            ServoCtrl(Servo_Center_Mid);  // ���е���
            MotorCtrl(-2500, -2500);      // ��󵹳������ֿ죬������
            while (RAllPulse > ps - 800) // �ҵ�� ĸ���ϱ�����1��С������Ϊ��ֵ�����ۼӵ�����Ϊֹ
            {
                // �ҵ�� ĸ���ϱ�����1��С������Ϊ��ֵ�����ۼӵ�����Ϊֹ
                sprintf(txt, "Enc1:%04d ", (sint16)(RAllPulse - ps));
                TFTSPI_P8X16Str(2, 4, txt, u16BLACK, u16BLUE); // ��ʾ����ʵ�����������Ա�������
                delayms(10);
            }
            sprintf(txt, "Enc1:%04d ", (sint16)(RAllPulse - ps));
            TFTSPI_P8X16Str(2, 4, txt, u16BLACK, u16BLUE); // ��ʾ����ʵ�����������Ա�������

            IfxCpu_disableInterrupts(); // �ر������ж�
            MotorCtrl(3000, 3000);
            delayms(300);               // �����תɲ������ֹ����������ʱ������ٶȵ���
            MotorCtrl(0, 0);            // ͣ��

            TFTSPI_CLS(u16RED);        // ����
            sprintf(txt, "Time:%d.%03ds", (sint16) (NowTime / 1000), (sint16) (NowTime % 1000));
            TFTSPI_P8X16Str(2, 4, txt, u16BLACK, u16BLUE); // ��ʾ����ʵ�����������Ա�������
            TFTSPI_P8X16Str(2, 2, "!!WellDone!!", u16WHITE, u16RED); // �����ϣ�����ͣ��
            while (1);                 // �����ϣ�����ͣ��
        }
        else  // 0�ҳ���
        {
            // 2020���¼ӳ���Ԫ�أ��˴�Ϊä�߳���
            ps = RAllPulse;
            ServoCtrl(Servo_Center_Mid); // ֱ�д�Լ10cm
            MotorCtrl(2500, 2500);       //
            while (RAllPulse < ps + 600)
            {
                // �ҵ�� ĸ���ϱ�����2��С��ǰ��Ϊ��ֵ�����ۼӵ�����Ϊֹ
                sprintf(txt, "Enc2:%04d ", (sint16)(RAllPulse - ps));
                TFTSPI_P8X16Str(2, 4, txt, u16BLACK, u16BLUE); // ��ʾ����ʵ�����������Ա�������
                delayms(10);
            }

            ps = RAllPulse;
            ServoCtrl(Servo_Right_Min); // ������Ҵ���Ϊ������׼��
            MotorCtrl(3500, 3000);       // ��ת�����ֿ죬��������
            while (RAllPulse < ps + 1200)
            {
                // �ҵ�� ĸ���ϱ�����2��С��ǰ��Ϊ��ֵ�����ۼӵ�����Ϊֹ
                sprintf(txt, "Enc2:%04d ", (sint16)(RAllPulse - ps));
                TFTSPI_P8X16Str(2, 4, txt, u16BLACK, u16BLUE); // ��ʾ����ʵ�����������Ա�������
                delayms(10);
            }
            LED_Ctrl(LED3, OFF);        // LED��˸ ָʾ��������״̬
            sprintf(txt, "Enc2:%04d ", (sint16)(RAllPulse - ps));
            TFTSPI_P8X16Str(2, 4, txt, u16BLACK, u16BLUE); // ��ʾ����ʵ�����������Ա�������

            // MotorCtrl(-2000, -2000);
            // delayms(200);               // �����תɲ������ֹ����������ʱ������ٶȵ���
            // ServoCtrl(Servo_Center_Mid);// ����
            // MotorCtrl(0, 0);            // ͣ��
            // while(1);                   // �����ã������ܳ���Ҫɾ���þ�
        }
    }
    else // 0�������⣻
    {
        if (inout) // 1�����
        {
            NowTime = (STM_GetNowUs(STM0) - NowTime) / 1000;  // ��ȡSTM0 ��ǰʱ�䣬�õ�����
            // 2020���¼ӳ���Ԫ�أ��˴�Ϊä�����
            ps = RAllPulse;
            ServoCtrl(Servo_Center_Mid);  // ���е���
            MotorCtrl(-2000, -2000);      // ��󵹳������ֿ죬������
            while (RAllPulse > ps - 600)  // �ҵ�� ĸ���ϱ�����1��С������Ϊ��ֵ�����ۼӵ�Ϊֹ
            {
                delayms(10);
            }

            ps = RAllPulse;
            ServoCtrl(Servo_Left_Max);    // ������Ҵ���Ϊ������׼��
            MotorCtrl(-2500, -2500);      // ��󵹳������ֿ죬������
            while (RAllPulse > ps - 2800)
            {
                // �ҵ�� ĸ���ϱ�����1��С������Ϊ��ֵ�����ۼӵ�����Ϊֹ
                sprintf(txt, "Enc1:%04d ", (sint16)(RAllPulse - ps));
                TFTSPI_P8X16Str(2, 4, txt, u16BLACK, u16BLUE); // ��ʾ����ʵ�����������Ա�������
                delayms(10);
            }

            ps = RAllPulse;
            ServoCtrl(Servo_Center_Mid);  // ���е���
            MotorCtrl(-2500, -2500);      // ��󵹳������ֿ죬������
            while (RAllPulse > ps - 1500)
            {
                // �ҵ�� ĸ���ϱ�����1��С������Ϊ��ֵ�����ۼӵ�����Ϊֹ
                sprintf(txt, "Enc1:%04d ", (sint16)(RAllPulse - ps));
                TFTSPI_P8X16Str(2, 4, txt, u16BLACK, u16BLUE); // ��ʾ����ʵ�����������Ա�������
                delayms(10);
            }
            sprintf(txt, "Enc1:%04d ", (sint16)(RAllPulse - ps));
            TFTSPI_P8X16Str(2, 4, txt, u16BLACK, u16BLUE); // ��ʾ����ʵ�����������Ա�������

            IfxCpu_disableInterrupts(); // �ر������ж�
            MotorCtrl(3000, 3000);
            delayms(300);               // �����תɲ������ֹ����������ʱ������ٶȵ���
            MotorCtrl(0, 0);            // ͣ��

            TFTSPI_CLS(u16RED);        // ����
            sprintf(txt, "Time:%d.%03ds", (sint16)(NowTime/1000),(sint16)(NowTime%1000));
            TFTSPI_P8X16Str(2, 4, txt, u16BLACK, u16BLUE); // ��ʾ����ʵ�����������Ա�������
            TFTSPI_P8X16Str(2, 2, "!!WellDone!!", u16WHITE, u16RED); // �����ϣ�����ͣ��
            while (1) ;                 // �����ϣ�����ͣ��
        }
        else  // 0�����
        {
            // 2020���¼ӳ���Ԫ�أ��˴�Ϊä�߳���
            ps = RAllPulse;
            ServoCtrl(Servo_Center_Mid); // ֱ�д�Լ10cm
            MotorCtrl(2500, 2500);       //
            while (RAllPulse < ps + 600)
            {
                // �ҵ�� ĸ���ϱ�����2��С��ǰ��Ϊ��ֵ�����ۼӵ�����Ϊֹ
                sprintf(txt, "Enc2:%04d ", (sint16)(RAllPulse - ps));
                TFTSPI_P8X16Str(2, 4, txt, u16BLACK, u16BLUE); // ��ʾ����ʵ�����������Ա�������
                delayms(10);
            }

            ps = RAllPulse;
            ServoCtrl(Servo_Left_Max); // ����������Ϊ������׼��
            MotorCtrl(3000, 3500);     // ��ת�����ֿ죬��������
            while (RAllPulse < ps + 1800)
            {
                // �ҵ�� ĸ���ϱ�����2��С��ǰ��Ϊ��ֵ�����ۼӵ�����Ϊֹ
                sprintf(txt, "Enc2:%04d ", (sint16)(RAllPulse - ps));
                TFTSPI_P8X16Str(2, 4, txt, u16BLACK, u16BLUE); // ��ʾ����ʵ�����������Ա�������
                delayms(10);
            }
            LED_Ctrl(LED3, OFF);        // LED��˸ ָʾ��������״̬
            sprintf(txt, "Enc2:%04d ", (sint16)(RAllPulse - ps));
            TFTSPI_P8X16Str(2, 4, txt, u16BLACK, u16BLUE); // ��ʾ����ʵ�����������Ա�������
            // MotorCtrl(-2000, -2000);
            // delayms(100);               // �����תɲ������ֹ����������ʱ������ٶȵ���
            // ServoCtrl(Servo_Center_Mid);// ����
            // MotorCtrl(0, 0);            // ͣ��
            // while(1);                   // �����ã������ܳ���Ҫɾ���þ�
        }
    }
    // �м�CPU0,CPU1...������ͬʱ������Ļ��ʾ�������ͻ����ʾ
    mutexCpu0TFTIsOk = 1;         // CPU1�� 0ռ��/1�ͷ� TFT
}
void OutInGarage (uint8 inout, uint8 lr)
{
    sint32 ps = 0;

    if (lr)           // 1�ҳ����
    {
        if (inout)    // 1�����
        {
            NowTime = (STM_GetNowUs(STM0) - NowTime) / 1000;  // ��ȡSTM0 ��ǰʱ�䣬�õ�����
            // 2020���¼ӳ���Ԫ�أ��˴�Ϊä�����
            ps = RAllPulse;
            ServoCtrl(Servo_Center_Mid);  // ���е���
            MotorCtrl(2000, 2000);        // ��󵹳�
            while (RAllPulse < ps + 2000) // ����ǰ����Լ35cm
            {
                delayms(10);
            }
            MotorCtrl(-2500, -2500);      // ɲ��
            delayms(300);

            ps = RAllPulse;
            ServoCtrl(Servo_Right_Min);   // ������Ҵ���Ϊ������׼��
            MotorCtrl(-3000, -2000);      // �Һ󵹳������ֿ죬��������
            while (RAllPulse > ps - 2000) // ��ͣ��λ���⣬��ԼҪ512������2000�����壬����512�����������1��5790������
            {   // �ҵ�� ĸ���ϱ�����1��С������Ϊ��ֵ�����ۼӵ�����Ϊֹ
                delayms(10);
            }
            ps = RAllPulse;
            ServoCtrl(Servo_Center_Mid);  // ���е���
            MotorCtrl(-2500, -2500);      // ��󵹳������ֿ죬������
            while (RAllPulse > ps - 800)  // �ҵ�� ĸ���ϱ�����1��С������Ϊ��ֵ�����ۼӵ�����Ϊֹ
            {
                delayms(10);
            }
            IfxCpu_disableInterrupts();  // �ر������ж�
            MotorCtrl(3000, 3000);
            delayms(300);                // �����תɲ������ֹ����������ʱ������ٶȵ���
            MotorCtrl(0, 0);             // ͣ��
            while (1);                   // �����ϣ�����ͣ��
        }
        else  // 0�ҳ���
        {
            // 2020���¼ӳ���Ԫ�أ��˴�Ϊä�߳���
            ps = RAllPulse;
            ServoCtrl(Servo_Center_Mid); // ֱ�д�Լ10cm
            MotorCtrl(2500, 2500);       //
            while (RAllPulse < ps + 600)
            {
                delayms(10);
            }

            ps = RAllPulse;
            ServoCtrl(Servo_Right_Min); // ������Ҵ���Ϊ������׼��
            MotorCtrl(3500, 3000);       // ��ת�����ֿ죬��������
            while (RAllPulse < ps + 1200)
            {
                delayms(10);
            }
        }
    }
    else // 0�������⣻
    {
        if (inout) // 1�����
        {
            NowTime = (STM_GetNowUs(STM0) - NowTime) / 1000;  // ��ȡSTM0 ��ǰʱ�䣬�õ�����
            // 2020���¼ӳ���Ԫ�أ��˴�Ϊä�����
            ps = RAllPulse;
            ServoCtrl(Servo_Center_Mid);  // ���е���
            MotorCtrl(2000, 2000);        // ��󵹳�
            while (RAllPulse < ps + 2500) // ����ǰ����Լ35cm
            {
                delayms(10);
            }
            MotorCtrl(-2500, -2500);      // ɲ��
            delayms(300);

            ps = RAllPulse;
            ServoCtrl(Servo_Left_Max);    // ������Ҵ���Ϊ������׼��
            MotorCtrl(-2000, -3000);      // ��󵹳������ֿ죬������
            while (RAllPulse > ps - 3000)
            {
                delayms(10);
            }

            ps = RAllPulse;
            ServoCtrl(Servo_Center_Mid);  // ���е���
            MotorCtrl(-2500, -2500);      // ��󵹳������ֿ죬������
            while (RAllPulse > ps - 1500)
            {
                delayms(10);
            }
            IfxCpu_disableInterrupts(); // �ر������ж�
            MotorCtrl(3000, 3000);
            delayms(300);               // �����תɲ������ֹ����������ʱ������ٶȵ���
            MotorCtrl(0, 0);            // ͣ��
            while (1) ;                 // �����ϣ�����ͣ��
        }
        else  // 0�����
        {
            // 2020���¼ӳ���Ԫ�أ��˴�Ϊä�߳���
            ps = RAllPulse;
            ServoCtrl(Servo_Center_Mid); // ֱ�д�Լ10cm
            MotorCtrl(2500, 2500);       //
            while (RAllPulse < ps + 600)
            {
                delayms(10);
            }

            ps = RAllPulse;
            ServoCtrl(Servo_Left_Max); // ����������Ϊ������׼��
            MotorCtrl(3000, 3500);     // ��ת�����ֿ죬��������
            while (RAllPulse < ps + 1800)
            {
                delayms(10);
            }
        }
    }
}

/*************************************************************************
 *  �������ƣ�uint8 ReadOutInGarageMode(void)
 *  ����˵������ȡ���뿪�����ó����ģʽ
 *  ����˵������
 *  �������أ������ģʽ,0�����⣻Ĭ��1�ҳ����
 *  �޸�ʱ�䣺2020��11��18��
 *  ��    ע��
 *************************************************************************/
uint8 ReadOutInGarageMode (void)
{
    return (KEY_Read(DSW0));
}
//
