/*******************************************************************
 *  FILE DESCRIPTION
-----------------------
 *  File:  _MAIN_H_
 *  Module:  APP
 *  Description:  Application Header FILE
*******************************************************************/
#ifndef _MAIN_H_
#define _MAIN_H_
/*****************************************
-----------     INCLUDES     -------------
*****************************************/
#include "NVIC_Interface.h"
#include "GPIO_Interface.h"
#include "GPT_Interface.h"
#include "RCC_Interface.h"
/*****************************************
-------   FUNCTIONS PROTOTYPES   ---------
*****************************************/
void Timer_ISR(void);
void System_Initialization(void);
/*****************************************
--------------   MACROS   ----------------
*****************************************/
#define Delay_Time_ms									(10000)
#define Led_On												(1)
#define Led_Off												(0)
/*****************************************
--------------- GLOBAL DATA  -------------
*****************************************/
static u32 Global_u32On_Time_ms,Global_u32Off_Time_ms;
static u8 Global_u8Initial_State=Led_Off;
#endif
/********************************************************************
 *  END OF FILE: Main.h
********************************************************************/	
