/*
 * Toggle_Led_Using_avrio.c
 *
 * Created: 9/30/2024 5:35:22 PM
 * Author : Khalid Metwally
 */ 
#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>

int main()
{
	DDRA = 0b00000001 ;
	while(1)
	{
		PORTA ^= (1<<0);
		_delay_ms(1000);
	}
	return 0;
}