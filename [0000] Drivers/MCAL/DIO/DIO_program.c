/*
 * DIO_program.c
 *
 * Created: 9/30/2024 7:10:57 PM
 *  Author: Khalid Metwally
 *   Layer: MCAL
 *	   SWC: DIO/GPIO
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"


/*
================================I/O PIN Functions================================
*/

/*
 * Brief : This Function set the DIRECTION of the Pin  (INPUT || OUTPUT)
 * Parameters :
  	  =>Copy_u8PORT		--> Port Name		[ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN		--> Pin Number		[ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>Copy_u8Direction--> Pin Direction	[ DIO_PIN_OUTPUT , DIO_PIN_INPUT ]
 * return : its status
 */
DIO_ErrorStatus DIO_enumSetPinDirection (u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Direction)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	return LOC_enumState ;
}
/*
 * Brief : This Function set the VALUE of the Pin  (HIGH || LOW)
 * Parameters :
  	  =>Copy_u8PORT		--> Port Name		[ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN		--> Pin Number		[ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>Copy_u8Direction--> Pin Direction	[ DIO_PIN_OUTPUT , DIO_PIN_INPUT ]
 * return : its status
 */
DIO_ErrorStatus DIO_enumSetPinValue		(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Value)
{
		DIO_ErrorStatus LOC_enumState = DIO_OK;
		
		return LOC_enumState ;
}

DIO_ErrorStatus DIO_enumGetPinValue		(u8 Copy_u8PORT,u8 Copy_u8PIN,u8*Copy_PtrData)
{
		DIO_ErrorStatus LOC_enumState = DIO_OK;
		
		return LOC_enumState ;
}

DIO_ErrorStatus DIO_enumTogglePinValue	(u8 Copy_u8PORT,u8 Copy_u8PIN){
		DIO_ErrorStatus LOC_enumState = DIO_OK;
		
		return LOC_enumState ;
}