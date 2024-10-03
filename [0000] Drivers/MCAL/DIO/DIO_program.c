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
==============================================I/O PIN-CONTROL Functions==============================================
*/

/*
 * Brief : This Function Sets the DIRECTION of the pin (INPUT || OUTPUT) by manipulating Data Direction Register - DDRx
 * Parameters :
  	  =>Copy_u8PORT		--> Port Name		[ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN		--> Pin Number		[ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>Copy_u8Direction--> Pin Direction	[ DIO_PIN_OUTPUT , DIO_PIN_INPUT ]
 * return : its status
 */
DIO_ErrorStatus DIO_enumSetPinDirection (u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Direction)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	
	/* Validation: 1) PORT=[0:3] 2) PIN=[0:7] */
	if ( (Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7) )
	{
		if (Copy_u8Direction == DIO_PIN_OUTPUT)
		{
			switch (Copy_u8PORT)
			{
				case DIO_PORTA: SET_BIT(DDRA_Register,Copy_u8PIN);
								break;
				case DIO_PORTB: SET_BIT(DDRB_Register,Copy_u8PIN);
								break;
				case DIO_PORTC: SET_BIT(DDRC_Register,Copy_u8PIN);
								break;
				case DIO_PORTD: SET_BIT(DDRD_Register,Copy_u8PIN);
								break;
			}
		}
		else if(Copy_u8Direction == DIO_PIN_INPUT)
		{
			switch(Copy_u8PORT)
			{
				case DIO_PORTA: CLR_BIT(DDRA_Register,Copy_u8PIN);
								break;
				case DIO_PORTB: CLR_BIT(DDRB_Register,Copy_u8PIN);
								break;
				case DIO_PORTC: CLR_BIT(DDRC_Register,Copy_u8PIN);
								break;
				case DIO_PORTD: CLR_BIT(DDRD_Register,Copy_u8PIN);
								break;
			}
		}
		else
		{
			LOC_enumState = DIO_NOK;
		}
	}
	
	else
	{
		LOC_enumState = DIO_NOK;
	}
	
	return LOC_enumState;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Brief : This Function Sets the VALUE of the OUTPUT Pin (HIGH || LOW) by manipulating PORTx Register
 * Parameters :
  	  =>Copy_u8PORT		--> Port Name		[ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN		--> Pin Number		[ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>Copy_u8Direction--> Output Value	[ DIO_PIN_HIGH , DIO_PIN_LOW ]
 * return : its status
 */
DIO_ErrorStatus DIO_enumSetPinValue		(u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Value)
{
		DIO_ErrorStatus LOC_enumState = DIO_OK;
		/* Validation: 1) PORT=[0:3] 2) PIN=[0:7] */
		if ( (Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7) )
		{	
			if (Copy_u8Value == DIO_PIN_HIGH)
			{
				switch (Copy_u8PORT)
				{
					case DIO_PORTA: SET_BIT(PORTA_Register,Copy_u8PIN);
									break;
					case DIO_PORTB: SET_BIT(PORTB_Register,Copy_u8PIN);
									break;
					case DIO_PORTC: SET_BIT(PORTC_Register,Copy_u8PIN);
									break;
					case DIO_PORTD: SET_BIT(PORTD_Register,Copy_u8PIN);
									break;
				}
			}
			else if(Copy_u8Value == DIO_PIN_LOW)
			{
				switch(Copy_u8PORT)
				{
					case DIO_PORTA: CLR_BIT(PORTA_Register,Copy_u8PIN);
									break;
					case DIO_PORTB: CLR_BIT(PORTB_Register,Copy_u8PIN);
									break;
					case DIO_PORTC: CLR_BIT(PORTC_Register,Copy_u8PIN);
									break;
					case DIO_PORTD: CLR_BIT(PORTD_Register,Copy_u8PIN);
									break;
				}
			}
			else
			{
				LOC_enumState = DIO_NOK;
			}
		}
		
		else
		{
			LOC_enumState = DIO_NOK;
		}
		
		return LOC_enumState;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Brief : This Function Gets the VALUE of the INPUT Pin (HIGH || LOW) by storing it using a given Pointer
 * Parameters :
  	  =>Copy_u8PORT		--> Port Name		[ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN		--> Pin Number		[ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>u8*Copy_PtrData --> Pointer used to store the pin value
 * return : its status
 */
DIO_ErrorStatus DIO_enumGetPinValue		(u8 Copy_u8PORT,u8 Copy_u8PIN,u8*Copy_PtrData)
{
		DIO_ErrorStatus LOC_enumState = DIO_OK;
		/* Validation: 1) PORT=[0:3] 2) PIN=[0:7] */
		if ( (Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7) )
		{
			switch(Copy_u8PORT)
			{
				case DIO_PORTA: *Copy_PtrData = GET_BIT(PINA_Register,Copy_u8PIN);
								break;
				case DIO_PORTB: *Copy_PtrData = GET_BIT(PINB_Register,Copy_u8PIN);
								break;
				case DIO_PORTC: *Copy_PtrData = GET_BIT(PINC_Register,Copy_u8PIN);
								break;
				case DIO_PORTD: *Copy_PtrData = GET_BIT(PIND_Register,Copy_u8PIN);
								break;
			}
		}
		
		else
		{
			LOC_enumState = DIO_NOK;
		}
		
		return LOC_enumState;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Brief : This Function Toggles the VALUE of the OUTPUT Pin by manipulating PORTx Register
 * Parameters :
  	  =>Copy_u8PORT		--> Port Name		[ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN		--> Pin Number		[ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
 * return : its status
 */
DIO_ErrorStatus DIO_enumTogglePinValue	(u8 Copy_u8PORT,u8 Copy_u8PIN){
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	/* Validation: 1) PORT=[0:3] 2) PIN=[0:7] */
	if( (Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7) )
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA: TOG_BIT(PORTA_Register,Copy_u8PIN);
							break;
			case DIO_PORTB: TOG_BIT(PORTB_Register,Copy_u8PIN);
							break;
			case DIO_PORTC: TOG_BIT(PORTC_Register,Copy_u8PIN);
							break;
			case DIO_PORTD: TOG_BIT(PORTD_Register,Copy_u8PIN);
							break;
		}
	}
	
	else
	{
		LOC_enumState = DIO_NOK;	
	}
	
	return LOC_enumState;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Brief : This Function connected internal pull up
 * Parameters :
  	  =>Copy_u8PORT --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>Copy_u8PIN  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
 	  =>Copy_u8ConnectPullup --> [DIO_PIN_HIGH , DIO_PIN_LOW ]
 * return : its status
 */
DIO_ErrorStatus DIO_enumConnectPullup (u8 Copy_u8PORT ,u8 Copy_u8PIN, u8 Copy_u8ConnectPullup)
{

	DIO_ErrorStatus LOC_enumState = DIO_OK ;

	if ((Copy_u8PORT <= DIO_PORTD) && (Copy_u8PIN <= DIO_PIN7))
	{
		switch(Copy_u8PORT)
		{
		/* Connect or disconnect the pull up resistance to the given pin in port A */
		case DIO_PORTA:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRA_Register,Copy_u8PIN);
				SET_BIT(PORTA_Register,Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTA_Register,Copy_u8PIN);
			}
			break;
			/* Connect or disconnect the pull up resistance to the given pin in port B */
		case DIO_PORTB:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRB_Register,Copy_u8PIN);
				SET_BIT(PORTB_Register,Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTB_Register,Copy_u8PIN);
			}
			break;
			/* Connect or disconnect the pull up resistance to the given pin in port C */
		case DIO_PORTC:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRC_Register,Copy_u8PIN);
				SET_BIT(PORTC_Register,Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTC_Register,Copy_u8PIN);
			}
			break;
			/* Connect or disconnect the pull up resistance to the given pin in port D */
		case DIO_PORTD:
			if(Copy_u8ConnectPullup==DIO_PIN_HIGH)
			{
				CLR_BIT(SFIOR,PUD);
				CLR_BIT(DDRD_Register,Copy_u8PIN);
				SET_BIT(PORTD_Register,Copy_u8PIN);
			}
			else
			{
				CLR_BIT(PORTD_Register,Copy_u8PIN);
			}
			break;
		}
	}

	else
	{
		LOC_enumState = DIO_NOK ;
	}

	return LOC_enumState ;
}


/*
==============================================I/O PORT-CONTROL Functions==============================================
*/

/*
 * Brief : This Function Set the direction of the whole Port (INPUT / OUTPUT) by manipulating all the 8-bits of Data Direction Register - DDR
 * Parameters :
 	  =>Copy_u8PORT		--> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 	  =>Copy_u8Direction--> Port direction [ DIO_PORT_OUTPUT"0xFF" , DIO_PORT_INPUT"0x00" ]
 * return :  its status
 */
DIO_ErrorStatus DIO_enumSetPortDirection (u8 Copy_u8PORT,u8 Copy_u8Direction)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	/* Validation: PORT=[0:3] */
	if(Copy_u8PORT <= DIO_PORTD)
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA: DDRA_Register = Copy_u8Direction;
							break;
			case DIO_PORTB: DDRB_Register = Copy_u8Direction;
							break;
			case DIO_PORTC: DDRC_Register = Copy_u8Direction;
							break;
			case DIO_PORTD: DDRD_Register = Copy_u8Direction;
							break;
		}
	}
	
	else
	{
		LOC_enumState = DIO_NOK;
	}
	
	return LOC_enumState;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Brief : This Function Set value on the whole Port (HIGH / LOW / Another Value) by writing on all the 8-bits of PORT Register
 * Parameters :
  	  =>Copy_u8PORT	--> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 	  =>Copy_u8Value--> The Value  [DIO_PORT_HIGH"0xFF" , DIO_PORT_LOW"0x00" , Another Value]
 * return : its status
 */
