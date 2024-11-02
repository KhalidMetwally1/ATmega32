/*
 * PORT_program.c
 *
 *  Author: Khalid Metwally
 *   Layer: MCAL
 *	   SWC: PORT
 */

/* LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_config.h"
#include "PORT_interface.h"
#include "PORT_private.h"

void PORT_voidInit(void)
{
	/* DIRECTIONS */
	DDRA_Register = PORTA_DIR;
	DDRB_Register = PORTB_DIR;
	DDRC_Register = PORTC_DIR;
	DDRD_Register = PORTD_DIR;
	
	/* INITIAL VALUES */
	PORTA_Register = PORTA_INITIAL_VALUE;
	PORTB_Register = PORTB_INITIAL_VALUE;
	PORTC_Register = PORTC_INITIAL_VALUE;
	PORTD_Register = PORTD_INITIAL_VALUE;
	
}