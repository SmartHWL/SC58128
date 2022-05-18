#include "BSP_uart.h"
volatile UART0_Type *UARTCH[] = {UART0, UART1, UART2};
struct UARTFIFO s_ufifo;

void BSP_UartInit(uint8_t ch,uint32_t baud){
	
	UartInit(ch, baud, UART_BIT8, PARITY_NONE, STOPBITS_ONE, UART_FIFO_DISABLE, UART_FIFO_DISABLE);
	
	//UartInit(ch, baud, UART_BIT8, PARITY_NONE, STOPBITS_ONE, UART_FIFO_DISABLE, UART_FIFO_rsvd0);//UART_FIFO_rsvd0

	UARTCH[ch]->UARTIMSC_b.Receive_IM    = 1;             //UART_INT_EN_RX(0);
  UARTCH[ch]->UARTIMSC_b.OE_IM         = 1;             //UART_INT_EN_OE(0);
  UARTCH[ch]->UARTICR                  = 0xffff;        //CLR_INT_ALL(0);
  UARTCH[ch]->UARTCR_b.TXE             = 1;             //UART_TX_EN(0);
  UARTCH[ch]->UARTCR_b.RXE             = 1;             //UART_RX_EN(0);
  UARTCH[ch]->UARTCR_b.UARTEN          = 1;             //UART_EN(0);
	
	s_ufifo.frame_len = 8;
  s_ufifo.rx_buff_len_max = 32;
	
}

/**
  * @brief  Transmits single data through the UARTx peripheral.
  * @param  UARTx: Select the UART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *   UART1, UART2, UART3, UART4, UART5 or UART6.
  * @param  Data: the data to transmit.
  * @retval None
  */
void UART_SendData(UART0_Type* UARTx, uint8_t Data){
		
	  /* Check the parameters */
		assert_param(IS_UART_ALL_PERIPH(UARTx));
		assert_param(IS_UART_DATA(Data)); 
    
		/* Transmit Data */
		UARTx->UARTDR_b.DATA = (uint8_t)Data;//UARTx->UARTDR = (uint8_t)Data;
}

void UART_SendArray( UART0_Type* UARTx, uint8_t *array, uint32_t length){

  uint8_t UARTNum=0;
	for (UARTNum=0;UARTNum<10;UARTNum++){
		UARTx->UARTDR_b.DATA = *(array + UARTNum);
	}
//	// WRITE UART ( UART FIFO)
//  while(UARTNum < length){
//    if(!IS_TXFF(2)){ // if uart0 fifo is not full
//      UARTx->UARTDR_b.DATA = *(array + UARTNum);//*(s_ufifo.RX_BUFF + s_ufifo.tx_index);
//      UARTNum++;
//    } else {
//      break;
//    }
//  }
//	UARTNum=0;
}

/**
  * @brief  Returns the most recent received data by the UARTx peripheral.
  * @param  UARTx: Select the UART or the UART peripheral. 
  *   This parameter can be one of the following values:
  *   UART1, UART2, UART3, UART4, UART5 or UART6.
  * @retval The received data.
  */
uint8_t UART_ReceiveData(UART0_Type* UARTx){
	
	uint8_t receive_data;
	
  /* Check the parameters */
  assert_param(IS_UART_ALL_PERIPH(UARTx));
  
  /* Receive Data */
	receive_data = UARTx->UARTDR_b.DATA;//UARTx->UARTDR;
	return receive_data;  
}

uint8_t u8ArrayTest[10]={1,2,3,4,5,6,7,8,9};


void UART_FIFO_deal(){
  // READ UART ( UART FIFO)  
  while(!IS_RXFE(2)){ // if uart0 fifo is empty
    if(IS_INT_RAW_OE(2)){ // uart0 fifo is over
      s_ufifo.u8Flag |= 0x01;
      break;
    }else{
      *(u8ArrayTest + s_ufifo.rx_index) = (uint8_t)UART2->UARTDR_b.DATA;//*(s_ufifo.RX_BUFF + s_ufifo.rx_index) = (uint8_t)UART2->UARTDR_b.DATA;
      s_ufifo.rx_index++;
      if(s_ufifo.rx_index > s_ufifo.rx_buff_len_max){ // uart0 s_ufifo.rx_buff is full
        s_ufifo.u8Flag |= 0x02;
      }
    }
  }
  if(s_ufifo.u8Flag){
    UART_REST_STATUS(2);
    s_ufifo.u8Flag = 0;
    s_ufifo.rx_index = 0;
  }
  
  // data deal
  if(s_ufifo.rx_index == s_ufifo.frame_len){ // one frame data is recived
    s_ufifo.rx_index = 0;
    s_ufifo.tx_index = 0;
  }

  // WRITE UART ( UART FIFO)
  while(s_ufifo.tx_index < s_ufifo.frame_len){
    if(!IS_TXFF(2)){ // if uart0 fifo is not full
      UART2->UARTDR_b.DATA =*(u8ArrayTest + s_ufifo.tx_index);//*(s_ufifo.RX_BUFF + s_ufifo.tx_index);//*(s_ufifo.RX_BUFF + s_ufifo.tx_index);
      s_ufifo.tx_index ++;
    } else {
      break;
    }  
  }  
  if(s_ufifo.tx_index > s_ufifo.frame_len){ // transmit is done
    
  }
}













