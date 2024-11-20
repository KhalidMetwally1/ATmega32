/******************************************************************************/
/*                                                                            */
/* !Layer           : Application Layer                                       */
/*                                                                            */
/* !Component       : main                                                    */
/* !Description     : Application Entry Point                                 */
/*                                                                            */
/* !File            : mian.c                                                  */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !LAB				: LM35 Sensor and CLCD									  */
/*                                                                            */
/* !Target          : ATMega32                                                */
/*                                                                            */
/* !Compiler        : AVR GCC Cross Compiler                                  */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/*                                                                            */
/* !Designed by     : Khalid Metwally                    !Date : NOV 11, 2024 */
/* !Coded by        : Khalid Metwally                    !Date : NOV 11, 2024 */
/*                                                                            */
/******************************************************************************/

/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "ADC_interface.h"
#include "DIO_interface.h"

/* HAL */
#include "CLCD_interface.h"
#include "LM35_interface.h"

LM35_CONFIG LM35={0,5,ADC_RESOLUTION_10_BIT};
	
int main(void)
{
	CLCD_voidInit();
	
    while (1) 
    {
    }
}

