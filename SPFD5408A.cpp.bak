#include "SPFD5408A.h"

extern "C"{
  #include "stm32f4xx_delay.h"
}

SPFD5408A::SPFD5408A(): TftDriver()
{
  configTftFsmc();
  fsmcSetup();
  initTft();
}

SPFD5408A::~SPFD5408A()
{

}

void SPFD5408A::configTftFsmc()
{
  GPIO_InitTypeDef GPIO_InitStructure;

  /* Enable GPIO D and E clocks */
  RCC_AHB1PeriphClockCmd(
                  RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOD | RCC_AHB1Periph_GPIOE | RCC_AHB1Periph_GPIOA,
                  ENABLE);

  // Create GPIO D Init structure for used pins
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_7
                  | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

  /* Initialize pins */
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  /* Configure GPIO D pins as FSMC alternate functions */
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource4, GPIO_AF_FSMC); // NOE -> RD
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource5, GPIO_AF_FSMC); // NWE -> WR
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource7, GPIO_AF_FSMC); // NE1 -> CS
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource8, GPIO_AF_FSMC); // D13 -> D5
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource9, GPIO_AF_FSMC); // D14 -> D6
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource10, GPIO_AF_FSMC); // D15 -> D7
  GPIO_PinAFConfig(GPIOD, GPIO_PinSource11, GPIO_AF_FSMC); // A16 -> RS

  /* Create GPIO E Init structure for used pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13
                  | GPIO_Pin_14 | GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

  /* Initialize GPIOE pins */
  GPIO_Init(GPIOE, &GPIO_InitStructure);

  /* Configure GPIO E pins as FSMC alternate functions */
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_FSMC); // D8  -> D0
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource12, GPIO_AF_FSMC); // D9  -> D1
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_FSMC); // D10 -> D2
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_FSMC); // D11 -> D3
  GPIO_PinAFConfig(GPIOE, GPIO_PinSource15, GPIO_AF_FSMC); // D12 -> D4

  /* Configure Reset Pin */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

  /* Initialize GPIOE pins */
  GPIO_Init(GPIOE, &GPIO_InitStructure);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;

  GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void SPFD5408A::fsmcSetup()
{
  FSMC_NORSRAMInitTypeDef FSMC_NORSRAMInitStructure;
  FSMC_NORSRAMTimingInitTypeDef FSMC_NORSRAMTimingInitStructureRead;
  FSMC_NORSRAMTimingInitTypeDef FSMC_NORSRAMTimingInitStructureWrite;

  /* Enable FSMC Clock */
  RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC, ENABLE);

  /* Define Read timing parameters */
  FSMC_NORSRAMTimingInitStructureRead.FSMC_AddressSetupTime = 1;
  FSMC_NORSRAMTimingInitStructureRead.FSMC_AddressHoldTime = 0;
  FSMC_NORSRAMTimingInitStructureRead.FSMC_DataSetupTime = 15;
  FSMC_NORSRAMTimingInitStructureRead.FSMC_BusTurnAroundDuration = 0;
  FSMC_NORSRAMTimingInitStructureRead.FSMC_CLKDivision = 1;
  FSMC_NORSRAMTimingInitStructureRead.FSMC_DataLatency = 0;
  FSMC_NORSRAMTimingInitStructureRead.FSMC_AccessMode = FSMC_AccessMode_A;

  /* Define Write Timing parameters */
  FSMC_NORSRAMTimingInitStructureWrite.FSMC_AddressSetupTime = 2; // 2
  FSMC_NORSRAMTimingInitStructureWrite.FSMC_AddressHoldTime = 0; // 0
  FSMC_NORSRAMTimingInitStructureWrite.FSMC_DataSetupTime = 5; // 5
  FSMC_NORSRAMTimingInitStructureWrite.FSMC_BusTurnAroundDuration = 0;
  FSMC_NORSRAMTimingInitStructureWrite.FSMC_CLKDivision = 1;
  FSMC_NORSRAMTimingInitStructureWrite.FSMC_DataLatency = 0;
  FSMC_NORSRAMTimingInitStructureWrite.FSMC_AccessMode = FSMC_AccessMode_A;

  /* Define protocol type */
  FSMC_NORSRAMInitStructure.FSMC_Bank = FSMC_Bank1_NORSRAM1; //Bank1
  FSMC_NORSRAMInitStructure.FSMC_DataAddressMux = FSMC_DataAddressMux_Disable; //No mux
  FSMC_NORSRAMInitStructure.FSMC_MemoryType = FSMC_MemoryType_SRAM; //SRAM type
  FSMC_NORSRAMInitStructure.FSMC_MemoryDataWidth = FSMC_MemoryDataWidth_16b; //16 bits wide
  FSMC_NORSRAMInitStructure.FSMC_BurstAccessMode =
                  FSMC_BurstAccessMode_Disable; //No Burst
  FSMC_NORSRAMInitStructure.FSMC_AsynchronousWait =
                  FSMC_AsynchronousWait_Disable; // No wait
  FSMC_NORSRAMInitStructure.FSMC_WaitSignalPolarity =
                  FSMC_WaitSignalPolarity_Low; //Don'tcare
  FSMC_NORSRAMInitStructure.FSMC_WrapMode = FSMC_WrapMode_Disable; //No wrap mode
  FSMC_NORSRAMInitStructure.FSMC_WaitSignalActive =
                  FSMC_WaitSignalActive_BeforeWaitState; //Don't care
  FSMC_NORSRAMInitStructure.FSMC_WriteOperation = FSMC_WriteOperation_Enable;
  FSMC_NORSRAMInitStructure.FSMC_WaitSignal = FSMC_WaitSignal_Disable; //Don't care
  FSMC_NORSRAMInitStructure.FSMC_ExtendedMode = FSMC_ExtendedMode_Enable; //Allow distinct Read/Write parameters
  FSMC_NORSRAMInitStructure.FSMC_WriteBurst = FSMC_WriteBurst_Disable; //Don't care

  // Set read timing structure
  FSMC_NORSRAMInitStructure.FSMC_ReadWriteTimingStruct =
                  &FSMC_NORSRAMTimingInitStructureRead;

  // Set write timing structure
  FSMC_NORSRAMInitStructure.FSMC_WriteTimingStruct =
                  &FSMC_NORSRAMTimingInitStructureWrite;

  // Initialize FSMC for read and write
  FSMC_NORSRAMInit(&FSMC_NORSRAMInitStructure);

  // Enable FSMC
  FSMC_NORSRAMCmd(FSMC_Bank1_NORSRAM1, ENABLE);
}

