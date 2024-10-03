/*
 * DIO_private.h
 *
 * Created: 9/30/2024 7:12:38 PM
 *  Author: Khalid Metwally
 *   Layer: MCAL
 *	   SWC: DIO/GPIO
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/* Group A Registers */
#define PORTA_Register	*((volatile u8)0x3B)
#define DDRA_Register	*((volatile u8)0x3A)
#define PINA_Register	*((volatile u8)0x39)

/* Group B Registers */
#define PORTB_Register	*((volatile u8)0x38)
#define DDRB_Register	*((volatile u8)0x37)
#define PINB_Register	*((volatile u8)0x36)

/* Group C Registers */
#define PORTC_Register	*((volatile u8)0x35)
#define DDRC_Register	*((volatile u8)0x34)
#define PINC_Register	*((volatile u8)0x33)

/* Group D Registers */
#define PORTD_Register	*((volatile u8)0x32)
#define DDRD_Register	*((volatile u8)0x31)
#define PIND_Register	*((volatile u8)0x30)

/* Pull-Up */
#define SFIOR			*((volatile u8)0x50)

#endif /* DIO_PRIVATE_H_ */