#ifndef __GRAPHICSLIB_H__
#define __GRAPHICSLIB_H__

#include "TftDriver.h"

#define MIN_X           0
#define MIN_Y           0
#define MAX_X           239
#define MAX_Y           319

class GraphicsLib
{
  public:
    GraphicsLib(TftDriver driver);
    virtual ~GraphicsLib();
    virtual void setPixel(unsigned int poX, unsigned int poY, unsigned int color);
    virtual void fillRectangle(unsigned int poX, unsigned int poY, unsigned int width, unsigned int length, 
                       unsigned int color);
    virtual void fillCircle(unsigned int poX, unsigned int poY, unsigned int radius, unsigned int color);
    virtual void drawCircle(unsigned int poX, unsigned int poY, unsigned int radius, unsigned int color);
    virtual void drawRectangle(unsigned int poX, unsigned int poY,
                               unsigned int width, unsigned int length,
                               unsigned int color);
    virtual void drawLine(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1,
                          unsigned int color);
    virtual void drawVerticalLine(unsigned int poX, unsigned int poY, unsigned int length, 
                                  unsigned int color);
    virtual void drawHorizontalLine(unsigned int poX, unsigned int poY, unsigned int length,
                                    unsigned int color);
    virtual void drawChar(unsigned char ascii, unsigned int poX, unsigned int poY, unsigned int size);
    virtual void setBgColor(unsigned int backgroundColor);
    virtual void setFgColor(unsigned int foregroundColor);
    virtual unsigned int getBgColor();
    virtual unsigned int getFgColor();

  protected:
    TftDriver tft;

    unsigned int bgColor;
    unsigned int fgColor;
    unsigned int simpleFont[][8];
};

#endif