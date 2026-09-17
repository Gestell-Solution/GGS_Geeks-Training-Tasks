#ifndef _KPD_INTERFACE_H
#define _KPD_INTERFACE_H
#include <stdint.h>
#include "../../MCAL/DIO/DIO_Interface.h"
#include"../../LIB/Definition.h"
#include"../../LIB/Bitmath.h"
#include "KPD_Private.h"
#include "KPD_Config.h"

void KeyPad_Init();
uint8_t KeyPad_Getpressedkey();



#endif