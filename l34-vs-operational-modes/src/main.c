#include <"stm32f446xx.h">

void generate_interrupt(void)
{
  // Simulate Watchdog
  NVIC_EnableIRQ();
}

int main(void)
{
  while(1);
  return 0;
}