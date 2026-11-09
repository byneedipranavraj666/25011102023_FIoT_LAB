#include <reg51.h>

void UART_Init()
{
    TMOD = 0x20;
    TH1 = 0xFD;
    TR1 = 1;
    SCON = 0x50;
}

void UART_TxChar(char c)
{
    SBUF = c;
    while(TI == 0);
    TI = 0;
}

void UART_TxString(char *str)
{
    while(*str)
    {
        UART_TxChar(*str++);
    }
}

void main()
{
    UART_Init();
    while(1)
    {
        UART_TxString("Hello from 8051\r\n");
        for(unsigned int i = 0; i < 60000; i++);
    }
}