/*
 * KPD_program.c
 *
 *  Author: Khalid Metwally
 *   Layer: HAL
 *	   SWC: KPD
 */

#include <util/delay.h>

/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

/*=====================================================================================================================================*/
/*
 * Brief : This Function initialize the pin which connected to KPD as input pins
 * Parameters : Nothing
 * return : Nothing
 */
void KPD_voidInit(void)
{
	/* ROWS		-> INPUTS (Pull up) */
	DIO_enumConnectPullup(KPD_PORT, KPD_R0, DIO_PIN_HIGH);
	DIO_enumConnectPullup(KPD_PORT, KPD_R1, DIO_PIN_HIGH);
	DIO_enumConnectPullup(KPD_PORT, KPD_R2, DIO_PIN_HIGH);
	DIO_enumConnectPullup(KPD_PORT, KPD_R3, DIO_PIN_HIGH);
	
	/* COLUMNS	-> OUTPUT */
	DIO_enumSetPinDirection	(KPD_PORT, KPD_C0, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection	(KPD_PORT, KPD_C1, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection	(KPD_PORT, KPD_C2, DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection	(KPD_PORT, KPD_C3, DIO_PIN_OUTPUT);
	
	DIO_enumSetPinValue		(KPD_PORT, KPD_C0, DIO_PIN_HIGH	);
	DIO_enumSetPinValue		(KPD_PORT, KPD_C1, DIO_PIN_HIGH	);
	DIO_enumSetPinValue		(KPD_PORT, KPD_C2, DIO_PIN_HIGH	);
	DIO_enumSetPinValue		(KPD_PORT, KPD_C3, DIO_PIN_HIGH	);
}

/*=====================================================================================================================================*/
/*
 * Brief : This Function used to get the pressed button of the Keypad
 * Parameters : Nothing
 * return : the pressed button
 */

u8 KPD_u8GetPressed(void)
{
	u8 LOC_u8ReturnData = NOTPRESSED ;
	u8 LOC_u8GetPressed ; /* Holds value we read when we iterate on rows [0/1] */
	
	/* [iterators] */
	u8 LOC_u8Row ;
	u8 LOC_u8Col ;
	
	for ( LOC_u8Col = 0 + KPD_COL_INIT ; LOC_u8Col <= KPD_COL_END ; LOC_u8Col++ )
	{
		DIO_enumSetPinValue(KPD_PORT, LOC_u8Col, DIO_PIN_LOW); /* Output a low on Column */
		
		for ( LOC_u8Row = 0 + KPD_ROW_INIT ; LOC_u8Row <= KPD_ROW_END ; LOC_u8Row++ )
		{
			DIO_enumGetPinValue( KPD_PORT , LOC_u8Row , &LOC_u8GetPressed ); /* get the pressed value */
			
			if ( LOC_u8GetPressed == 0 )
			{
				_delay_ms(50); // delay to avoid bouncing
				DIO_enumGetPinValue( KPD_PORT , LOC_u8Row , &LOC_u8GetPressed ); /* get the pressed value */
				
				if ( LOC_u8GetPressed == 0 )
				{
					/* return value based on  KPD_u8Buttons Array*/
					LOC_u8ReturnData = KPD_u8Buttons[ LOC_u8Row - KPD_ROW_INIT ][ LOC_u8Col - KPD_COL_INIT ];
				}
				
				/* Stuck to taking values when the user is holding some button */
				/* START */
				DIO_enumGetPinValue( KPD_PORT , LOC_u8Row , &LOC_u8GetPressed );
				while( DIO_PIN_LOW == LOC_u8GetPressed ) /*  This cond for safty instead of (LOC_u8GetPressed == DIO_PIN_LOW) if i forget = */
				{
					DIO_enumGetPinValue( KPD_PORT , LOC_u8Row , &LOC_u8GetPressed );
				}
				break;
				/* END */
			}
		}
	DIO_enumSetPinValue(KPD_PORT, LOC_u8Col, DIO_PIN_HIGH); /* Output a high back on the Column */	
	}
	
	return LOC_u8ReturnData;
}