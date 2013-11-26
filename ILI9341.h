#ifndef __ILI9341_H__
#define __ILI9341_H__

#include "TftDriver.h"

extern "C"{
  #include <stm32f4xx_gpio.h>
  #include <stm32f4xx_fsmc.h>
  #include <stm32f4xx_rcc.h>
  #include <stm32f4xx_tim.h>
  #include <stm32f4xx.h>
  #include <misc.h>
}

#define LCD_REG             (*((volatile short *) 0x60000000))
#define LCD_RAM             (*((volatile short *) 0x60020000))

#define MIN_X               0
#define MIN_Y               0
#define MAX_X               239
#define MAX_Y               319

// ILI9341 Registers

#define TFT_REG_COL         0x2A
#define TFT_REG_PAGE        0x2B
#define TFT_REG_MEM_WRITE   0x2C
#define TFT_REG_TE_OFF      0x34
#define TFT_REG_TE_ON       0x35
#define TFT_REG_GAMMA_1     0xe0
#define TFT_REG_GAMMA_2     0xe1

#define RESET_PIN           0x0002
#define RESET_PORT          GPIOA

class ILI9341 : public TftDriver
{
  public:
    ILI9341();
    virtual ~ILI9341();
    virtual void configTftFsmc();
    void configBacklightPWM();
    virtual void fsmcSetup();
    virtual void initTft();
    virtual void tftReset();
    virtual void sendRegister(unsigned int reg);
    virtual void sendCommand(unsigned int data);
    virtual void sendData(unsigned int data);
    virtual void pushDataReg(unsigned int data);
    virtual void pushDataRam(unsigned int data);
    virtual void enterSleep();
    virtual void exitSleep();
    virtual void setOrientation(unsigned int HV);
    virtual void setXY(uint16_t poX, uint16_t poY);
    void setCol(uint16_t startX, uint16_t endX);
    void setPage(uint16_t startY, uint16_t endY);
    void fillRectangle(uint16_t poX, uint16_t poY,
                       uint16_t width, uint16_t length,
                       uint16_t color);
    void drawHorizontalLine(uint16_t poX, uint16_t poY, uint16_t length,
                            uint16_t color);
    void setWindow(uint16_t startX, uint16_t startY, uint16_t endX, uint16_t endY);
    void setBacklightON();
    void setBacklightOff();
    void fadeBacklightON(uint16_t duration);
    void fadeBacklightOFF(uint16_t duration);
    void fadeBacklight_DownHalf();
    void fadeBacklight_UpHalf();

  private:
    uint16_t PrescalerValue;
};

#endif