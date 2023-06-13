#include "led.h"
#include "delay.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	
#include "usart2.h"
#include "dht11.h" 	 
#include "touch.h"
 extern unsigned int rec_data[4];
u8 flag=0;
extern u16 USART2_RX_STA;         		//����״̬���	
 int main(void)
 {	 
	u8 i=0;
  u16 button_color=YELLOW; 
	u8 t=0;	  	    
	delay_init();	    	 //��ʱ������ʼ��	  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(9600);	 	//���ڳ�ʼ��Ϊ115200
	usart2_init(9600);
	LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ�
	LCD_Init();			   	//��ʼ��LCD  
 	POINT_COLOR=RED;		//��������Ϊ��ɫ 
	tp_dev.init();
	BACK_COLOR=YELLOW; 
	LCD_Fill(15,120,75,150,button_color); 
	LCD_ShowxNum(35,120,0,2,16,0);
	LCD_Fill(90,120,150,150,button_color);  
	LCD_ShowxNum(110,120,1,2,16,0);
	LCD_Fill(165,120,225,150,button_color);  
	LCD_ShowxNum(185,120,2,2,16,0);	
	BACK_COLOR=WHITE;
	LED0=0;	 
	 for(i=0;i<7;i++)
	 {
	 Chinese_Show_one(30+i*16, 30,  i*2, 16,0);
	 Chinese_Show_one(30+i*16, 60,  (i+7)*2, 16,0);	
	 }
	 	i=0;  
	 while(1)
	{
		tp_dev.scan(0);
		if(tp_dev.sta&TP_PRES_DOWN)			//������������
			{	
				if((15<tp_dev.x[t]&&tp_dev.x[t]<75)&&(tp_dev.y[t]>120&&tp_dev.y[t]<150))
				{
					flag=0;

				}else if((90<tp_dev.x[t]&&tp_dev.x[t]<150)&&(tp_dev.y[t]>120&&tp_dev.y[t]<150))
				{
					flag=1;
		
				}else if((165<tp_dev.x[t]&&tp_dev.x[t]<225)&&(tp_dev.y[t]>120&&tp_dev.y[t]<150))
				{
					flag=2;
	
				}
				
			}else delay_ms(10);	//û�а������µ�ʱ��		
		delay_ms(100);
		DHT11_REC_Data(); //�����¶Ⱥ�ʪ�ȵ�����
		LCD_ShowxNum(142,30,rec_data[2],2,16,0);
		LCD_ShowChar(158,30,'.',16,0);
		LCD_ShowxNum(166,30,rec_data[3],2,16,0);
		LCD_ShowxNum(142,60,rec_data[0],2,16,0);
		LCD_ShowChar(158,60,'.',16,0);
		LCD_ShowxNum(166,60,rec_data[1],2,16,0);	
		if(flag==0)
		{
			if(rec_data[2]>25)
			{
				LED0=1;
				u2_printf("�¶���%d.%d,����\n",rec_data[2],rec_data[3]);
				
			}else
			{
				LED0=0;
				u2_printf("�¶���%d.%d,����\n",rec_data[2],rec_data[3]);
			}		
		}else if(flag==1)
		{
			LED0=0;
			u2_printf("�¶���%d.%d,����\n",rec_data[2],rec_data[3]);
		}else if(flag==2)
		{
			LED0=1;
			u2_printf("�¶���%d.%d,����\n",rec_data[2],rec_data[3]);
		}	
			

	}
}
 

 
