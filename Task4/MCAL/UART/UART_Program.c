/**
 * @file UART_Program.c
 * @brief Implementation of the UART peripheral driver
 * @details This file contains the implementation of the UART driver APIs
 * The driver provides UART initialization, polling-based
 * communication, interrupt-based communication, peripheral
 * control, and callback registration.
 * @version 0.1
 * @author Malak Mohammed (malak.mohammed.esmail@gmail.com) 
 * @date 14-09-2026
 * @copyright Copyright (c) 2026, Gestell Company
 */


#include "UART_Interface.h"
/**
 * @brief Pointer to the UART receive callback function.
 * @details Stores the callback function registered by the user to handle UART receive complete interrupts.
 */
static void (*PF_UartRx)(uint16_t)=Null; 

/**
 * @brief Pointer to the UART transmit complete callback function.
 * @details Stores the callback function registered by the user to handle UART transmit complete interrupts.
 */
static void (*PF_UartTx)(void)=Null;

/**
 * @brief Pointer to the UART Data Reguster Empty callback function.
 * @details Stores the callback function registered by the user to handle UART Data Register Empty interrupts.
 */
static void (*PF_UartRE)(void)=Null;

/**
 * @brief Global UART configuration.
 * @details Stores the configuration parameters used to initialize and manage the UART peripheral.
 * @note Updated during UART initialization.
 */
static UART_Config_t GlobalUARTConfig={0};

void UART_Init (UART_Config_t UART_Config)
{
    uint8_t Local_UCSRCValue=0;
    GlobalUARTConfig=UART_Config;

    SetBit(Local_UCSRCValue,UART_URSEL);

//Mode
if(UART_Config.ModeSelect==UART_AsynchMode)
{
ClearBit(Local_UCSRCValue,UART_UMSEL);
}
else if(UART_Config.ModeSelect==UART_SynchMode)
{
SetBit(Local_UCSRCValue,UART_UMSEL);
}
else 
{
    //Invalid Mode Configuration 
}

//StopBit
if(UART_Config.StopBitSelect==UART_1StopBit)
{
ClearBit(Local_UCSRCValue,UART_USBS);
}

else if(UART_Config.StopBitSelect==UART_2StopBits)
{
SetBit(Local_UCSRCValue,UART_USBS);
}
else 
{
    //Invalid Stop Bit configuration 
}

//Parity
if(UART_Config.ParitySelect==UART_ParityDisabled)
{
ClearBit(Local_UCSRCValue,UART_UPM0);
ClearBit(Local_UCSRCValue,UART_UPM1);
}
else if(UART_Config.ParitySelect==UART_ParityEven)
{
ClearBit(Local_UCSRCValue,UART_UPM0);
SetBit(Local_UCSRCValue,UART_UPM1);
}
else if(UART_Config.ParitySelect==UART_ParityOdd)
{
SetBit(Local_UCSRCValue,UART_UPM0);
SetBit(Local_UCSRCValue,UART_UPM1);
}
else 
{
    //Invalid Parity Configuration 
}

//Character Size Selection
if(UART_Config.CharacterSizeSelect<9)
{
ClearBit(UCSRB_Reg,UART_UCSZ2);
Local_UCSRCValue= (Local_UCSRCValue &~ CharacterSelectMask)| (UART_Config.CharacterSizeSelect<<1);
}
else if(UART_Config.CharacterSizeSelect==9)
{
SetBit(Local_UCSRCValue,UART_USCZ0);
SetBit(Local_UCSRCValue,UART_USCZ1);
SetBit(UCSRB_Reg,UART_UCSZ2);
}
else 
{
    //Invalid Character Size Selection 
}
UCSRC_Reg= Local_UCSRCValue;

//-------------------------------------------------------

//Speed
if(UART_Config.SpeedMode==UART_DoubleSpeed)
{
SetBit(UCSRA_Reg,UART_U2X);
}
else if(UART_Config.SpeedMode==UART_NormalSpeed)
{
ClearBit(UCSRA_Reg,UART_U2X);
}
else 
{
    //Invalid Speed Configuration 
}

//BaudRate
uint16_t Local_UBBRValue=0;

if(UART_Config.SpeedMode==UART_DoubleSpeed)
{
    Local_UBBRValue= ( FCPU/(8UL * UART_Config.BaudRate) )-1;
}
else if(UART_Config.SpeedMode==UART_NormalSpeed)
{
    Local_UBBRValue= ( FCPU/(16UL * UART_Config.BaudRate) )-1;
}
else 
{
    //Invalid Baud Rate Configuration 
}

UBRRL_Reg=Local_UBBRValue;
UBRRH_Reg=(Local_UBBRValue>>8);


//InterruptSelect

UART_RxInterruptDisable();
UART_TxInterruptDisable();
UART_REInterruptDisable();

if(UART_Config.InterruptSelect==UART_InterruptRxOnly)
{
    UART_RxInterruptEnable();
}
else if(UART_Config.InterruptSelect==UART_InterruptTxOnly)
{
    UART_TxInterruptEnable();

}
else if(UART_Config.InterruptSelect==UART_InterruptREOnly)
{
    UART_REInterruptEnable();

}
else if(UART_Config.InterruptSelect==UART_InterruptRxTx)
{
     UART_RxInterruptEnable();
     UART_TxInterruptEnable();
}
else if(UART_Config.InterruptSelect==UART_InterruptRxRE)
{
     UART_RxInterruptEnable();
     UART_REInterruptEnable();

}
else if(UART_Config.InterruptSelect==UART_InterruptTxRE)
{
     UART_TxInterruptEnable();
     UART_REInterruptEnable();
}
else if(UART_Config.InterruptSelect==UART_InterruptAll)
{
     UART_TxInterruptEnable();
     UART_REInterruptEnable();
     UART_RxInterruptEnable();
}
else 
{
    //Invalid Interrupt Configuration 
}

//Enable Select
if(UART_Config.EnableSelect==UART_EnableRxOnly)
{
    UART_RxEnable();
   UART_TxDisable();
}
else if(UART_Config.EnableSelect==UART_EnableTxOnly)
{
   UART_TxEnable();
    UART_RxDisable();

}
else if(UART_Config.EnableSelect==UART_EnableRxTx)
{
    UART_RxEnable(); 
    UART_TxEnable();
}
else 
{
    //Invalid Transmission Line Configuration 
}

}

