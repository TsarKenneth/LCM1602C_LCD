Author:		Kenneth Wong
Email:		kenneth.wongwx@gmail.com
Version:	1.0

- Description -
This AVR library is created for LCM1602C Liquid Crystal 
Display (LCD) and verified on Atmel Atmega 2560 micro 
controller. Port mappings are as follows:
	Atmega Port		| LCD Port
	-------------------------------
	PORT A [7:0]	| DB [7:0]
	PORT B [7]		| RS
	PORT B [6]		| R/W
	PORT B [5]		| E

- Copyrights and Permissions -
Author retains all intellectual property (IP) rights to this 
document. Users, however, have the permission to use, modify 
and/or distribute this document for any non-commercial 
purposes. Please retain this credit during use. If in doubt, 
please feel free to contact the author at the e-mail address 
provided above.
 
 Finally, have fun with it! :)
	
- Functions -
void ClearDisplay()
Clears the LCD display.

void CarriageReturn()
Returns cursor to its original position.

void InitLCD(int cursor, int blink)
Initializes LCD with options for cursor visibility and
cursor blink. Default value is 0. Enter 1 to enable each 
option.

void WriteLine(char* LnMsg, int CharCnt, int LineNum)
Writes "CharCnt" number of charaters from "LnMsg" to line 
"LineNum" of LCD screen.
Note: Only 1 line will be written on LCD screen.

void WriteLines(char* Ln1Msg, int CharCnt1,
		char* Ln2Msg, int CharCnt2)
Write CharCnt1 number of characters from "Ln1Msg" and 
CharCnt2 number of characters from "Ln2Msg" to lines 1
and 2 of LCD screen respectively.
