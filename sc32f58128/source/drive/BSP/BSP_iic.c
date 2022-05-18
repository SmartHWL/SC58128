#include "BSP_iic.h"



void IIC_GPIO_Init(uint8_t ch){
	switch(ch){
		case 1:{
			GPIO_OutputEnable(IIC1_SDA);
			GPIO_OutputEnable(IIC1_SCL);
		}break;
		case 2:{
			
		}break;
		default:
			break;
	}
}

void IIC_Start(uint8_t ch){
	switch(ch){
		case 1:{
			SDA1_OUT();
			IIC1_SDA_HIGH;
			IIC1_SCL_HIGH;
			//time_delayUs(2);
			IIC1_SDA_LOW;
			//time_delayUs(2);
			IIC1_SCL_LOW;
		}break;
		case 2:{
		}break;
		default:
			break;
	}
}

void IIC_Stop(uint8_t ch)
{
  switch(ch){
    case 1:{
      SDA1_OUT();
		  IIC1_SDA_LOW;
			IIC1_SCL_LOW;
//    TIM2_DelayUs(4);
      IIC1_SDA_HIGH;
			IIC1_SCL_HIGH;
//    TIM2_DelayUs(4);
    }break;
    case 2:{
    }break;
		default:
			break;
  }
}

uint8_t IIC_Wait_ACK(uint8_t ch)
{
  uint8_t ucErrTime=0;
  switch(ch){
    case 1:{
      IIC1_SDA_HIGH;
//		TIM2_DelayUs(1);
      SDA1_IN();  
      IIC1_SCL_HIGH;
//		TIM2_DelayUs(1);
      while(IIC1_SDA_READ){
        ucErrTime++;
        if(ucErrTime>250){
          IIC_Stop(1);
          return 1;
          }
      }
      IIC1_SCL_LOW;   
      return 0;
    }break;
    case 2:{
      return 0;
    }break;
		default:
			break;
  }
  return 0;
}

void IIC_ACK(uint8_t ch)
{
  switch(ch){
    case 1:{
      IIC1_SCL_LOW;
      SDA1_OUT();
      IIC1_SDA_LOW;
//    TIM2_DelayUs(2);
      IIC1_SCL_HIGH;
//    TIM2_DelayUs(2);
      IIC1_SCL_LOW;
   }break;
   case 2:{
   }break;
	 default:
			break;
  }
}

void IIC_NACK(uint8_t ch){
  switch(ch){
    case 1:{
      IIC1_SCL_LOW;
      SDA1_OUT();
      IIC1_SDA_HIGH;
//      TIM2_DelayUs(2);
      IIC1_SCL_HIGH;
//      TIM2_DelayUs(2);
      IIC1_SCL_LOW;
    }break;
    case 2:{
    }break;
		default:
			break;
  }
}
 
uint8_t IIC_Read_Byte(uint8_t ack,uint8_t ch){
  uint8_t receive=0;
  switch(ch){
    case 1:{
      SDA1_IN();
      for(uint8_t i=0;i<8;i++){
        IIC1_SCL_LOW; 
//      TIM2_DelayUs(2);
        IIC1_SCL_HIGH;
        receive<<=1;
        if(IIC1_SDA_READ)receive++;   
//      TIM2_DelayUs(1); 
      }					 
      if(!ack)
        IIC_NACK(1);
      else
        IIC_ACK(1);  
      return receive;
    }break;
    case 2:{
    }break;
		default:
			break;
  }
   return receive;
}

void IIC_Send_Byte(uint8_t ch,uint8_t txd,OrderENUM order){ 
  switch(ch){
    case 1:{
      SDA1_OUT(); 	    
      //IIC1_SCL=0;
      for(uint8_t t=0;t<8;t++){   
        if(order==1){//LSB
					if((txd&0x01)==0x01){
						IIC1_SDA_HIGH;
					}
					else{
						IIC1_SDA_LOW
					}
          txd=txd>>1;
        }
        else if(order==2){//MSB
					if((txd&0x80)==0x80){
						IIC1_SDA_HIGH;
					}
					else{
						IIC1_SDA_LOW
				  }
          txd<<=1;
        }
//      TIM2_DelayUs(2);   
        IIC1_SCL_LOW;
//      TIM2_DelayUs(2);
        IIC1_SCL_HIGH;
//      TIM2_DelayUs(2); 
        IIC1_SCL_LOW;	
//      TIM2_DelayUs(2);
     }
    }
    case 2:{
        
    }break;
		default:
			break;
  }
}