DIO_ErrorStatus DIO_enumSetPortValue	 (u8 Copy_u8PORT,u8 Copy_u8Value)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	/* Validation: PORT=[0:3] */
	if (Copy_u8PORT <= DIO_PORTD)
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA: DDRA_Register = Copy_u8Value;
							break;
			case DIO_PORTB: DDRB_Register = Copy_u8Value;
							break;
			case DIO_PORTC: DDRC_Register = Copy_u8Value;
							break;
			case DIO_PORTD: DDRD_Register = Copy_u8Value;
							break;
		}
	}
	
	else
	{
		LOC_enumState = DIO_NOK;
	}
	
	return LOC_enumState;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Brief : This Function GET value that INPUTS in the whole PORT by reading all the 8-bits from PIN Register
 * Parameters :
 	  => Copy_u8PORT	--> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 	  => *Copy_PtrData	--> pointer to recieve the port value
 * return : its status and receive Port Value in pointer
 */
DIO_ErrorStatus DIO_enumGetPortValue	 (u8 Copy_u8PORT,u8*Copy_PtrData)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	/* Validation: PORT=[0:3] */
	if (Copy_u8PORT <= DIO_PORTD)
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA: *Copy_PtrData = PINA_Register;
							break;
			case DIO_PORTB: *Copy_PtrData = PINB_Register;
							break;
			case DIO_PORTC: *Copy_PtrData = PINC_Register;
							break;
			case DIO_PORTD: *Copy_PtrData = PIND_Register;
							break;
		}
	}
	
	else
	{
		LOC_enumState = DIO_NOK;
	}
	
	return LOC_enumState;
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------*/
/*
 * Brief : This Function Toggle value on whole OUTPUT Port
 * Parameters :
 	  =>Copy_u8PORT --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 * return : its status
 */
