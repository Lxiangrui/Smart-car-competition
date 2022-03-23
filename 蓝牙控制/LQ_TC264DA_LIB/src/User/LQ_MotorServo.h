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
#ifndef SRC_APPSW_TRICORE_USER_LQ_MOTORCONTROL_H_
#define SRC_APPSW_TRICORE_USER_LQ_MOTORCONTROL_H_

#include "../../Libraries/iLLD/TC26B/Tricore/Cpu/Std/Platform_Types.h"

#define  Kbat       2    // ��ص�ѹ�Ե��ռ�ձȵ�Ӱ��ϵ��
#define  Kencoder   5    // �������ٶȶԵ��ռ�ձȵ�Ӱ��ϵ��
#define  Koffset    1    // �������ʶԵ��ռ�ձȵ�Ӱ��ϵ��

#define TURN_LEFT    0   // ��ת
#define TURN_RIGHT   1   // ��ת
#define IN_GARAGE    1   // ���
#define OUT_GARAGE   0   // ����

#define Servo_Delta 150

#define Servo_Delta 150            //�������ת���Ĳ�ֵ�������ͺţ����˺Ͷ���۳��й�
#define Servo_Center_Mid 600      //���ֱ����ֵ��
#define Servo_Left_Max   (Servo_Center_Mid+Servo_Delta)      //�����ת����ֵ
#define Servo_Right_Min  (Servo_Center_Mid-Servo_Delta)      //�����ת����ֵ����ֵ��������÷�ʽ�йأ���ʽ

#define MtTargetDuty  4200  //���ռ�ձ�ֵ�����ֵ��ʵ����Ҫ��ȥ��ص�ѹ�����������������ʣ��ﲻ����ֵ

extern sint16 ServoDuty;
extern sint16 MotorDuty1;      // �������ռ�ձ���ֵ
extern sint16 MotorDuty2;      // �������ռ�ձ���ֵ
extern sint32 NowTime;
extern uint16 BatVolt;         // ��ص�ѹ�ɼ�
extern unsigned char Camera_Flag; // ����ʶ
extern uint8 CircleNumber;// �뻷������0������Ĭ��1�� ;���ĸ���һ���ڱ���ǰ��������ʱ��֪����
extern sint16 OFFSET0;    // ��Զ������������ֵ�ۺ�ƫ����
extern sint16 OFFSET1;    // �ڶ���
extern sint16 OFFSET2;    // �����������

void EncInit(void);
void TestEncoder(void);

void MotorInit(void);
void MotorCtrl(sint32 motor1, sint32 motor2);
void MotorCtrl4w(sint32 motor1, sint32 motor2,sint32 motor3, sint32 motor4);
void TestMotor(void);

void ServoInit(void);
void ServoCtrl(uint32 duty);
void TestServo(void);
uint8 ReadOutInGarageMode (void);
void OutInGarage (uint8 inout, uint8 lr);
void OutInGarageTft (uint8 inout, uint8 lr);// �����ã�����Ļ��ʾ����Ҫ��ͻ
uint8 SetCircleNum (void);
void CircleDetect (void);




#endif /* SRC_APPSW_TRICORE_USER_LQ_MOTORCONTROL_H_ */
