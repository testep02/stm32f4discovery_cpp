#ifndef __STM32F4XX_DELAY_H__
#define __STM32F4XX_DELAY_H__

#include <stm32f4xx.h>

void InitSysTick();
void Delay( __IO uint32_t nTime);
void TimingDelay_Decrement(void);

#endif