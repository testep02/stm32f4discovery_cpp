#include "main.h"

class Screen
{
  public:
    Screen();
    ~Screen();

    void setBgColor(uint16_t color);
    uint16_t getBgColor();
    void setFgColor(uint16_t color);
    uint16_t getFgColor();

  private:
    uint16_t bgColor;
    uint16_t fgColor;
};