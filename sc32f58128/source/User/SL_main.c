/**
  ******************************************************************************
  * @file    SL_main.c
  * @author  Silan - MC Team
  * @version 1.0.0
  * @date    2017/07/19
  * @brief   Main File for MiniSystem.
  * @details None
	* @note    None
  ******************************************************************************
  * @attention
  * THE PRESENT SOFTWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
  * AS A RESULT, SILAN MICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
  * INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
  * CONTENT OF SUCH SOFTWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
  * INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
	*
  ******************************************************************************
	* Change History
	* -# 2017/07/19 | v1.0.0 | Wangjianlong | Creat file.
	*
	******************************************************************************
  */

/*******************************************************************************
 * Include file
 ******************************************************************************/
#include "SC32F58128.h"
#include "SC32F58128_can.h"
#include "SC32F58128_iic.h"
#include "SC32F58128_pwm.h"

#include "devInit.h"
#include "timer4Tick.h"
#include "osc.h"
#include "BSP_gpio.h"
#include "BSP_pwm.h"
#include "BSP_uart.h"
#include "SL_niv.h"
#include "iis2dlpc_reg.h"

/**Modbus**/
#include "mb.h"
#include "mbport.h"
#include "mbutils.h"

/******************************************************************************
 * Global data for the project
 ******************************************************************************/


/*******************************************************************************
 * Local data for the current file
 ******************************************************************************/


/*******************************************************************************
 * Local prototypes function
 ******************************************************************************/


/*******************************************************************************
 * Local function for the current file
 ******************************************************************************/

/**
  * @brief   Main function for core 1
  * @param   None
  * @retval  None
  * @note
  */
int main_c1(void)
{
	return 0;
}

/**
  * @brief   Main function for core 0
  * @param   None
  * @retval  None
  * @note
  */
int testnum=0;
int GetPIN=-1;
int PWM0A_Duty=0;

int main(void){
	
  /* Device Init */
  INIT_DeviceInit();

	/* MODBUS Init */
	/* FreeModbus Init,RTU,SlaveID:0x01,UART2,baud:9600*/
	eMBInit(MB_RTU, 0x01, 2, 9600, MB_PAR_NONE);
  eMBEnable();
	
	/* Software Timer Init */
  TICK_TimerInit4C0(&g_Tmr4C0);
	
	while(1){
		
    TICK_TimerTickRunning(&g_Tmr4C0);
    if(IS_1MS_FLG_SET(g_Tmr4C0)){
      CLR_1MS_FLG(g_Tmr4C0);
    }
    if(IS_10MS_FLG_SET(g_Tmr4C0)){
			
			(void)eMBPoll();
      CLR_10MS_FLG(g_Tmr4C0);
    }
    
    if(IS_100MS_FLG_SET(g_Tmr4C0)){
			testnum++;
			PWM0A_Duty=testnum*500;
			if(testnum==1){
				//PWM_DUTYA_UPDATE_SINGLE(0,PWM0A_Duty);
				//LED1_ON;
				LED2_ON;
				LED3_ON;
			}
			else if(testnum==2){
				//PWM_DUTYA_UPDATE_SINGLE(0,PWM0A_Duty);
				//LED1_OFF;
				LED2_OFF;
				LED3_OFF;
				testnum=0;
			}
      CLR_100MS_FLG(g_Tmr4C0);
    }
	}
}

/*---------------------------------- End of the file ---------------------------------*/
