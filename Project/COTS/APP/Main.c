/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  Main_Program.c
 *  Brief:  Blink LED With Timer
 *  Description:  Logic C File For Main Module
*******************************************************************/
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "Main.h"
/*****************************************
----------    GLOBAL DATA     ------------
*****************************************/
/********************************************************************
* Syntax          : int main(void)
* Description     : Main Function
********************************************************************/
int main(void)
{
	Global_u32On_Time_ms=10000;
	Global_u32Off_Time_ms=1000;
	System_Initialization();
	GPT_VidTimer_0_A_ISR(Timer_ISR);
	while(TRUE){}//Busy_Wait
}
/********************************************************************
* Syntax          : void System_Initialization(void)
* Description     : System Initialization Function
********************************************************************/
void System_Initialization(void)
{
	RCC_VidClock_Enable(RCC_GPIO,Port_A,Enable);
	RCC_VidClock_Enable(RCC_GPT,Timer_0,Enable);
	GPIO_VidMode_Pin(Port_A,Pin_0,GPIO_Output);
	GPT_VidTimer_0_Delay_ms(Global_u32Off_Time_ms,GPT_Interrupt_Enable);
	NVIC_VidInterrupt_Peripheral_Set(GPT_0_A,NVIC_Enable,NVIC_GROUP_0,NVIC_SUP_GROUP_0);
}
/********************************************************************
* Syntax          : void Timer_ISR(void)
* Description     : Timer Interrupt Service routine
********************************************************************/
void Timer_ISR(void)
{
	switch(Global_u8Initial_State)
	{
		case(Led_Off):
			Global_u8Initial_State=Led_On;
			GPIO_VidPin_Set(Port_A,Pin_0,Hi);
			GPT_VidTimer_0_Delay_ms(Global_u32On_Time_ms,GPT_Interrupt_Enable);
		break;
		case(Led_On):
			Global_u8Initial_State=Led_Off;
			GPIO_VidPin_Set(Port_A,Pin_0,Low);
			GPT_VidTimer_0_Delay_ms(Global_u32Off_Time_ms,GPT_Interrupt_Enable);
		break;
	}
}
