/**
  ******************************************************************************
  * @file    SL_niv.c
  * @author  Silan - MC Team
  * @version 1.0.0
  * @date    2017/07/19
  * @brief   Interrupt Service Routine Source File
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
#include "sl_niv.h"

#include "SC32F58128_timer.h"

#include "BSP_dma.h"
#include "BSP_uart.h"
#include "BSP_gpio.h"
#include "timer4Tick.h"

#include "osc.h"

#include "mb.h"
#include "mbport.h"
#include "mbutils.h"

extern uint8_t UARTArray[10];
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


/******************************************************************************/
/*            Cortex-M0 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
* @brief  This function handles NMI exception.
* @param  None
* @retval None
*/
void NMI_Handler(void)
{
}

/**
* @brief  This function handles Hard Fault exception.
* @param  None
* @retval None
*/
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
    /* Add user code */
  }
}

/**
* @brief  This function handles SysTick Handler.
* @param  None
* @retval None
*/
void SysTick_Handler(void)
{
  g_u32SysTickNumb++;
	
}


/**
* @brief  This function handles SVC Handler.
* @param  None
* @retval None
*/
void SVC_Handler(void)
{

}


/**
* @brief  This function handles PendSV Handler.
* @param  None
* @retval None
*/
void PendSV_Handler(void)
{

}

/******************************************************************************/
/*                 Peripherals Interrupt Handlers                             */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file .                                               */
/******************************************************************************/
/**
* @brief  This function handles UART0 receive interrupt request.
* @param  None
* @retval None
*/
void UART0_RX_IRQHandler(void)
{


}
extern int UARTNum;
/**
* @brief  This function handles UART0 interrupt request.
* @param  None
* @retval None
*/
void UART0_IRQHandler(void)
{
  volatile uint8_t tt;

  /* Receive Interrupt */
  if(IS_INT_RX())
  {
    //DBG_SetRxData(UART_BUFF);
		//UARTNum=UART_ReceiveData(UART2);
    CLR_INT_FLAG_RX();
  }

  /* Transmit Interrupt */
  if(IS_INT_TX())
  {
    CLR_INT_FLAG_TX();
  }

  /* Overrun Error Interrupt */
  if(IS_INT_OE())
  {
   // tt = UART_BUFF;
    UART_REST_OE();
  }
}



/**
* @brief  This function handles SSP0&1 interrupt requests.
* @param  None
* @retval None
*/
void SSP01_IRQHandler(void)
{

}

/**
* @brief  This function handles SSP2&3 interrupt requests.
* @param  None
* @retval None
*/
void SSP23_IIC_IRQHandler(void)
{

}
/**
* @brief  This function handles CAN interrupt request.
* @param  None
* @retval None
*/
void CAN_IRQHandler(void)
{

}
 /**
* @brief  This function handles ECAP0 interrupt request.
* @param  None
* @retval None
*/
void ECAP0_IRQHandler(void)
{


}

/**
* @brief  This function handles ECAP1 interrupt request.
* @param  None
* @retval None
*/
void ECAP1_IRQHandler(void)
{


}
/**
* @brief  This function handles ECAP2 interrupt request.
* @param  None
* @retval None
*/
void ECAP2_IRQHandler(void)
{

}

/**
* @brief  This function handles EQPE0 interrupt request.
* @param  None
* @retval None
*/
void EQEP0_IRQHandler(void)
{
}


/**
* @brief  This function handles EQEP1 interrupt request.
* @param  None
* @retval None
*/
void EQEP1_IRQHandler(void)
{
}

/**
* @brief  This function handles GPIO interrupt request.
* @param  None
* @retval None
*/
void GPIO_IRQHandler(void)
{

}


/**
* @brief  This function handles DMA interrupt request.
* @param  None
* @retval None
*/
void DMA_IRQHandler(void)
{
	/* DMA Channel 0 Done ISR */
  if(IS_DMA0_CHNL_APINT)
  {
    CLR_DMA0_INT_APFLG();
    SendNotSendData2UartTx();
  }
}


/**
* @brief  This function handles COPROC interrupt request.
* @param  None
* @retval None
*/
void COPROC_IRQHandler(void)
{

}


/**
* @brief  This function handles sysrem interrupt request.
* @param  None
* @retval None
*/
void SYS_IRQHandler(void)
{

}


/**
* @brief  This function handles reserved interrupt request.
* @param  None
* @retval None
*/
void rsv1_IRQHandler(void)
{

}




/**
* @brief  This function handles TIMER1 interrupt request.
* @param  None
* @retval None
*/
void TIMER1_IRQHandler(void)
{
	uint32_t u32Tmp = 0;
  u32Tmp = WDT0->WDOGLOAD;  // Read Load Value
  WDT0->WDOGLOAD = u32Tmp;  // Kick Dog
  TIMER[1]->CTRL_b.OV = 0;
}



/**
* @brief  This function handles TIMER2&3&4 interrupt requests.
* @param  None
* @retval None
*/
void TIMER234_IRQHandler(void)
{

}

/**
* @brief  This function handles ADC interrupt 1 request.
* @param  None
* @retval None
*/
void ADC1_IRQHandler(void)
{

}


/**
* @brief  This function handles ADC interrupt 2 request.
* @param  None
* @retval None
*/
void ADC2_IRQHandler(void)
{

}


/**
* @brief  This function handles ADC interrupt 3 request.
* @param  None
* @retval None
*/
void ADC3_IRQHandler(void)
{


}

/**
* @brief  This function handles all ADC interrupt requests.
* @param  None
* @retval None
*/
void ADC_IRQHandler(void)
{


}

/**
* @brief  This function handles PWM0 interrupt request.
* @param  None
* @retval None
*/
void PWM0_IRQHandler(void)
{

}

/**
* @brief  This function handles PWM3 interrupt request.
* @param  None
* @retval None
*/
void PWM3_IRQHandler(void)
{


}

/**
* @brief  This function handles PWM4 interrupt request.
* @param  None
* @retval None
*/
void PWM4_IRQHandler(void)
{


}

/**
* @brief  This function handles PWM7 interrupt request.
* @param  None
* @retval None
*/
void PWM7_IRQHandler(void)
{


}

/**
* @brief  This function handles all PWM interrupt requests.
* @param  None
* @retval None
*/
void PWM1256_IRQHandler(void)
{


}

/**
* @brief  This function handles ERU0 interrupt request.
* @param  None
* @retval None
*/
void ERU0_IRQHandler(void)
{


}

/**
* @brief  This function handles ERU1 interrupt request.
* @param  None
* @retval None
*/
void ERU1_IRQHandler(void)
{


}

/**
* @brief  This function handles ERU2 interrupt request.
* @param  None
* @retval None
*/
void ERU2_IRQHandler(void)
{


}

/**
* @brief  This function handles ERU3 interrupt request.
* @param  None
* @retval None
*/
void ERU3_IRQHandler(void)
{


}

/*---------------------------------- End of the file ---------------------------------*/
