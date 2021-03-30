#include "main.h"
#include "gpio.h"
#include "tim.h"
#include "usart.h"
#include "mcu_api.h"
#include "protocol.h"
#include "hardware.h"

//uint8_t angle舵机转动的角度（只能取10的倍数）,uint8_t s开关量
uint8_t quick_feed_mode(uint8_t angle,uint8_t s)
{
	if(s==1)
	{
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 5);	//高电平0.5ms复位
	HAL_Delay(300);
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, angle/10+5);	//每10度，增加0.1ms
		return 1;
	}
	else 
	{
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 5);	//高电平0.5ms复位
		return 1;
	}
	return 0;
}

uint8_t manual_feed_mode(uint8_t manual_feed,uint8_t s)
{
	if(s==1)
	{
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 5);	//高电平0.5ms复位
	HAL_Delay(300);		// 手动喂食按照主人意愿喂食，喂食多就开启角度大一点，时间通过简单延时调整
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, manual_feed+5);	//手动喂食度每大一增加10度
	HAL_Delay(3000);	
	}
	else 
	{
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 5);	//高电平0.5ms复位
		return 1;
	}
	return 0;
}

void error()	//异常处理，这里占个位，但是不写
{
}
