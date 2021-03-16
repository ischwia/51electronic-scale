#ifndef _UART_H
#define _UART_H
#include "reg52.h"

extern  unsigned int UART_RX_STA;         		//接收状态标记	
extern  unsigned int UART_STA;         		//接收状态标记	
extern  unsigned char UART_BUF[50];
void uart_init(void);

//与串口屏通讯
extern void Send_Byte(char mydata);
extern void Send_Str(char *s);
extern void Send_END(void);				//发送结束符
extern void Send_start(void);				//初始化




#endif
