#ifndef __MAIN_H__
#define __MAIN_H__

#include <__cross_studio_io.h>
#include "Stm32F4XX_Discovery.h"
#include "SPFD5408A.h"
#include "ILI9341.h"
#include "GraphicsLib.h"
#include "Led_Pwm.h"
#include "LIS302DL.h"

extern "C"{
  #include "stm32f4xx_delay.h"
  #include <stm32f4xx.h>
  #include <stm32f4xx_exti.h>
  #include <stm32f4xx_rcc.h>
  #include <stm32f4xx_gpio.h>
  #include <stm32f4xx_syscfg.h>
  #include <misc.h>
}

typedef enum
{
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1

} ButtonMode_TypeDef;

void initAccelDemo();
void initTftDemo();
void initUsrLedsDemo();
void initPwmDemo();
void initButtonInt();

#endif