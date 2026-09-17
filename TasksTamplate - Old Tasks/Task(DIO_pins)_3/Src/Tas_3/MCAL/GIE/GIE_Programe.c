#include <stdint.h>
#include "GIE_Interface.h"
#include "../Atmega32regmap.h"


void GIE_Enable()
{
    SET_BIT(SREG,I_Bit);
}
void GIE_Disable()
{
    CLEAR_BIT(SREG,I_Bit);
}