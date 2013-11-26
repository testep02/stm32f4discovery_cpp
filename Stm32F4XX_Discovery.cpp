#include "Stm32F4XX_Discovery.h"

extern "C" {
  #include "stm32f4xx_delay.h"
}

Stm32F4XX_Discovery::Stm32F4XX_Discovery()
{
  usrLed3State = 0;
  usrLed4State = 0;
  usrLed5State = 0;
  usrLed6State = 0;

  configUsrLeds();
}

void Stm32F4XX_Discovery::configUsrLeds()
{
  GPIO_InitTypeDef USR_LED_Setup;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

  USR_LED_Setup.GPIO_Pin = 0xF000;
  USR_LED_Setup.GPIO_Mode = GPIO_Mode_OUT;
  USR_LED_Setup.GPIO_OType = GPIO_OType_PP;
  USR_LED_Setup.GPIO_Speed = GPIO_Speed_100MHz;
  USR_LED_Setup.GPIO_PuPd = GPIO_PuPd_NOPULL;

  GPIO_Init(USR_LED_PORT, &USR_LED_Setup);
}

void Stm32F4XX_Discovery::toggleUsrLed3()
{
  if( usrLed3State == 0 )
  {
    GPIOD->BSRRL = USR_LED_3;
    usrLed3State = 1;
    
    
    //Delay(30);
  }
  else
  {
    GPIOD->BSRRH = USR_LED_3;
    usrLed3State = 0;

   
    //Delay(30);
  }
}

void Stm32F4XX_Discovery::toggleUsrLed4()
{
  if( usrLed4State == 0 )
  {
    GPIOD->BSRRL = USR_LED_4;
    usrLed4State = 1;
    
    int i = 0;
    int count = 0;
    for(i = 0; i < 0xFFFFF; i++){
      count++;
    }
    //Delay(30);
  }
  else
  {
    GPIOD->BSRRH = USR_LED_4;
    usrLed4State = 0;

    int i = 0;
    int count = 0;
    for(i = 0; i < 0xFFFFF; i++){
      count++;
    }
    //Delay(30);
  }
}

void Stm32F4XX_Discovery::toggleUsrLed5()
{
  if( usrLed5State == 0 )
  {
    GPIOD->BSRRL = USR_LED_5;
    usrLed5State = 1;
    Delay(30);
  }
  else
  {
    GPIOD->BSRRH = USR_LED_5;
    usrLed5State = 0;
    Delay(30);
  }
}

void Stm32F4XX_Discovery::toggleUsrLed6()
{
  if( usrLed6State == 0 )
  {
    GPIOD->BSRRL = USR_LED_6;
    usrLed6State = 1;
    Delay(30);
  }
  else
  {
    GPIOD->BSRRH = USR_LED_6;
    usrLed6State = 0;
    Delay(30);
  }
}

void Stm32F4XX_Discovery::usrLed3_ON()
{
  GPIOD->BSRRL = USR_LED_3;
}

void Stm32F4XX_Discovery::usrLed3_OFF()
{
  GPIOD->BSRRH = USR_LED_3;
}

void Stm32F4XX_Discovery::usrLed4_ON()
{
  GPIOD->BSRRL = USR_LED_4;
}

void Stm32F4XX_Discovery::usrLed4_OFF()
{
  GPIOD->BSRRH = USR_LED_4;
}

void Stm32F4XX_Discovery::usrLed5_ON()
{
  GPIOD->BSRRL = USR_LED_5;
}

void Stm32F4XX_Discovery::usrLed5_OFF()
{
  GPIOD->BSRRH = USR_LED_5;
}

void Stm32F4XX_Discovery::usrLed6_ON()
{
  GPIOD->BSRRL = USR_LED_6;
}

void Stm32F4XX_Discovery::usrLed6_OFF()
{
  GPIOD->BSRRH = USR_LED_6;
}