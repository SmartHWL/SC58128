/**************************************************************************//**
 * @file     BSP_gpio.c
 * @brief    GPIO related Configuration Source File
 * @version  V1.00
 * @date     25. March 2017
 *
 * @note
 *
 ******************************************************************************/

/******************************************************************************
* include file
*******************************************************************************/
#include "SC32F58128.h"
#include "BSP_gpio.h"

/******************************************************************************
* global data for the project
*******************************************************************************/

/******************************************************************************
* loacal data for the current file
*******************************************************************************/

/******************************************************************************/
/* local prototypes function **************************************************/
/******************************************************************************/

/******************************************************************************
* loacal function for the current file
*******************************************************************************/

/******************************************************************************
* global function for the current project
*******************************************************************************/

/**
  * @brief  Gpio Initialization.
*/
void BSP_GpioInit(void)
{
  /* UART Gpio Config */
//  GPIO_MuxSel(GPIO_WATCHER_TXD, UART0_HS_TXD_29);
//  GPIO_MuxSel(GPIO_WATCHER_RXD, UART0_HS_RXD_28);
//	
//	GPIO_MuxSel(GPIO_UART1_TXD, UART1_LS_TXD_31);
//  GPIO_MuxSel(GPIO_UART1_RXD, UART1_LS_RXD_30);
	
	GPIO_MuxSel(GPIO_UART2_TXD, UART2_LS_TXD_22);
  GPIO_MuxSel(GPIO_UART2_RXD, UART2_LS_RXD_23);

//  GPIO_PullUpDownSel(GPIO_WATCHER_RXD, PULL_UP);
//	GPIO_PullUpDownSel(GPIO_UART1_RXD, PULL_UP);
	GPIO_PullUpDownSel(GPIO_UART2_RXD, PULL_UP);

  /* LED Gpio Config */
  GPIO_OutputEnable(GPIO_LED1);
  GPIO_OutputEnable(GPIO_LED2);
  GPIO_OutputEnable(GPIO_LED3);
	GPIO_OutputEnable(GPIO_31);
	LED1_OFF;
	LED2_OFF;
	LED3_OFF;
}


