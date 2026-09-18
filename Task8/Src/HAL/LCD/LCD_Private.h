#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

#define Lcd_4bitMode 0
#define Lcd_8bitMode 1
#define Lcd_ClearScreen 0x01



#define Lcd_8bitMode2Line5x8F 0x38
#define Lcd_8bitMode2Line5x11F 0x3c
#define Lcd_4bitMode2Line5x8F  0x28
#define Lcd_4bitMode2Line5x11F  0x2C


#define Lcd_DisplayOff 0x08
#define Lcd_DisplayOn 0x0C
#define Lcd_CursorOn 0x0E
#define Lcd_CursorBlink 0x0F

#define Lcd_EntryMode1 0x06
#define Lcd_EntryMode2 0x04//no shift , cursor left
#define Lcd_EntryMode3 0x05//shift right
#define Lcd_EntryMode4 0x07//shft left 




#endif