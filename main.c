//Blinking of LED on STM32F303 using HAL driver

//https://github.com/ninadwaingankar/My-STM32F303-projects

#include "stm32f3xx_hal.h"


//for LED sets
#define LEDS1 (GPIO_PIN_8 | GPIO_PIN_10 | GPIO_PIN_12 | GPIO_PIN_14)
#define LEDS2 (GPIO_PIN_9 | GPIO_PIN_11 | GPIO_PIN_13 | GPIO_PIN_15)

//function to initialise LEDS
void led_init(void);

//function for delay
void my_delay(uint32_t);


int main(void)
{
  //function to initiate LED 
	led_init();
	
  //infinite loop for continuous working
	while(1)
	{
		HAL_GPIO_WritePin(GPIOE,LEDS1 | LEDS2,GPIO_PIN_RESET);
		//my_delay(1000);
	  HAL_GPIO_WritePin(GPIOE,LEDS1,GPIO_PIN_SET);
		my_delay(200);
		HAL_GPIO_WritePin(GPIOE,LEDS1 | LEDS2,GPIO_PIN_RESET);
		//my_delay(1000);
	  HAL_GPIO_WritePin(GPIOE,LEDS2,GPIO_PIN_SET);
		my_delay(200);
	}
	
//	return 0;
}

void my_delay(uint32_t cycles)
{
	uint32_t i,j;
	
  //loop for interating to generate delay
	for(i=0;i<cycles;i++)
	{
		for(j=0;j<1000;j++)
		{
			// does nothing
		}
	}
}

//developed by: Ninad Waingankar


void led_init(void)
{
	__HAL_RCC_GPIOE_CLK_ENABLE();
	
	GPIO_InitTypeDef myled = {0};
	
	myled.Mode=GPIO_MODE_OUTPUT_PP;	
	myled.Pull=GPIO_NOPULL;
	myled.Pin=LEDS1 | LEDS2;
	
	HAL_GPIO_Init(GPIOE,&myled);
}

