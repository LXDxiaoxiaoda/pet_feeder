#include "main.h"
#include "gpio.h"
#include "tim.h"
#include "usart.h"
#include "mcu_api.h"
#include "protocol.h"
#include "hardware.h"

//uint8_t angle���ת���ĽǶȣ�ֻ��ȡ10�ı�����,uint8_t s������
uint8_t quick_feed_mode(uint8_t angle,uint8_t s)
{
	if(s==1)
	{
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 5);	//�ߵ�ƽ0.5ms��λ
	HAL_Delay(300);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, angle/10+5);	//ÿ10�ȣ�����0.1ms
		return 1;
	}
	else 
	{
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 5);	//�ߵ�ƽ0.5ms��λ
		return 1;
	}
	return 0;
}

uint8_t manual_feed_mode(uint8_t manual_feed,uint8_t s)
{
	if(s==1)
	{
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 5);	//�ߵ�ƽ0.5ms��λ
	HAL_Delay(300);		// �ֶ�ιʳ����������Ըιʳ��ιʳ��Ϳ����Ƕȴ�һ�㣬ʱ��ͨ������ʱ����
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, manual_feed+5);	//�ֶ�ιʳ��ÿ��һ����10��
	HAL_Delay(3000);	
	}
	else 
	{
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 5);	//�ߵ�ƽ0.5ms��λ
		return 1;
	}
	return 0;
}

void error()	//�쳣��������ռ��λ�����ǲ�д
{
}
