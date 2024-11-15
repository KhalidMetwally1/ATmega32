/*
 * KPD_interface.h
 *
 *  Author: Khalid Metwally
 *   Layer: HAL
 *	   SWC: KPD
 */
#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

 #define NOTPRESSED 0xff

 void KPD_voidInit(void);		/* OR use PORT Driver	*/
 u8   KPD_u8GetPressed( void );	/* Gets the pressed key */
 
#endif
