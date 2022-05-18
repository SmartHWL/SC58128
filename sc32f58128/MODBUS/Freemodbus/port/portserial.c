/*
 * FreeModbus Libary: BARE Port
 * Copyright (C) 2006 Christian Walter <wolti@sil.at>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * File: $Id: portserial.c,v 1.1 2006/08/22 21:35:13 wolti Exp $
 */

#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbport.h"
#include "BSP_uart.h"
/* ----------------------- static functions ---------------------------------*/
 void prvvUARTTxReadyISR( void );
 void prvvUARTRxISR( void );

/* ----------------------- Start implementation -----------------------------*/
void 
vMBPortSerialEnable( BOOL xRxEnable, BOOL xTxEnable )
{
  if(xRxEnable)
  {
    UART_INT_EN_RX(2);
  }
  else
  {
		UART_INT_DISEN_RX(2);
  }
  if(xTxEnable)
  {
		UART_INT_EN_TX(2);
  }
	else
	{
		UART_INT_DISEN_TX(2);
	}
}

BOOL
xMBPortSerialInit( UCHAR ucPORT, ULONG ulBaudRate, UCHAR ucDataBits, eMBParity eParity )
{
	BSP_UartInit(ucPORT,ulBaudRate);
  return TRUE;
}

BOOL
xMBPortSerialPutByte( CHAR ucByte )
{
  UART2->UARTDR_b.DATA = ucByte;
  return TRUE;
}
BOOL
xMBPortSerialGetByte( CHAR * pucByte )
{
	static int num=0;
	(*pucByte) = (uint8_t)UART2->UARTDR_b.DATA;
  return TRUE;
}

/* Create an interrupt handler for the transmit buffer empty interrupt
 * (or an equivalent) for your target processor. This function should then
 * call pxMBFrameCBTransmitterEmpty( ) which tells the protocol stack that
 * a new character can be sent. The protocol stack will then call 
 * xMBPortSerialPutByte( ) to send the character.
 */
void 
prvvUARTTxReadyISR( void )
{
  pxMBFrameCBTransmitterEmpty(  );
}

/* Create an interrupt handler for the receive interrupt for your target
 * processor. This function should then call pxMBFrameCBByteReceived( ). The
 * protocol stack will then call xMBPortSerialGetByte( ) to retrieve the
 * character.
 */
void 
prvvUARTRxISR( void )
{
  pxMBFrameCBByteReceived(  );
	
}
/**
* @brief  This function handles UART1&2 interrupt requests.
* @param  None
* @retval None
*/
void UART12_IRQHandler(void){
	
	if(IS_INT_RX()){
		prvvUARTRxISR(); 
		CLR_INT_FLAG_RX();
	}
	if(IS_INT_TX())
  {
		prvvUARTTxReadyISR();
    CLR_INT_FLAG_TX();
	}

}