void UART_SendBytePolling (uint16_t Data)
{
    while(ReadFlag(UCSRA_Reg,UART_UDRE)==FlagDown);

    if(GlobalUARTConfig.CharacterSizeSelect==9)
    {
     ClearBit(UCSRB_Reg,UART_TXB8);
      if(ReadBit(Data,8)==1)
        {
            SetBit(UCSRB_Reg,UART_TXB8);
        }
    }
    UDR_Reg=(uint8_t)Data;
}

uint16_t UART_ReceiveBytePolling(void)
{
    uint16_t LocalData=0;
    uint32_t Timeout_Counter = 0;

    while(ReadFlag(UCSRA_Reg,UART_RXC)==FlagDown)
    {
        Timeout_Counter++;

        if(Timeout_Counter>UART_MaxTimeOut)
        {
            return UART_TimeOut_Error;
        }
    }

    if(GlobalUARTConfig.CharacterSizeSelect==9)
    {
        if(ReadBit(UCSRB_Reg,UART_RXB8)==1)
        {
            SetBit(LocalData,UART_RXB8);
        }
    }
    LocalData|=UDR_Reg;
    return LocalData;
}
void UART_SendStringPolling(uint8_t* string)
{
    uint8_t LocalCount=0;
    while(string[LocalCount]!=NullChar)
   {
    UART_SendBytePolling(string[LocalCount]);
    LocalCount++;
   }
}

void UART_ReceiveStringPolling(uint8_t* Buffer,uint8_t Terminator)
{
    uint16_t LocalCount=0;
    uint32_t SafetyCounter = 0;

    if(Buffer!=Null)
    {
        Buffer[LocalCount]=(uint8_t)UART_ReceiveBytePolling();
        while(Buffer[LocalCount]!=Terminator)
        {
         LocalCount++;
         SafetyCounter++;

         if(SafetyCounter>=UART_Max_StringTimeout)
         {
                Buffer[LocalCount] = '\0';
                break;
         }
               Buffer[LocalCount]=(uint8_t)UART_ReceiveBytePolling();
        }
               Buffer[LocalCount] = '\0';
    }
}

void UART_SendBufferPolling(uint8_t* Buffer, uint16_t Length)
{
    uint16_t LocalCount=0;
     for(LocalCount = 0; LocalCount < Length; LocalCount++)
    {
        UART_SendBytePolling(Buffer[LocalCount]);
    }

}

void UART_SendByteInterrupt(uint16_t Data)
{
    if(GlobalUARTConfig.CharacterSizeSelect == 9)
    {
        ClearBit(UCSRB_Reg, UART_TXB8);
        if(ReadBit(Data, 8) == 1)
        {
            SetBit(UCSRB_Reg, UART_TXB8);
        }
    }
    
    
    UDR_Reg = (uint8_t)Data;
}


void UART_RxEnable(void)
{
  SetBit(UCSRB_Reg,UART_RXEN);
}
void UART_TxEnable(void)
{
  SetBit(UCSRB_Reg,UART_TXEN); 
}
void UART_RxDisable(void)
{
    ClearBit(UCSRB_Reg,UART_RXEN);
}
void UART_TxDisable(void)
{
    ClearBit(UCSRB_Reg,UART_TXEN);
}

void UART_RxInterruptEnable(void)
{
    SetBit(UCSRB_Reg,UART_RXCIE);
}
void UART_TxInterruptEnable(void)
{
    SetBit(UCSRB_Reg,UART_TXCIE);
}
void UART_REInterruptEnable(void)
{
    SetBit(UCSRB_Reg,UART_UDRIE);
}

void UART_RxInterruptDisable(void)
{
    ClearBit(UCSRB_Reg,UART_RXCIE);
}
void UART_TxInterruptDisable(void)
{
    ClearBit(UCSRB_Reg,UART_TXCIE);
}
void UART_REInterruptDisable(void)
{
    ClearBit(UCSRB_Reg,UART_UDRIE);
}

void UART_SetRxCallBack(void (*PF)(uint16_t))
{
      if(PF!=Null)
      {
       PF_UartRx=PF;
      }

}
void UART_SetTxCallBack(void (*PF)(void))
{
      if(PF!=Null)
      {
      PF_UartTx=PF;
      }
}
void UART_SetRECallBack(void (*PF)(void))
{
      if(PF!=Null)
      {
         PF_UartRE=PF;
      }
}


//Rx
void __vector_13(void)
{
   if(PF_UartRx!=Null)
   {
    uint16_t LocalData=0;
   if(GlobalUARTConfig.CharacterSizeSelect==9)
   {
      if(ReadBit(UCSRB_Reg, UART_RXB8) == 1)
        {
        SetBit(LocalData, 8); 
        }
   }
     LocalData|=UDR_Reg;
     PF_UartRx(LocalData);
   }
}
//RE
void __vector_14(void)
{
   if(PF_UartRE!=Null)
   {
    PF_UartRE();
   }
}

//Tx
void __vector_15(void)
{
   if(PF_UartTx!=Null)
   {
    PF_UartTx(); 
   }
}