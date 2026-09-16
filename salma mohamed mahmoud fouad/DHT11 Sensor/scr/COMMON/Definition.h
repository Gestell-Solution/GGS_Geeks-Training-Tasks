/**
 * @file Definition.h
 * @author salma mohamed mahmoud fouad(salmafouadothman@gmail.com)
 * @brief   this file have every single macro that i can use in any file
 * @details we have input output,high low,disable enable,off on,null nullchar flagup flag down,
 * clear regester, cpu frequency 
 * @version 0.1
 * @date 2026-09-16
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef _DEFINITION_H
#define _DEFINITION_H 

#define Input   0 
#define Output  1 

#define Low     0 
#define High    1 

#define Disable 0 
#define Enable  1

#define Off     0 
#define On      1 

#define Null      (void*)0x00 
#define NullChar    '\0'
#define FlagUp       1 
#define FlagDown     0 


#define ClearRegister 0x00

#define FCPU     8000000UL

#endif 