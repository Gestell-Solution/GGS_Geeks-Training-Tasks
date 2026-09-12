#include "KPD_Interface.h"
#include <util/delay.h>
  

static uint8_t kpd_columnsGroup[kpd_ColumnsNo]={kpd_C0Group,kpd_C1Group,kpd_C2Group,kpd_C3Group};
static uint8_t kpd_columnsPin[kpd_ColumnsNo]={kpd_C0Pin,kpd_C1Pin,kpd_C2Pin,kpd_C3Pin};

static uint8_t kpd_RowsGroup[kpd_RowNo]={ kpd_R0Group, kpd_R1Group, kpd_R2Group, kpd_R3Group};
static uint8_t kpd_RowsPin[kpd_RowNo]={kpd_R0Pin,kpd_R1Pin ,kpd_R2Pin ,kpd_R3Pin }; 


static uint8_t kpd_keysvalue[kpd_RowNo][kpd_ColumnsNo]=kpd_keyvalue;




void KeyPad_Init(){
    uint8_t Counter =0;
// Columns as Input & Internal Pull UP
for(Counter=0;Counter<kpd_ColumnsNo;Counter++){

 DIO_InitPin(kpd_columnsGroup[Counter],kpd_columnsPin[Counter],Input);
 DIO_WritePin(kpd_columnsGroup[Counter],kpd_columnsPin[Counter],High);

}
//ROW as Output & Initaial Value VCC
for(Counter=0;Counter<kpd_RowNo;Counter++){
DIO_InitPin(kpd_RowsGroup[Counter],kpd_RowsPin[Counter],Output);
DIO_WritePin(kpd_RowsGroup[Counter],kpd_RowsPin[Counter],High);

}
}





uint8_t KeyPad_Getpressedkey(){

uint8_t kpd_value=kpd_NoKeyPressed;
uint8_t Columns_Counter=0;
uint8_t Rows_Counter=0;
uint8_t BtnState=0;


for(Rows_Counter=0;Rows_Counter<kpd_RowNo;Rows_Counter++){
    DIO_WritePin(kpd_RowsGroup[Rows_Counter],kpd_RowsPin[Rows_Counter],Low);
    for(Columns_Counter=0;Columns_Counter<kpd_ColumnsNo;Columns_Counter++){
         DIO_ReadPin(kpd_columnsGroup[Columns_Counter],kpd_columnsPin[Columns_Counter],&BtnState);
         if(BtnState==kpd_BtnPressed)
         {
           kpd_value = kpd_keysvalue[Rows_Counter][Columns_Counter];
           do
           {
               DIO_ReadPin(kpd_columnsGroup[Columns_Counter],
                           kpd_columnsPin[Columns_Counter],
                           &BtnState);
           }
           while(BtnState == kpd_BtnPressed);
           _delay_ms(20);   // Debounce
           DIO_WritePin(kpd_RowsGroup[Rows_Counter],kpd_RowsPin[Rows_Counter],High);
           return kpd_value;
         }
        }
         DIO_WritePin(kpd_RowsGroup[Rows_Counter],kpd_RowsPin[Rows_Counter],High);
    }
    return kpd_value;
}
