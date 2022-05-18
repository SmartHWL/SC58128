#ifndef __BSP_PWM_H__
#define __BSP_PWM_H__

#include "SC32F58128_pwm.h"
#include "SC32F58128_gpio.h"
typedef enum
{
  PWM_CH0,
	PWM_CH1,
	PWM_CH2,
	PWM_CH3,
	PWM_CH4,
	PWM_CH5,
	PWM_CH6,
	PWM_CH7
}PWMCHENUM;

void PWM_Init(uint8_t ch,uint16_t PeriodNum);





























#endif



