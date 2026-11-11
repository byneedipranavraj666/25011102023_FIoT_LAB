#include<stdio.h>
#include<reg51.h>

void init(){
	TMOD=0x20;
	TH1=0xFD;
	TR1=1;
	SCON=0x50;
	
}
 void uart(char c){
	 SBUF=c;
	 while(TI==0);
	 TI=0;
 }
 
 void main(){
	 init();
	 while(1){
		 uart("Hello from 8051");
	 }
 }