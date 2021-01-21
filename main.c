#include <REG51.h>
#include "header.h"

#define keypad P1

void main()
{
	u8 key1,key2,i=0,j=0;
	s8 usrPass[5], pass[5];
	usrPass[4]=0;
	pass[4]=0;
	lcd_init();
	lcd_cmd(0x80);
	en_ext_interrupt();
	while(1)
	{
		for(i=0;i<4;i++)
		{
			pass[i]=eeprom_byte_read(0,i);
		}
		i=0;
		delay_ms(50);
		lcd_string("Enter password:");
		lcd_cmd(0xC0);
		while(i<4)
		{
			key1=GetKey();
			delay_ms(30);
			key2=GetKey();
			if(key1==key2 && i<4)
			{
				lcd_data(key1);
				usrPass[i]=key1;
				i++;
			}
		}
		i=0;
		delay_ms(50);
		while(i<4)
		{
			if(pass[i]!=usrPass[i])
			{
				lcd_cmd(0x1);
				lcd_cmd(0x80);
				lcd_string("Invalid pwd.");
				return;
			}
			i++;
		}
		delay_ms(100);
	}
}