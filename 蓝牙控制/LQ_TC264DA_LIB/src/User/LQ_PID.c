/*LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
��ƽ    ̨�������������ܿƼ�TC264DA���İ�
����    д��chiusir
��E-mail  ��chiusir@163.com
������汾��V1.0
�������¡�2020��4��10��
�������Ϣ�ο����е�ַ��
����    վ��http://www.lqist.cn
���Ա����̡�http://longqiu.taobao.com
------------------------------------------------
��dev.env.��Hightec4.9.3/Tasking6.3�����ϰ汾
��Target �� TC264DA
��Crystal�� 20.000Mhz
��SYS PLL�� 200MHz
����iLLD_1_0_1_11_0�ײ����
QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ*/

#include "LQ_PID.h"

/*************************************************************************
 *  �������ƣ�float constrain_float(float amt, float low, float high)
 *  ����˵�����޷�����
 *  ����˵����
  * @param    amt   �� ����
  * @param    low   �� ���ֵ
  * @param    high  �� ���ֵ
 *  �������أ���
 *  �޸�ʱ�䣺2020��4��1��
 *  ��    ע��
 *************************************************************************/
float constrain_float(float amt, float low, float high)
{
	return ((amt)<(low)?(low):((amt)>(high)?(high):(amt)));
}

// pid������ʼ������
void PidInit(pid_param_t * pid)
{
	pid->kp        = 0;
	pid->ki        = 0;
	pid->kd        = 0;
	pid->imax      = 0;
	pid->out_p     = 0;
	pid->out_i     = 0;
	pid->out_d     = 0;
	pid->out       = 0;
	pid->integrator= 0;
	pid->last_error= 0;
	pid->last_derivative   = 0;
	pid->last_t    = 0;
}

/*************************************************************************
 *  �������ƣ�float constrain_float(float amt, float low, float high)
 *  ����˵����pidλ��ʽ���������
 *  ����˵����
  * @param    pid     pid����
  * @param    error   pid�������
 *  �������أ�PID������
 *  �޸�ʱ�䣺2020��4��1��
 *  ��    ע��
 *************************************************************************/
float PidLocCtrl(pid_param_t * pid, float error)
{
	/* �ۻ���� */
	pid->integrator += error;

	/* ����޷� */
	constrain_float(pid->integrator, -pid->imax, pid->imax);


	pid->out_p = pid->kp * error;
	pid->out_i = pid->ki * pid->integrator;
	pid->out_d = pid->kd * (error - pid->last_error);

	pid->last_error = error;

	pid->out = pid->out_p + pid->out_i + pid->out_d;

	return pid->out;
}
/*************************************************************************
 *  �������ƣ�float constrain_float(float amt, float low, float high)
 *  ����˵����pid����ʽ���������
 *  ����˵����
  * @param    pid     pid����
  * @param    error   pid�������
 *  �������أ�PID������   ע���������Ѿ��������ϴν��
 *  �޸�ʱ�䣺2020��4��1��
 *  ��    ע��
 *************************************************************************/
float PidIncCtrl(pid_param_t * pid, float error)
{

	pid->out_p = pid->kp * (error - pid->last_error);
	pid->out_i = pid->ki * error;
	pid->out_d = pid->kd * ((error - pid->last_error) - pid->last_derivative);

	pid->last_derivative = error - pid->last_error;
	pid->last_error = error;

	pid->out += pid->out_p + pid->out_i + pid->out_d;

	return pid->out;
}

