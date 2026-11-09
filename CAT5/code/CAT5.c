#include <stdio.h>
#include <reg51.h>

sbit led1 = P1^0;

void main(void)
{
    unsigned int count = 0;
    
    TMOD = 0x01;
    TH0 = 0xFC;
    TL0 = 0x66;
    
    TR0 = 1;
    
    while(1)
    {
        if(TF0 == 1)
        {
            TF0 = 0;
            TH0 = 0xFC;
            TL0 = 0x66;
            
            count++;
            if(count >= 500)
            {
                led1 = !led1;
                count = 0;
            }
        }
    }
}