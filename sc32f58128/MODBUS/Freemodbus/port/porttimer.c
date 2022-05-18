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
 * File: $Id: porttimer.c,v 1.1 2006/08/22 21:35:13 wolti Exp $
 */

#include "SC32F58128_timer.h"

/* ----------------------- Platform includes --------------------------------*/
#include "port.h"
/* ----------------------- Modbus includes ----------------------------------*/
#include "mb.h"
#include "mbport.h"
#include "devInit.h"
#include "osc.h"
/* ----------------------- static functions ---------------------------------*/
 void prvvTIMERExpiredISR( void );

/* ----------------------- Start implementation -----------------------------*/
BOOL
xMBPortTimersInit( USHORT usTim1Timerout50us )
{
	TIMER_TmrConfig(0,(usTim1Timerout50us*50),1);     // 50uS
	
  return TRUE;
}


 void vMBPortTimersEnable(  )
{
	TIMER0->COUNT=0;
	TIMER0->CTRL_b.ENABLE = 1;
	
}

 void vMBPortTimersDisable(  )
{
	TIMER0->COUNT=0;
	TIMER0->CTRL_b.ENABLE = 0;
}

/* Create an ISR which is called whenever the timer has expired. This function
 * must then call pxMBPortCBTimerExpired( ) to notify the protocol stack that
 * the timer has expired.
 */
void prvvTIMERExpiredISR( void )
{
    ( void )pxMBPortCBTimerExpired();
}
/**
* @brief  This function handles TIMER0 interrupt request.
* @param  None
* @retval None
*/

void TIMER0_IRQHandler(void)
{
	if(TIMER[0]->CTRL_b.OV==1){
		 prvvTIMERExpiredISR( );
     TIMER[0]->CTRL_b.OV = 0;
	}
}