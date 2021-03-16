#include "HX711.h"

	
void dekay_us(void)
{
	//int t=10;
	//while(t--);
	_nop_();
	_nop_();
}

unsigned int HX711_Read()
{
	unsigned int count;
	uchar i;
	dout=1;
	dekay_us();
	sck=0;
	count=0;
	while(dout);
	for(i=0;i<16;i++)
	{
		sck=1;
		count=count<<1;
		sck=0;
		if(dout)count++;
	}
	sck=1;
	count=count^0x8000;
	dekay_us();
	sck=0;
	return(count);
}






