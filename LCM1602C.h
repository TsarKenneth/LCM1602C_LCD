/**************************************************************
 * LCM1602C.h
 *
 * Author:	Kenneth Wong
 * Email:	kenneth.wongwx@gmail.com
 * Version:	1.1
 *
 * - Description -
 * This library is created for LCM1602C Liquid Crystal Display
 * (LCD) and verified on Atmel Atmega 2560 micro controller.
 *
 * - Copyrights and Permissions -
 * Author retains all intellectual property (IP) rights to this 
 * document. Users, however, have the permission to use, modify 
 * and/or distribute this document for any non-commercial 
 * purposes. Please retain this credit during use. If in doubt, 
 * please feel free to contact the author at the e-mail address 
 * provided above.
 *
 * Finally, have fun with it! :)
 ***************************************************************/ 

#ifndef _LCM1620C_H_
#define _LCM1620C_H_

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "LCM1602C.h"
                         
#define LATCH {PORTB |= 0x20; _delay_us(1); PORTB &= ~(0x20); _delay_us(50);}
#define WRITE {PORTB &= ~(0xC0); PORTB |= 0x80;}
#define CONTROL {PORTB &= ~(0xC0);}
#define LINE_1 {PORTA = 0x80; LATCH;}
#define LINE_2 {PORTA = 0xC0; LATCH;}

void ClearDisplay();
void InitLCD(int, int);
void WriteLine(char*, int, int);
void WriteLines(char*, int, char*, int);
void CarriageReturn();

void ClearDisplay()
{
	CONTROL;
	PORTA = 0x01;
	LATCH;
	_delay_us(500);
}
void InitLCD(int cursor, int blink)
{
	/****Init IO****/
	DDRA |= 0xFF;
	DDRB |= 0xE0;
	
	/****Init MAIN****/
	_delay_ms(40);
	// Function Set
	CONTROL;
	PORTA = 0b00110000;
	LATCH;
	_delay_ms(5);
	LATCH;
	_delay_us(100);
	LATCH;
	
	// Function Set
	PORTA = 0b00111100;
	LATCH;
	// Display Off
	PORTA = 0b00001000;
	LATCH;
	// Display Clear
	ClearDisplay();
	// Entry Mode Set
	PORTA = 0b00000110;
	LATCH;
	_delay_ms(1);
	
	/****Init MISC****/
	// Display ON Control
	PORTA = 0b00001100;
	if (cursor == 1)
	{
		PORTA |= 0x02;
	}
	if (blink == 1)
	{
		PORTA |= 0x01;
	}
	LATCH;
}
void WriteLine(char* LnMsg, int CharCnt, int LineNum)
{
	int i;
	CONTROL;
	switch (LineNum)
	{
		case 1:
		LINE_1;
		break;
		case 2:
		LINE_2;
		break;
		default:
		return;
	}
	
	WRITE;
	for (i=0; i<CharCnt; i++)
	{
		PORTA = LnMsg[i];
		LATCH;
	}
}
void WriteLines(char* Ln1Msg, int CharCnt1,
				char* Ln2Msg, int CharCnt2)
{
	int i;
	CONTROL;
	LINE_1;
	WRITE;
	for (i=0; i<CharCnt1; i++)
	{
		PORTA = Ln1Msg[i];
		LATCH;
	}
	
	CONTROL;
	LINE_2;
	WRITE;
	for (i=0; i<CharCnt2; i++)
	{
		PORTA = Ln2Msg[i];
		LATCH;
	}
}
void CarriageReturn()
{
	CONTROL;
	PORTA = 0x20;
	LATCH;
}

#endif /* _LCM1620C_H_ */
