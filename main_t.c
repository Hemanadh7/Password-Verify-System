#include <REG51.h>
#include "header.h"

#define keypad P1

void main()
{
	lcd_init();
	lcd_cmd(0x80);
	keypad=0xF0;
	while(1)
	{
		if(keypad==0xE0)
		{
			keypad=0xEF;
			while(1)
			{
				if(keypad==0xEE)
					lcd_data('1');
				delay_ms(40);
			}
		}
	}
}