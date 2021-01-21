#include <REG51.h>
#include "header.h"

#define keypad P1

u8 GetKey()
{
	keypad=0xFF;
	while(1)
	{
		keypad=0xFE;
		if(keypad==0xEE)
			return '1';
		if(keypad==0xDE)
			return '2';
		if(keypad==0xBE)
			return '3';
		
		keypad=0xFD;
		if(keypad==0xED)
			return '4';
		if(keypad==0xDD)
			return '5';
		if(keypad==0xBD)
			return '6';
			
		keypad=0xFB;
		if(keypad==0xEB)
			return '7';
		if(keypad==0xDB)
			return '8';
		if(keypad==0xBB)
			return '9';
							
		keypad=0xF7;
		if(keypad==0xE7)
			return '*';
		if(keypad==0xD7)
			return '0';
		if(keypad==0xB7)
			return '#';
	}
}