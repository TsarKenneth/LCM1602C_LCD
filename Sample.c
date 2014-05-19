/**************************************************************
 * Sample.c
 *
 * Author:	Kenneth Wong
 * Email:	kenneth.wongwx@gmail.com
 * Version:	1.0
 *
 * - Description -
 * This is a sample of how the library is used.
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

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "LCM1602C.h"

#define TRUE 1
#define FALSE 0

int main(void)
{
	DDRA |= 0xFF;
	DDRB |= 0xE0;
	InitLCD(FALSE, FALSE);
	
	char msg1[] = {'H', 'e', 'l', 'l', 'o',};
	char msg2[] = {'W', 'o', 'r', 'l', 'd', '!'};
	
	while(1)
    {
		WriteLine(msg1, 5, 1);
		_delay_ms(1000);
		WriteLine(msg1, 5, 2);
		_delay_ms(1000);
		WriteLines(msg1, 5, msg2, 6);
    }
}
