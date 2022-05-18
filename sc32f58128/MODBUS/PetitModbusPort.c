//#include "General.h"
#include "PetitModbus.h"
#include "PetitModbusPort.h"

// This port file for PIC microcontrollers!

// Modbus RTU Variables
volatile unsigned char   PetitReceiveBuffer[PETITMODBUS_RECEIVE_BUFFER_SIZE];   // Buffer to collect data from hardware
volatile unsigned char   PetitReceiveCounter=0;                                 // Collected data number

// UART Initialize for Microconrollers, yes you can use another phsycal layer!
void PetitModBus_UART_Initialise(void)
{
// Insert UART Init Code Here
	BSP_UartInit(2,115200);
    //InitUART();
}

// Timer Initialize for Petit Modbus, 1ms Timer will be good for us!
void PetitModBus_TIMER_Initialise(void)
{
	mg_TimerInit();
   // Insert TMR Init Code Here
   // InitTMR1();
}



//// This is used for send string, better to use DMA for it ;)
unsigned char PetitModBus_UART_String(unsigned char *s, unsigned int Length){
	
	UART_SendArray(UART2,s,Length);
//    unsigned short  DummyCounter;
//    
//    for(DummyCounter=0;DummyCounter<Length;DummyCounter++)
//        PetitModBus_UART_Putch(s[DummyCounter]);
	return TRUE;
}

/*************************Interrupt Fonction Slave*****************************/
// Call this function into your UART Interrupt. Collect data from it!
// Better to use DMA
void ReceiveInterrupt(unsigned char Data)
{
    PetitReceiveBuffer[PetitReceiveCounter]   =Data;
    PetitReceiveCounter++;

    if(PetitReceiveCounter>PETITMODBUS_RECEIVE_BUFFER_SIZE)  
        PetitReceiveCounter=0;

    PetitModbusTimerValue=0;
}

// Call this function into 1ms Interrupt or Event!
void PetitModBus_TimerValues(void)
{
    PetitModbusTimerValue++;
}
/******************************************************************************/



