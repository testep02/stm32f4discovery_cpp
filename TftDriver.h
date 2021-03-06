#ifndef __TFTDRIVER_H__
#define __TFTDRIVER_H__

class TftDriver
{
  public:
    TftDriver();
    virtual ~TftDriver();
    virtual void configTftFsmc();
    virtual void fsmcSetup();
    virtual void initTft();
    virtual void sendCommand(unsigned int data);
    virtual void sendData(unsigned int data);
    virtual void pushDataReg(unsigned char data);
    virtual void pushDataRam(unsigned char data);
    virtual void exitStandby();
    virtual void setOrientation(unsigned int HV);
    virtual void setXY(unsigned int poX, unsigned int poY);
};

#endif