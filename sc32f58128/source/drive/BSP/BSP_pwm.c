#include "BSP_pwm.h"

struct PWMGEN mg_sPwmTest1 = PWMGEN_DEFAULTS;

/*****
  * @brief      PWM ch Initialize
  * @param[in]  ch : pwm ch
  * @Note       
*/

void PWM_Init(uint8_t ch,uint16_t PeriodNum){
	
	switch(ch){
		case PWM_CH0:{
			GPIO_MuxSel(GPIO_0, 1);
      GPIO_MuxSel(GPIO_1, 1);
		}break;
		case PWM_CH1:{
			GPIO_MuxSel(GPIO_2, 1);
      GPIO_MuxSel(GPIO_3, 1);
		}break;
		case PWM_CH2:{
			GPIO_MuxSel(GPIO_4, 1);
      GPIO_MuxSel(GPIO_5, 1);
		}break;
		case PWM_CH3:{
			GPIO_MuxSel(GPIO_6, 1);
      GPIO_MuxSel(GPIO_7, 1);
		}break;
		case PWM_CH4:{
			GPIO_MuxSel(GPIO_8, 1);
      GPIO_MuxSel(GPIO_9, 1);
		}break;
		case PWM_CH5:{
			GPIO_MuxSel(GPIO_10, 1);
      GPIO_MuxSel(GPIO_11, 1);
		}break;
		default:
			break;
	}
	
	STOP_ALL_PWM;

  mg_sPwmTest1.PeriodMax = PeriodNum;                        
  mg_sPwmTest1.HalfPerMax = mg_sPwmTest1.PeriodMax / 2; 
  mg_sPwmTest1.Deadband = 100;
	
  PWM_INIT_MACRO(ch,mg_sPwmTest1);
	
  START_ALL_PWM;
}


































