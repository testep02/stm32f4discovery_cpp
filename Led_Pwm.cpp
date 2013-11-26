#include "Led_Pwm.h"

Led_Pwm::Led_Pwm()
{
  TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
  TIM_OCInitTypeDef TIM_OCInitStructure;

  /* TIM Config */

  GPIO_InitTypeDef GPIO_InitStructure;

  /* TIM4 Clock Enable */

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

  /* LEDs and GPIO */

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 |
    GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_TIM4);

  /* PWM Setup */

  // Compute the Prescaler Value
  PrescalerValue = (uint16_t) ((SystemCoreClock / 2) / 21000000) - 1;
  
  /* Time base config */

  TIM_TimeBaseStructure.TIM_Period = 665;
  TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

  /* PWM1 Mode configuration: Channel 1 */

  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;
  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

  TIM_OC1Init(TIM4, &TIM_OCInitStructure);

  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

  /* PWM1 Mode Configuration: Channel 2 */

  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;

  TIM_OC2Init(TIM4, &TIM_OCInitStructure);

  TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

  /* PWM1 Mode Configuration: Channel 3 */

  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;

  TIM_OC3Init(TIM4, &TIM_OCInitStructure);

  TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);

  /* PWM1 Mode Configuration: Channel 4 */

  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
  TIM_OCInitStructure.TIM_Pulse = 0;

  TIM_OC4Init(TIM4, &TIM_OCInitStructure);

  TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);

  TIM_ARRPreloadConfig(TIM4, ENABLE);

  /* TIM4 Enable Counter */

  TIM_Cmd(TIM4, ENABLE);
}

Led_Pwm::~Led_Pwm()
{

} 

void Led_Pwm::ledBright(unsigned int value)
{

}

void Led_Pwm::ledDim(unsigned int value)
{

}

void Led_Pwm::demo()
{
  int brightness = 0;

  while(1)
  {
    brightness++;

    // Duty Cycle values can range from 0 (OFF) t0 333 (Full ON)

    TIM4->CCR3 = 333 - (brightness + 0) % 333;
    TIM4->CCR4 = 333 - (brightness + 83 / 2) % 333; //166
    TIM4->CCR1 = 333 - (brightness + 151 / 2) % 333; //333
    TIM4->CCR2 = 333 - (brightness + 249 / 2) % 333; //499

    Delay(20);
  }
}