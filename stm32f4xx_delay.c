#include "stm32f4xx_delay.h"

static __IO uint32_t uwTimingDelay;

void InitSysTick()
{ 
  if(SysTick_Config(SystemCoreClock / 1000))
  {
    while(1);
  }
}

void Delay(__IO uint32_t nTime)
{
  uwTimingDelay = nTime;

  while(uwTimingDelay != 0);
}

void TimingDelay_Decrement(void)
{
  if(uwTimingDelay != 0x00)
  {
    uwTimingDelay--;
  }
}