#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H




#define Lcd_4bitMode     0
#define Lcd_8bitMode     1
#define Lcd_ClearScreen   0x01
/*
FunctionSet ->  0 0 0 1 DL N F 0 0
                        1  1 0 
*/
#define Lcd_8bitMode2Line5x8F   0x38
/*
DisplayON/OFF
  00001DCB
*/
#define Lcd_DisplayOff     0x08  
#define Lcd_DisplayOn      0x0C
#define Lcd_CursorOn       0x0E
#define Lcd_CursorBlink    0x0F
//EntryMode
#define Lcd_EntryMode1     0x06



#endif