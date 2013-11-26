#include"GraphicsLib.h"

GraphicsLib::GraphicsLib(TftDriver driver)
{
  tft = driver;
}

GraphicsLib::~GraphicsLib()
{

}

void GraphicsLib::setBgColor(unsigned int backgroundColor)
{
  bgColor = backgroundColor;
}

void GraphicsLib::setFgColor(unsigned int foregroundColor)
{
 fgColor = foregroundColor;
}

unsigned int GraphicsLib::getBgColor()
{
  return bgColor;
}

unsigned int GraphicsLib::getFgColor()
{
  return fgColor;
}

void GraphicsLib::setPixel(unsigned int poX, unsigned int poY, unsigned int color)
{
  tft.setXY(poX, poY);
  tft.sendData(color);
}

void GraphicsLib::fillRectangle(unsigned int poX, unsigned int poY,
                                unsigned int width, unsigned int length,
                                unsigned int color)
{
  unsigned int i;
  
  for(i=0;i<width;i++)
  {
    drawHorizontalLine(poX, poY+i, length, color);
  }
}

void GraphicsLib::fillCircle(unsigned int poX, unsigned int poY, unsigned int radius, unsigned int color)
{

}

void GraphicsLib::drawCircle(unsigned int poX, unsigned int poY, unsigned int radius, unsigned int color)
{

}

void GraphicsLib::drawRectangle(unsigned int poX, unsigned int poY,
                   unsigned int width, unsigned int length,
                   unsigned int color)
{
  drawHorizontalLine(poX, poY, length, color);
  drawHorizontalLine(poX, poY+width, length, color);
 
  drawVerticalLine(poX, poY, width,color);
  drawVerticalLine(poX + length, poY, width,color);
}

void GraphicsLib::drawLine(unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1,
              unsigned int color)
{

}

void GraphicsLib::drawVerticalLine(unsigned int poX, unsigned int poY, unsigned int length, 
                      unsigned int color)
{

}

void GraphicsLib::drawHorizontalLine(unsigned int poX, unsigned int poY, unsigned int length,
                        unsigned int color)
{
  unsigned int i;
  if(poX <0)
    poX = 0;
  if(poX>239)
    poX = 239;
 
  if(poY <0)
    poY = 0;
  if(poY>319)
    poY = 319;
 
  tft.setXY(poX,poY);
  //tft.setOrientation(0);
  
  if(length+poX>MAX_X)
  {
    length=MAX_X-poX;
  }
  for(i=0;i<length;i++)
  {
    tft.sendData(color);
  }
}

void GraphicsLib::drawChar(unsigned char ascii, unsigned int poX, unsigned int poY, unsigned int size)
{
  unsigned char i;
  unsigned char temp;
  unsigned char f;
  
  tft.setXY(poX,poY);
  tft.setOrientation(1);
  
  if((ascii < 0x20)||(ascii > 0x7e))//Unsupported char.
  {
    ascii = '?';
  }
  for(i=0;i<8;i++)
  {
    temp = simpleFont[ascii-0x20][i];
    for(f=0;f<8;f++)
    {
      if((temp>>f)&0x01)
      {
        fillRectangle(poX+i*size, poY+f*size, size, size, fgColor);
      }
      else
      {
        fillRectangle(poX+i*size, poY+f*size, size, size, bgColor);
      }
    }
  }
}

