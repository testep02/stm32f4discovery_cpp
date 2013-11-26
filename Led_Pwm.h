#ifndef __LED_PWM_H__
#define __LED_PWM_H__

extern "C"{
  #include <stm32f4xx_gpio.h>
  #include <stm32f4xx_tim.h>
  #include <stm32f4xx_rcc.h>
  #include <stm32f4xx.h>
  #include <misc.h>
  #include "stm32f4xx_delay.h"
}

class Led_Pwm
{
  public:
    Led_Pwm();
    ~Led_Pwm();
    virtual void ledBright(unsigned int value);
    virtual void ledDim(unsigned int value);
    virtual void demo();

  protected:
    uint16_t PrescalerValue;
};

#endif