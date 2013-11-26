#ifndef __STM32F4XX_DISCOVERY_H__
#define __STM32F4XX_DISCOVERY_H__

#include "main.h"

extern "C" {
  #include <stm32f4xx.h>
  #include <stm32f4xx_gpio.h>
  #include <stm32f4xx_rcc.h>
}

#define USR_LED_PORT        GPIOD
#define USR_LED_3           0x2000
#define USR_LED_4           0x1000
#define USR_LED_5           0x4000
#define USR_LED_6           0x8000

class Stm32F4XX_Discovery
{
  public:

    Stm32F4XX_Discovery();

    void configUsrLeds();

    void toggleUsrLed3();
    void toggleUsrLed4();
    void toggleUsrLed5();
    void toggleUsrLed6();
    void usrLed3_ON();
    void usrLed3_OFF();
    void usrLed4_ON();
    void usrLed4_OFF();
    void usrLed5_ON();
    void usrLed5_OFF();
    void usrLed6_ON();
    void usrLed6_OFF();

  private:

    int usrLed3State;
    int usrLed4State;
    int usrLed5State;
    int usrLed6State;
};

#endif