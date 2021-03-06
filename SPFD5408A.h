#ifndef __SPFD5408A_H__
#define __SPFD5408A_H__

#include "TftDriver.h"

extern "C"{
  #include <stm32f4xx_gpio.h>
  #include <stm32f4xx_fsmc.h>
  #include <stm32f4xx_rcc.h>
}

#define LCD_REG           (*((volatile short *) 0x60000000))
#define LCD_RAM           (*((volatile short *) 0x60020000))

class SPFD5408A : public TftDriver
{
  public:
    SPFD5408A();
    virtual ~SPFD5408A();
    virtual void configTftFsmc();
    virtual void fsmcSetup();
    virtual void initTft();
    virtual void tftReset();
    virtual void sendCommand(unsigned int data);
    virtual void sendData(unsigned int data);
    virtual void pushDataReg(unsigned char data);
    virtual void pushDataRam(unsigned char data);
    virtual void exitStandby();
    virtual void setOrientation(unsigned int HV);
    virtual void setXY(unsigned int poX, unsigned int poY);
};

#endif