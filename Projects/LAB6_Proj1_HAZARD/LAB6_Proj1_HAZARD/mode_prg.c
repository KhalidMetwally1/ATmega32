/******************************************************************************/
/*                                                                            */
/* !Layer           : Application Abstraction Layer                           */
/*                                                                            */
/* !Component       : MODE                                                    */
/* !Description     : Hazard Indicator Function module                       */
/*                                                                            */
/* !Module          : MODE                                                    */
/* !Description     : MODE Module interface                                   */
/*                                                                            */
/* !File            : mode_prg.c                                              */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Coding language : C                                                       */
/*                                                                            */
/* !Project         : Induction training exercise project                     */
/*                                                                            */
/* !Target          : ATMega32                                                */
/*                                                                            */
/* !Compiler        : AVR GCC Cross Compiler                                  */
/*                                                                            */
/*                                                                            */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/*                                                                            */
/* !Coded by        : Mahmoud Karem Zamel             !Date : NOV 21, 2023    */
/* !Student			: Khalid Metwally				  !Date : OCT 21, 2024    */
/*                                                                            */
/******************************************************************************/
#define F_CPU 8000000
#include "util/delay.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SW_interface.h"
#include "SSD_interface.h"
#include "CLCD_interface.h"

#include "mode_int.h"

/******************************************************************************/

MODE_enumModeState Mode_MyState;

u8 u8PreviousState = IDLE;

/*****************************************************************************************/
extern SSD_Type R_SSD ;
extern SSD_Type L_SSD ;

extern SW_Type R_SW ;
extern SW_Type L_SW ;
extern SW_Type H_SW ;
/*****************************************************************************************/

/******************************************************************************/
/*! \Description Helper Functions                                             */
/*! \return      None                                                         */
/*! \Trace_To                                                                 */
/******************************************************************************/
void APP_voidSetMode(MODE_enumModeState Copy_enumSetMode)
{
	switch(Copy_enumSetMode)
	{
	case IDLE:
		// SSD For IDLE
		SSD_voidDisable(R_SSD);
		SSD_voidDisable(L_SSD);
		// CLCD For IDLE
		CLCD_voidClearScreen();
		CLCD_voidSendString("IDLE MODE");
		
		break;

	case RIGHT_BLINK:
		// SSD For Right
		SSD_voidEnable(R_SSD);
		SSD_voidDisable(L_SSD);
		SSD_voidSendNumber(R_SSD,0);
		// CLCD For Right
		CLCD_voidClearScreen();
		CLCD_voidSendString("RIGHT MODE");
		
		break;

	case LEFT_BLINK:
		// SSD For Left
		SSD_voidDisable(R_SSD);
		SSD_voidEnable(L_SSD);
		SSD_voidSendNumber(L_SSD,0);
		// CLCD For Left
		CLCD_voidClearScreen();
		CLCD_voidSendString("LEFT MODE");

		break;

	case HAZZARD_BLINK:
		// SSD For Hazard
		SSD_voidEnable(R_SSD);
		SSD_voidEnable(L_SSD);
		SSD_voidSendNumber(R_SSD,0);
		SSD_voidSendNumber(L_SSD,0);
		// CLCD For Hazard
		CLCD_voidClearScreen();
		CLCD_voidSendString("HAZARD MODE");

		break;
	}

}

/***************************************/
void MODE_voidIdle (void)
{
	//Implementation
	u8PreviousState = Mode_MyState;
	Mode_MyState = IDLE;
	APP_voidSetMode(IDLE);
}
void MODE_voidRightBlink (void)
{
	//Implementation
	u8PreviousState = Mode_MyState;
	Mode_MyState = RIGHT_BLINK;
	APP_voidSetMode(RIGHT_BLINK);
}
void MODE_voidLeftBlink (void)
{
	//Implementation
	u8PreviousState = Mode_MyState;
	Mode_MyState = LEFT_BLINK;
	APP_voidSetMode(LEFT_BLINK);
}
void MODE_voidHazardBlink (void)
{
	//Implementation
	u8PreviousState = Mode_MyState;
	Mode_MyState = HAZZARD_BLINK;
	APP_voidSetMode(HAZZARD_BLINK);
}


/*****************************************************************************************/

/******************************************************************************/
/*! \Description Initialize the MODE driver variables                         */
/*! \return      None                                                         */
/*! \Trace_To                                                                 */
/******************************************************************************/
void MODE_voidInit(void)
{
	Mode_MyState  = IDLE;
	APP_voidSetMode(IDLE);
}

/******************************************************************************/
/*! \Description The MODE driver task, should be called periodically.
				 This service update the state of all configured push
                 buttons.                                                     */
/*! \return      None                                                         */
/*! \Trace_To                                                                 */
/******************************************************************************/
void MODE_voidTask(void)
{
	/* When pressing Right Switch */
	if ( SW_u8GetPressed(R_SW) )
	{
		_delay_ms(20);
		if (SW_u8GetPressed(R_SW))	/* Recheck to make sure it isn't bouncing */
		{
			switch (Mode_MyState)
			{
				case IDLE:			MODE_voidRightBlink();
									break;
				case RIGHT_BLINK:	MODE_voidRightBlink();
									break;
				case LEFT_BLINK:	MODE_voidIdle();
									break;
				case HAZZARD_BLINK: MODE_voidHazardBlink();
									break;
				
			}
		}
		while(SW_u8GetPressed(R_SW) ) /*  This condition makes switch stuck when pressed, Avoiding repetitive reading issue */
		{
			SW_u8GetPressed(R_SW);
		}
	}
	
	/* When pressing Left Switch */
	if ( SW_u8GetPressed(L_SW) )
	{
		_delay_ms(20);
		if ( SW_u8GetPressed(L_SW) )	/* Recheck to make sure it isn't bouncing */
		{
			switch (Mode_MyState)
			{
				case IDLE:			MODE_voidLeftBlink();
									break;
				case RIGHT_BLINK:	MODE_voidIdle();
									break;
				case LEFT_BLINK:	MODE_voidLeftBlink();
									break;
				case HAZZARD_BLINK: MODE_voidHazardBlink();
									break;
				
			}
			while(SW_u8GetPressed(L_SW) ) /*  This condition makes switch stuck when pressed, Avoiding repetitive reading issue */
			{
				SW_u8GetPressed(L_SW);
			}
		}
	}
	
	/* When pressing Right Switch -bouncing 20ms - "hello" and the last delay*/
	if ( SW_u8GetPressed(H_SW) )
	{
		_delay_ms(20);
		if ( SW_u8GetPressed(H_SW) )	/* Recheck to make sure it isn't bouncing */
		{
			if ( (Mode_MyState == IDLE) || (Mode_MyState == LEFT_BLINK) || (Mode_MyState == RIGHT_BLINK) )
			{
				MODE_voidHazardBlink();
			}
			else if (Mode_MyState == HAZZARD_BLINK)
			{
				switch(u8PreviousState)
				{
					case IDLE:			MODE_voidIdle();
										break;
					case RIGHT_BLINK:	MODE_voidRightBlink();
										break;
					case LEFT_BLINK:	MODE_voidLeftBlink();
										break;
					case HAZZARD_BLINK:	MODE_voidIdle();
										break;
				}
			}
			while(SW_u8GetPressed(H_SW) ) /*  This condition makes switch stuck when pressed, Avoiding repetitive reading issue */
			{
				SW_u8GetPressed(H_SW);
			}
		}
	}
}

/**********************************************************************************************/
