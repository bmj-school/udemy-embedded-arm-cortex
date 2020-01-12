#include "stm32f10x.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"

GPIO_InitTypeDef GPIO_InitStruct;
void delay(int a);

int main(void)
{
  // Enable clock for GPIOB
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  // Configure PB0 as open-drain output
  GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
  GPIO_Init(GPIOB, &GPIO_InitStruct);
  while (1)
 {
  // Turn on LED on PB0 (LED circuit is active low)
  GPIO_ResetBits(GPIOB, GPIO_Pin_0);
  delay(500000);
  // Turn off LED on PB0
  GPIO_SetBits(GPIOB, GPIO_Pin_0);
  delay(500000);
 }
}

void delay (int a)
{
 volatile int i,j;
 for (i=0 ; i < a ; i++)
 {
  j++;
 }
 return;
}