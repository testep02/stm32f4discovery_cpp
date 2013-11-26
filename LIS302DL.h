#ifndef __LIS302DL_H__
#define __LIS302DL_H__

extern "C"{
  #include <stm32f4xx_spi.h>
  #include <stm32f4xx.h>
  #include <stm32f4xx_gpio.h>
  #include <stm32f4xx_rcc.h>
}

#define WHO_AM_I              0x0F
#define CTRL_REG1             0x20
#define CTRL_REG2             0x21
#define CTRL_REG3             0x22
#define HP_FILTER_RESET       0x23
#define STATUS_REG            0x27
#define OUT_X                 0x29
#define OUT_Y                 0x2B
#define OUT_Z                 0x2D
#define FF_WU_CFG_1           0x30
#define FF_WU_SRC_1           0x31
#define FF_WU_THS_1           0x32
#define FF_WU_DURATION_1      0x33
#define FF_WU_CFG_2           0x34
#define FF_WU_SRC_2           0x35
#define FF_WU_THS_2           0x36
#define FF_WU_DURATION_2      0x37
#define CLICK_CFG             0x38
#define CLICK_SRC             0x39
#define CLICK_THSY_X          0x3B
#define CLICK_THSZ            0x3C
#define CLICK_TIMELIMIT       0x3D
#define CLICK_LATENCY         0x3E
#define CLICK_WINDOW          0x3F
#define DUMMY_BYTE            0x00
#define SELECT_ACCEL          GPIOE->BSRRH = 0x0008
#define DESELECT_ACCEL        GPIOE->BSRRL = 0x0008

class LIS302DL
{
  public:
    LIS302DL();
    ~LIS302DL();
    int32_t readAccelID();
    int32_t readAccelX();
    int32_t readAccelY();
    int32_t readAccelZ();
    int32_t readAccelXYZ();
    void configAccelClick();
    void configAccelDoubleClick();

  private:
    void configAccelSPI();
    void initAccel();
    uint8_t accelSendByte(uint8_t byte);
    uint8_t accelGetByte();
    void accelWrite(uint8_t reg, uint8_t* data, uint8_t count);
    void accelRead(uint8_t reg, uint8_t* data, uint8_t count);
    uint8_t accelId;
    const static uint32_t LIS302DL_FLAG_TIMEOUT = 0x1000;
};

#endif