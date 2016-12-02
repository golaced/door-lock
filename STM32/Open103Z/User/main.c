#include "head.h"
#include "table.h"
extern uint8_t write[];
extern uint8_t read[];
u8 state_lock[2];

u8 test;
u8 en_set_time=0;
int time[6];
int main(void)
{	u8 i;
	u8 key;
		delay_init(72);		//延时初始化
		OLED_Init();
		delay_ms(1000);	OLED_Fill(0x00);OLED_P8x16Str(15,3,"SYS Init_done!");	
		RS485_Init();USART_init();
	  
		//delay_ms(1000);//	OLED_Fill(0x00);//OLED_P8x16Str(10,3,"UART Initdone");
    Lock_init();
time[0]=15;
time[1]=3;
time[2]=10;
time[3]=21+6;
time[4]=18+6;
time[5]=0;
if(en_set_time)
	 Ds1302_Write_Time();
	
  	Ds1302_Init();
		Time4ON();
	
	OLED_Fill(0x00);OLED_P6x8Str(3,0,"By Golaced-BIT ");OLED_P8x16Str(43,3,"Welcome!");	 __enable_irq();
		while(1){
	key=Get_open_key;
	if(key==0)	 //按键KEY0
	{  if(open_lock1==0)
	      {open_lock1=1;
					
				OLED_Fill(0x00);OLED_P8x16Str(30,3,"See You!");	
				}	
	}		 
		
    //Lock_tast(1,state_lock[0]);
	  //Lock_tast(2,state_lock[1]);
   Lock_Task();
			test=Get_open_key;
		}
}
/*********************************************END OF FILE**********************/

