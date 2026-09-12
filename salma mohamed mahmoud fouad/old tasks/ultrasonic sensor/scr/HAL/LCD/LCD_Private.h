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

#define LCD_4bitMode 0
#define LCD_8bitMode 1
#define LCD_ClearScreen 0x01

#define LCD_8bitMode2Line5x8f 0x38

#define LCD_DisplayOff 0x08
#define LCD_DisplayON 0x0C
#define LCD_CursorON 0x0E
#define LCD_BlinkingON 0x0F

#define entrymodeR 0x04
#define entrymodeL 0x07
#define entrymodeI_D 0x06
#define entrymodeS 0x05


#endif 