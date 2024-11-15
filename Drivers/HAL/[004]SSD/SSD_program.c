/*
 * SSD_program.c
 *
 *  Author: Khalid Metwally
 *   Layer: HAL
 *	   SWC: SSD
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

static u8 Local_u8SSDNumbers[10] = SSD_NUMBER_ARR ;

//====================================================================================================================================================
/*
 * Breif : This Function initialize the port which connected to 7 Seg leds as output pins ( 8 Pins or Port )
 * Parameters :
            =>Copy_u8PORT --> Port Name [ SSD_PORTA ,	SSD_PORTB , SSD_PORTC , SSD_PORTD ]
 * return : void
 */
void SSD_voidInitialDataPort  (SSD_Type Copy_SSDConfig )
{
	DIO_enumSetPortDirection    ( Copy_SSDConfig.DataPort , 0xFF );
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function write Number on 7 seg [ 0 : 9 ]
 * Parameters : => struct has the SSD type , data port and enable(port & pin)
 * return : void
 */
void SSD_voidSendNumber( SSD_Type Copy_SSDConfig , u8 Copy_u8Number ){

	if( Copy_SSDConfig.Type == SSD_COMMON_CATHODE ){

		DIO_enumSetPortValue( Copy_SSDConfig.DataPort , Local_u8SSDNumbers[ Copy_u8Number ] );

	}else if( Copy_SSDConfig.Type == SSD_COMMON_ANODE ){

		DIO_enumSetPortValue( Copy_SSDConfig.DataPort , ~( Local_u8SSDNumbers[ Copy_u8Number ] ) );

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function enable common pin
 * Parameters : => struct has the SSD type , data port and enable(port & pin)
 * return : void
 */
void SSD_voidEnable    ( SSD_Type Copy_SSDConfig ){

	if( Copy_SSDConfig.Type == SSD_COMMON_CATHODE ){

		DIO_enumSetPinDirection( Copy_SSDConfig.EnablePort , Copy_SSDConfig.EnablePin , DIO_PIN_OUTPUT );
		DIO_enumSetPinValue( Copy_SSDConfig.EnablePort , Copy_SSDConfig.EnablePin , DIO_PIN_LOW );

	}else if( Copy_SSDConfig.Type == SSD_COMMON_ANODE ){

		DIO_enumSetPinDirection( Copy_SSDConfig.EnablePort , Copy_SSDConfig.EnablePin , DIO_PIN_OUTPUT );
		DIO_enumSetPinValue( Copy_SSDConfig.EnablePort , Copy_SSDConfig.EnablePin , DIO_PIN_HIGH );

	}

}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function disable common pin
 * Parameters : => struct has the SSD type , data port and enable(port & pin)
 * return : void
 */
void SSD_voidDisable   ( SSD_Type Copy_SSDConfig ){

	if( Copy_SSDConfig.Type == SSD_COMMON_CATHODE ){

		DIO_enumSetPinDirection( Copy_SSDConfig.EnablePort , Copy_SSDConfig.EnablePin , DIO_PIN_OUTPUT );
		DIO_enumSetPinValue( Copy_SSDConfig.EnablePort , Copy_SSDConfig.EnablePin , DIO_PIN_HIGH );

	}
	else if( Copy_SSDConfig.Type == SSD_COMMON_ANODE ){

		DIO_enumSetPinDirection( Copy_SSDConfig.EnablePort , Copy_SSDConfig.EnablePin , DIO_PIN_OUTPUT );
		DIO_enumSetPinValue( Copy_SSDConfig.EnablePort , Copy_SSDConfig.EnablePin , DIO_PIN_LOW );

	}

}

//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    END    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

