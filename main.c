#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"
#include "usmart.h"	 
#include "24cxx.h"
#include "sht2x.h"

char Str_Buf[32];
int main(void)
{
	float temp,Humi;
	u16 DS18B20Temp;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// ÉèÖÃÖÐ¶ÏÓÅÏÈ¼¶·Ö×é2
	delay_init();	    	//ÑÓÊ±º¯Êý³õÊ¼»¯	  
	uart_init(9600);	 	//´®¿Ú³õÊ¼»¯Îª9600
	LED_Init();		  		//³õÊ¼»¯ÓëLEDÁ¬½ÓµÄÓ²¼þ½Ó¿Ú
	LCD_Init();			 	  //LCD³õÊ¼»¯
	SHT2x_Init();       //SHT2x³õÊ¼»¯
	POINT_COLOR=RED;    //ÉèÖÃ×ÖÌåÎªºìÉ« 
	LCD_ShowString(60,50,200,16,16,"Mini V3.0 STM32");	
	LCD_ShowString(60,70,200,16,16,"SHT20-TEST");	
//  DS18B20_Init();	//DS18B20³õÊ¼»¯	

	POINT_COLOR=BLUE;    //ÉèÖÃ×ÖÌåÎªÀ¶É« 
	while(1)
	{
//		DS18B20Temp=DS18B20_Get_Temp();//»ñÈ¡DS18B20ÎÂ¶È
		temp=SHT2x_GetTempPoll();//»ñÈ¡SHT20 ÎÂ¶È
		Humi=SHT2x_GetHumiPoll();//»ñÈ¡SHT20 Êª¶È
		sprintf(Str_Buf,"SHT20 Temp:%6.2f C",temp);
		LCD_ShowString(60,100,200,16,16,(u8 *)Str_Buf);
		sprintf(Str_Buf,"SHT20 Humi:%6.2f %%",Humi);	
		LCD_ShowString(60,120,200,16,16,(u8 *)Str_Buf);		
	  sprintf(Str_Buf,"DS18B20 Temp:%6.2f  C",(float)DS18B20Temp/10.0);	
		LCD_ShowString(60,140,200,16,16,(u8 *)Str_Buf);		
		delay_ms(250);
		LED0=!LED0;//ÌáÊ¾ÏµÍ³ÕýÔÚÔËÐÐ	
                                                    
	}
}

