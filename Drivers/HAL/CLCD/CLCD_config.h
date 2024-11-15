/*
 * CLCD_config.h
 *
 *  Author: Khalid Metwally
 *   Layer: HAL
 *	   SWC: CLCD
 */
#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

/*
	[CLCD MODES]
	1. 4-bit Connection: 4
	2. 8-bit Connection: 8
*/
#define CLCD_MODE  4

/*
	[DATA PORT D0 -> D7]
	1. DIO_PORTA
	2. DIO_PORTB
	3. DIO_PORTC
	4. DIO_PORTD
*/
#define CLCD_DATA_PORT      DIO_PORTA

/*
	[CONTROL PINS PORT RS,RW,EN]
*/
#define CLCD_CONTROL_PORT   DIO_PORTB
/*
	[CONTROL PINS RS,RW,EN]
	1. DIO_PIN0
	2. DIO_PIN1
	3. DIO_PIN2
	4. DIO_PIN3
	5. DIO_PIN4
	6. DIO_PIN5
	7. DIO_PIN6
	8. DIO_PIN7
*/
#define CLCD_RS             DIO_PIN1
#define CLCD_RW             DIO_PIN2
#define CLCD_EN             DIO_PIN3
 
#endif