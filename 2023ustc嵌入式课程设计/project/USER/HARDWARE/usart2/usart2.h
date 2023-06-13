#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 

#define USART2_MAX_RECV_LEN  			2048  	//�����������ֽ��� 1024
#define USART2_MAX_SEND_LEN 			2048  	//�����������ֽ��� 1024

	  	
extern u8 USART2_RX_BUF[USART2_MAX_RECV_LEN];  //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u8  USART2_TX_BUF[USART2_MAX_SEND_LEN];
extern char USART2_RX_BUF_char[USART2_MAX_RECV_LEN];
extern u16 USART2_RX_STA;         		//����״̬���	
//����봮���жϽ��գ��벻Ҫע�����º궨��
void USART2_IRQHandler(void);
void usart2_init(u32 bound);
void TIM4_IRQHandler(void);
void TIM4_Int_Init(u16 arr,u16 psc);
void u2_printf(char* fmt,...);
#endif














