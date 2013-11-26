#include "main.h"

//Stm32F4XX_Discovery board;
ILI9341 tft;
 uint16_t color = 0xFFFF;

extern "C" void EXTI0_IRQHandler(void);

int
main(void)
{
  //InitSysTick();


  //board.toggleUsrLed3();
  //Delay(500);
  //board.toggleUsrLed3();
  //Delay(500);
  //board.toggleUsrLed3();

  //initAccelDemo();
  initTftDemo();
  //initPwmDemo();
  initButtonInt();

  uint16_t x = 0;
  uint16_t y = 0;

  while(1)
  {
    if(GPIOB->IDR = 0x0004)
    {
      tft.fillRectangle(x, y, 10, 10, 0x0000);
    }
    else
    {
      tft.fillRectangle(x, y, 10, 10, 0xFFFF);
    }
    
    x += 10;
    y += 10;
    
    if( x > 239 )
    {
      x = 0;
    }
    if( y > 319 )
    {
      y = 0;
    }
  }

  return 0;
}

void initTftDemo()
{
  //SPFD5408A tft;
  ILI9341 tft;
  
  //uint16_t color = 0xFFFF;

  /*while(1)
  {
    if( color == 0x0000 )
    {
      color = 0xFFFF;
    }

    tft.fillRectangle(0, 0, 239, 319, color);
    
    color--;
  }*/

  tft.fillRectangle(0, 0, 239, 319, 0xF800);
  //GraphicsLib graphics(tft);
  //graphics.fillRectangle(10, 10, 100, 100, 0xF800);
}

void initUsrLedsDemo()
{
  while(1)
  {
    //board.toggleUsrLed3();
  }
}

void initPwmDemo()
{
  Led_Pwm pwmDemo;

  pwmDemo.demo();
}

void initAccelDemo()
{
  uint8_t accelID = 0x00000000;
  LIS302DL accel;
  accelID = accel.readAccelID();
  Delay(2000);
}

void initButtonInt()
{
  GPIO_InitTypeDef GPIO_InitStructure;
  EXTI_InitTypeDef EXTI_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;

  /* Enable the BUTTON Clock */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

  /* Configure Button pin as input */
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_Init(GPIOB, &GPIO_InitStructure);  
  
  /* Connect Button EXTI Line to Button GPIO Pin */
  SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource3);

  /* Configure Button EXTI line */
  EXTI_InitStructure.EXTI_Line = EXTI_Line3;
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  /* Enable and set Button EXTI Interrupt to the lowest priority */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x01;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

  NVIC_Init(&NVIC_InitStructure);

}

void EXTI0_IRQHandler(void)
{
  if(EXTI_GetITStatus(EXTI_Line0) != RESET)
  {
    if(color == 0x0000)
    {
      color = 0xFFFF;
    }
    
    tft.fillRectangle(0, 0, 239, 319, color);
    color--;
    EXTI_ClearITPendingBit(EXTI_Line0);

    
  }
}