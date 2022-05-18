#ifndef __BSP_IIC_H__
#define __BSP_IIC_H__

#include "stdint.h"
#include "SC32F58128.h"
#include "SC32F58128_Gpio.h"

#define IIC1_SDA                    GPIO_8
#define IIC1_SCL                    GPIO_9

#define SDA1_OUT()                    GPIO_OutputEnable(GPIO_8)
#define SDA1_IN()                     GPIO_OutputDisable(GPIO_8)

#define IIC1_SDA_HIGH             {GPIO_SetHigh(GPIO_8);}
#define IIC1_SDA_LOW              {GPIO_SetLow(GPIO_8);}

#define IIC1_SCL_HIGH             {GPIO_SetHigh(GPIO_9);}
#define IIC1_SCL_LOW              {GPIO_SetLow(GPIO_9);}

#define IIC1_SDA_READ             GPIO_GetGpioStatus(GPIO_8)

typedef enum
{
  LSB=1,
  MSB
}OrderENUM;

























#endif



