/*
 * TOGGLE.c
 *
 * Created: 14-10-2026 20:00:33
 * Author : roshn
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>

void gpio_init()
{
	DDRB |= (1 << DDB5);      // PB5 as output
	DDRB &= ~(1 << DDB0);     // PB0 as input
}

int main(void)
{
	gpio_init();

	while (1)
	{
		if (PINB & (1 << PINB0))
		{
			PORTB ^= (1 << PORTB5);  // Toggle LED

			while (PINB & (1 << PINB0))
			{
				// Wait until switch is released
			}
		}
	}
}