DIO_ErrorStatus DIO_enumTogglePortValue	 (u8 Copy_u8PORT)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	/* Validation: PORT=[0:3] */
	if (Copy_u8PORT <= DIO_PORTD)
	{
		switch(Copy_u8PORT)
		{
			case DIO_PORTA: PORTA_Register = ~PORTA_Register;
							break;
			case DIO_PORTB: PORTB_Register = ~PORTB_Register;
							break;
			case DIO_PORTC: PORTC_Register = ~PORTC_Register;
							break;
			case DIO_PORTD: PORTD_Register = ~PORTD_Register;
							break;
		}
	}
	
	else
	{
		LOC_enumState = DIO_NOK;
	}
	
	return LOC_enumState;
}


/*
==============================================I/O NIBBLE-CONTROL Functions==============================================
*/

/*
 * Brief : This Function write value on high nibbles of the Port (0000 #### / 1111 ####) 
 * Parameters :
 	  =>Copy_u8PORT  --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 	  =>Copy_u8value --> to set its high bits on high nibble of register
 * return : its status
 *
 *Hint1 : High Nibbles = Most Pins [4:7]
 *Hint2 : This Function takes the first 4 bits from the Copy_u8Value (#) => (xxxx ####) AND put it in high nibbles
 *
 */

DIO_ErrorStatus DIO_voidWriteHighNibbles (u8 Copy_u8PORT,u8 Copy_u8Value)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	/* Validation: PORT=[0:3] */
	if(Copy_u8PORT <= DIO_PORTD)
	{
			Copy_u8Value = (Copy_u8Value<<4) ;		/* Validate Value: if in=(#### 0101) --> out: (0101 0000) */
			switch(Copy_u8PORT)
			{
				case DIO_PORTA:	PORTA_Register &= 0x0f;				/* Validate PORT: if port=(#### ####) --> out: (0000 ####) */
								PORTA_Register |= Copy_u8Value;		/* Write Value  : port(0000 ####) | value(0101 0000) --> port = (0101 ####) */
								break;
				case DIO_PORTB:	PORTB_Register &= 0x0f;				
								PORTB_Register |= Copy_u8Value;		
								break;
				case DIO_PORTC:	PORTC_Register &= 0x0f;
								PORTC_Register |= Copy_u8Value;
								break;
				case DIO_PORTD:	PORTC_Register &= 0x0f;
								PORTC_Register |= Copy_u8Value;
								break;
			}
	}
	
	else
	{
		LOC_enumState = DIO_NOK;
	}
	
	return LOC_enumState;
}

