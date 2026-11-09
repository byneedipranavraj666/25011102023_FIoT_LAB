#include <reg51.h>

void UART_Init()
{
    TMOD = 0x20;
    TH1 = 0xFD;
    TR1 = 1;
    SCON = 0x50;
}

char UART_RxChar()
{
    while(RI == 0);
    RI = 0;
    return SBUF;
}

void UART_TxChar(char c)
{
    SBUF = c;
    while(TI == 0);
    TI = 0;
}

void main()
{
    UART_Init();
    while(1)
    {
        char received = UART_RxChar();
        UART_TxChar(received);
    }
}