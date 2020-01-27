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

void call_application_task(void)
{
	// This is the user
	uint32_t value = __get_CONTROL();
	value &= ~0x01;
	__set_CONTROL(value);

}

void RTOS_init(void)
{
	// Does RTOS low level initialization

	// Before running the task, change privilege level!
	uint32_t value = __get_CONTROL();
	value |= 0x01;
	__set_CONTROL(value);

	call_application_task();
}

int main(void)
{
	// This line will simulate an interrupt
	generate_interrupt();
	RTOS_init();
	while(1);
	return 0;
}