/*
 * Brief : This Function write value on low nibbles of the Port (#### 0000 / #### 1111) 
 * Parameters :
 	  =>Copy_u8PORT  --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 	  =>Copy_u8value --> to set its low bits on low nibble of register
 * return : its status
 *
 *Hint1 : LOW Nibbles = Least Pins [4:7]
 *Hint2 : This Function also takes the first 4 bits from the Copy_u8Value (#) => (xxxx ####) AND put it in low nibbles
 *
 */

DIO_ErrorStatus DIO_voidWriteLowNibbles	 (u8 Copy_u8PORT,u8 Copy_u8Value)
{
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	/* Validation: PORT=[0:3] */
	if(Copy_u8PORT <= DIO_PORTD)
	{
			Copy_u8Value &= 0x0f;		/* Validate Value: if in=(#### 0101) --> out: (0000 0101) */
			switch(Copy_u8PORT)
			{
				case DIO_PORTA:	PORTA_Register &= 0xf0;				/* Validate PORT: if port=(#### ####) --> out: (#### 0000) */
								PORTA_Register |= Copy_u8Value;		/* Write Value  : port(#### 0000) | value(0000 0101) --> port = (#### 0101) */
								break;
				case DIO_PORTB:	PORTB_Register &= 0xf0;				
								PORTB_Register |= Copy_u8Value;		
								break;
				case DIO_PORTC:	PORTC_Register &= 0xf0;
								PORTC_Register |= Copy_u8Value;
								break;
				case DIO_PORTD:	PORTC_Register &= 0xf0;
								PORTC_Register |= Copy_u8Value;
								break;
			}
	}
	
	else
	{
		LOC_enumState = DIO_NOK;
	}
	
	return LOC_enumState;
}


/*
==============================================END==============================================
*/