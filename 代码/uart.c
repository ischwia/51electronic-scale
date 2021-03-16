#include "uart.h"

unsigned int UART_RX_STA=0;
unsigned int UART_STA=0;
unsigned char UART_BUF[50];

void uart_init()
{
	TMOD|=0x20;
	SCON=0x50;
	PCON=0x00;
	TH1=0xFD;
	TL1=TH1;
	TR1=1;
	EA=1;
	ES=1;
}

void Send_Byte(char mydata)	
{
	 ES=0;
	 TI=0;
	 SBUF=mydata;
	 while(!TI);
	 TI=0;
	 ES=1;
}

void Send_Str(char *s)
{
	 int i=0;
	 while(s[i]!=0)
	 {
		Send_Byte(s[i]);
		i++;
	 }
 
}
void Send_END(void)
{
	 Send_Byte(0xFF);
	 Send_Byte(0xFF);
	 Send_Byte(0xFF);
}

void Send_start(void)
{
	// delayms(10);
	 Send_END();
	// delayms(10);
}

void uart_recive() interrupt 4
{
	unsigned char buf;
	EA=0;
	RI=0;
	buf=SBUF;
	if(UART_STA==0)
	{		
		if(buf=='*')UART_STA=1;
		else
		{
			UART_BUF[UART_RX_STA]=buf;
			UART_RX_STA++;
		}
	}
	EA=1;
}