void SPFD5408A::initTft()
{
  sendCommand(0x0000);
  sendData(0x0001);
  // TE Delay(100,ms);

  sendCommand(0x0001);
  sendData(0x0100);
  sendCommand(0x0002);
  sendData(0x0700);
  sendCommand(0x0003);
  sendData(0x1030);
  sendCommand(0x0004);
  sendData(0x0000);
  sendCommand(0x0008);
  sendData(0x0302);
  sendCommand(0x000A);
  sendData(0x0000);
  sendCommand(0x000C);
  sendData(0x0000);
  sendCommand(0x000D);
  sendData(0x0000);
  sendCommand(0x000F);
  sendData(0x0000);

  // TE Delay(100, ms);
  //power on sequence VGHVGL
  sendCommand(0x0030);
  sendData(0x0000);
  sendCommand(0x0031);
  sendData(0x0405);
  sendCommand(0x0032);
  sendData(0x0203);
  sendCommand(0x0035);
  sendData(0x0004);
  // added
  sendCommand(0x0036);
  sendData(0x0B07);
  sendCommand(0x0037);
  sendData(0x0000);
  sendCommand(0x0038);
  sendData(0x0405);
  sendCommand(0x0039);
  sendData(0x0203);
  sendCommand(0x003c);
  sendData(0x0004);
  sendCommand(0x003d);
  sendData(0x0B07);
  sendCommand(0x0020);
  sendData(0x0000);
  sendCommand(0x0021);
  sendData(0x0000);
  sendCommand(0x0050);
  sendData(0x0000);
  sendCommand(0x0051);
  sendData(0x00ef);
  sendCommand(0x0052);
  sendData(0x0000);
  sendCommand(0x0053);
  sendData(0x013f);
  // /added
      // TE Delay(100, ms);

  sendCommand(0x0060);
  sendData(0xa700);
  sendCommand(0x0061);
  sendData(0x0001);
  sendCommand(0x0090);
  sendData(0x003a);
  sendCommand(0x0095);
  sendData(0x021E);
  sendCommand(0x0080);
  sendData(0x0000);
  sendCommand(0x0081);
  sendData(0x0000);
  sendCommand(0x0082);
  sendData(0x0000);
  sendCommand(0x0083);
  sendData(0x0000);
  sendCommand(0x0084);
  sendData(0x0000);
  sendCommand(0x0085);
  sendData(0x0000);
  sendCommand(0x00FF);
  sendData(0x0001);
  sendCommand(0x00B0);
  sendData(0x140D);
  sendCommand(0x00FF);
  sendData(0x0000);
  // TE Delay(100, ms);
  sendCommand(0x0007);
  sendData(0x0133);
  // TE Delay(50, ms);
  exitStandby();
  sendCommand(0x0022);

  for( int i = 0; i < 76800; i++ )
  {
    sendData( 0xF810 );
  }
}

void SPFD5408A::sendCommand(unsigned int data)
{
  pushDataReg(data >> 8);
  pushDataReg(data);
}

void SPFD5408A::sendData(unsigned int data)
{
  pushDataRam(data >> 8);
  pushDataRam(data);
}

void SPFD5408A::pushDataReg(unsigned char data)
{
  LCD_REG = data << 8;
}

void SPFD5408A::pushDataRam(unsigned char data)
{
  LCD_RAM = data << 8;
}

void SPFD5408A::exitStandby()
{
  sendCommand(0x0010);
  sendData(0x14E0);
  // TE Delay(100, ms);
  sendCommand(0x0007);
  sendData(0x0133);
}

void SPFD5408A::setOrientation(unsigned int HV)
{
  sendCommand(0x03);
  if(HV==1)//vertical
  {
    sendData(0x5038);
  }
  else//horizontal
  {
    sendData(0x5030);
  }
  sendCommand(0x0022); //Start to write to display RAM
}

void SPFD5408A::setXY(unsigned int poX, unsigned int poY)
{
  if(poX <0)
    poX = 0;
  if(poX>239)
    poX = 239;

  if(poY <0)
    poY = 0;
  if(poY>319)
    poY = 319;

  sendCommand(0x0020);//X
  sendData(poX);

  sendCommand(0x0021);//Y
  sendData(poY);

  sendCommand(0x0022);//Start to write to display RAM
}