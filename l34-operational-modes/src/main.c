/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "stm32f4xx_nucleo.h"
#include "stm32f446xx.h"

// Implement the WatchDog Handler
void WWDG_IRQHandler(void)
{
	for(int i=0; i<50;i++);
}

void generate_interrupt(void)
{
	// SIMULATE the Watch Dog interrupt
	NVIC_EnableIRQ(WWDG_IRQn);
	NVIC_SetPendingIRQ(WWDG_IRQn);
}

int main(void)
{
	// This line will simulate an interrupt
	generate_interrupt();

	while(1);
	return 0;
}


