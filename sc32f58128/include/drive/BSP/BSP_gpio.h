/**************************************************************************//**
 * @file     BSP_gpio.h
 * @brief    GPIO Related Config Header File
 * @version  V1.00
 * @date     25. March 2017
 *
 * @note
 *
 ******************************************************************************/
#ifndef __BSP_GPIO_H__
#define __BSP_GPIO_H__

/********************************************************************************
 * Include section
 *******************************************************************************/
#include "SC32F58128_Gpio.h"

/********************************************************************************
 * Constants and macros
 *******************************************************************************/

#define GPIO_WATCHER_TXD   GPIO_29
#define GPIO_WATCHER_RXD   GPIO_28

#define GPIO_UART1_TXD   GPIO_31
#define GPIO_UART1_RXD   GPIO_30

#define GPIO_UART2_TXD   GPIO_22
#define GPIO_UART2_RXD   GPIO_23

#define GPIO_LED1          GPIO_36
#define GPIO_LED2          GPIO_35
#define GPIO_LED3          GPIO_38

#define GPIO_TESTPIN       GPIO_21


#define LED1_ON            GPIO_SetLow  (GPIO_LED1)
#define LED1_OFF           GPIO_SetHigh (GPIO_LED1)	
#define LED1_FLASH         GPIO_Toggle	(GPIO_LED1)
#define LED2_ON            GPIO_SetLow  (GPIO_LED2)
#define LED2_OFF           GPIO_SetHigh (GPIO_LED2)	
#define LED2_FLASH         GPIO_Toggle	(GPIO_LED2)
#define LED3_ON            GPIO_SetLow  (GPIO_LED3)
#define LED3_OFF           GPIO_SetHigh (GPIO_LED3)	
#define LED3_FLASH         GPIO_Toggle	(GPIO_LED3)

#define TESTPIN_HIGH       GPIO_SetHigh (GPIO_TESTPIN)	
#define TESTPIN_LOW           (GPIO_TESTPIN)	
#define TESTPIN_TOGGLE     GPIO_Toggle	(GPIO_TESTPIN)

/********************************************************************************
 * Typedefs, structs and enums
 *******************************************************************************/


/********************************************************************************
* Variables
*******************************************************************************/


/********************************************************************************
* prototypes of the functions
*******************************************************************************/
extern void BSP_GpioInit(void);


/*---------------------------------- End of the file ---------------------------------*/
#endif /* __BSP_GPIO_H__ */

