#include "UART_interface.h"

void UART_send_byte_polling(u16 Data);
u16 UART_receive_byte_polling();


static Uart_config_t global_uart_Config = {0};

void UART_init(Uart_config_t Uart_config)
{
    u8 Local_UCSRCValue = 0;
    global_uart_Config = Uart_config; 
    SetBit (Local_UCSRCValue ,Ucsrc_URSEL);
    // mode select 
    if (Uart_config.mode_select == Uart_mode_async)
    {
        ClearBit(Local_UCSRCValue ,Ucsrc_UMSEL);
    }
    else if (Uart_config.mode_select == Uart_mode_sync)
    {
        SetBit(Local_UCSRCValue ,Ucsrc_UMSEL);
    }
    // parity mode
    if (Uart_config.parity_mode == Uart_parity_mode_disabled)
    {
        ClearBit(Local_UCSRCValue ,Ucsrc_UPM0);
        ClearBit(Local_UCSRCValue ,Ucsrc_UPM1);
    }
    else if (Uart_config.parity_mode == Uart_parity_mode_even)
    {
        ClearBit(Local_UCSRCValue ,Ucsrc_UPM0);
        SetBit(Local_UCSRCValue ,Ucsrc_UPM1);
    }
    else if (Uart_config.parity_mode == Uart_parity_mode_odd)
    {
        SetBit(Local_UCSRCValue ,Ucsrc_UPM0);
        SetBit(Local_UCSRCValue ,Ucsrc_UPM1);
    }
    // stop bit select
    if (Uart_config.stop_bit_select == Uart_stop_bit_1)
    {
        ClearBit(Local_UCSRCValue ,Ucsrc_USBS);
    }
    else if (Uart_config.stop_bit_select == Uart_stop_bit_2)
    {
        SetBit(Local_UCSRCValue ,Ucsrc_USBS);
    }
    // character size select
    if(Uart_config.character_size==Uart_character_size_5)
    {
        ClearBit(Local_UCSRCValue,Ucsrc_UCSZ0);
        ClearBit(Local_UCSRCValue,Ucsrc_UCSZ1);
        ClearBit(UCSRB,Ucsrb_UCSZ2);
            
    }
    else if(Uart_config.character_size==Uart_character_size_6)
    {
        SetBit(Local_UCSRCValue,Ucsrc_UCSZ0);
        ClearBit(Local_UCSRCValue,Ucsrc_UCSZ1);
        ClearBit(UCSRB,Ucsrb_UCSZ2);            
    }
    else if(Uart_config.character_size==Uart_character_size_7)
    {
        ClearBit(Local_UCSRCValue,Ucsrc_UCSZ0);
        SetBit(Local_UCSRCValue,Ucsrc_UCSZ1);
        ClearBit(UCSRB,Ucsrb_UCSZ2);            
    }
    else if(Uart_config.character_size==Uart_character_size_8)
    {
        SetBit(Local_UCSRCValue,Ucsrc_UCSZ0);
        SetBit(Local_UCSRCValue,Ucsrc_UCSZ1);
        ClearBit(UCSRB,Ucsrb_UCSZ2);            
    }
    else if(Uart_config.character_size==Uart_character_size_9)
    {
        SetBit(Local_UCSRCValue,Ucsrc_UCSZ0);
        SetBit(Local_UCSRCValue,Ucsrc_UCSZ1);
        SetBit(UCSRB,Ucsrb_UCSZ2);            
    }
    UCSRC= Local_UCSRCValue;
    // speed mode select
    if (Uart_config.speed_mode == Uart_speed_mode_normal)
    {
        ClearBit(UCSRA,Ucsra_U2X);
    }
    else if (Uart_config.speed_mode == Uart_speed_mode_double)
    {
        SetBit(UCSRA,Ucsra_U2X);
    }

    u16 Local_UBRRValue = 0 ; 

    if (Uart_config.speed_mode == Uart_speed_mode_normal)
    {
        Local_UBRRValue = (F_CPU/(16*Uart_config.baud_rate))-1;
    }
    else if (Uart_config.speed_mode == Uart_speed_mode_double)
    {
        Local_UBRRValue = (F_CPU/(8*Uart_config.baud_rate))-1;
    }
    UBRRL = Local_UBRRValue;
    UBRRH = (Local_UBRRValue >> 8);

    // enable select
    if (Uart_config.enable_select == Uart_EnableRxOnly)
    {
        UART_EnableRX();
        UART_DisableTX();
    }
    else if (Uart_config.enable_select == Uart_EnableTxOnly)
    {
        UART_DisableRX();
        UART_EnableTX();
    }
    else if (Uart_config.enable_select == Uart_EnableRxAndTx)
    {
        UART_EnableRX();
        UART_EnableTX();
    }
}


void UART_send_byte_polling(u16 Data)
{   // 0 1 1 1 1 0 0 1 0 
    // 1 1 1 1 1 0 0 1 0 
    // 1- Make Sure the Regiser is Empty 
    while(ReadFlag(UCSRA,Ucsra_UDRE)==FlagDown);
    // 2- Check on size 
    if(global_uart_Config.character_size==Uart_character_size_9)
    {
        //TXB8 -> UCSRB
        ClearBit(UCSRB,Ucsrb_TXB8);
        if(ReadBit(Data,8)==1) 
        {
            SetBit(UCSRB,Ucsrb_TXB8);
        }
    }
    // 3- Update the UDR 
    UDR=(u8)Data;
}
u16 UART_receive_byte_polling()
{
    u16 LocalData = 0;
    while(ReadFlag(UCSRA,Ucsra_RXC)==FlagDown);
    if(global_uart_Config.character_size==Uart_character_size_9)
    {
        if(ReadBit(UCSRB,Ucsrb_RXB8)==1)
        {
            SetBit(LocalData,8);
        }
    }
    LocalData|=UDR;
    return LocalData;
}

void UART_send_string_polling(u8* String)
{
    u8 LocalCount = 0;
    while(String[LocalCount] != NullChar)
    {
        UART_send_byte_polling(String[LocalCount]);
        LocalCount++;
    }
}
void UART_receive_string_polling(u8* Buffer, u8 Terminator)
{
    u8 LocalCount = 0;
    if(Buffer!=Null)
    {
        Buffer[LocalCount] = (u8)UART_receive_byte_polling();
        while(Buffer[LocalCount] != Terminator)
        {
            LocalCount++;
            Buffer[LocalCount] = (u8)UART_receive_byte_polling();
        }
        Buffer[LocalCount] = '\0';
    }

}

void UART_send_number_polling(u8 Number)
{
    u8 array[10];
    s8 counter = 0;
    if(Number == 0)
    {
        UART_send_byte_polling('0'); 
        return;
    }
    while(Number > 0)
    {
        array[counter] = (Number % 10) + '0'; 
        counter++;
        Number /= 10;
    }
    for(counter = counter - 1; counter >= 0; counter--)
    {
        UART_send_byte_polling(array[counter]);
    }
} 

u8 UART_read_flag_RX_complete()
{
    return ReadFlag(UCSRA , Ucsra_RXC);
}


void UART_EnableRX()
{
    SetBit(UCSRB,Ucsrb_RXEN);
}
void UART_EnableTX()
{
    SetBit(UCSRB,Ucsrb_TXEN);
}
void UART_DisableRX()
{
    ClearBit(UCSRB,Ucsrb_RXEN);
}
void UART_DisableTX()
{
    ClearBit(UCSRB,Ucsrb_TXEN);
}

