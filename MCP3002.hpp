#ifndef _MCP3002_H_
#define _MCP3002_H_
/*
  MCP3002 specification : http://ww1.microchip.com/downloads/en/DeviceDoc/21294E.pdf
*/

#define MCP3002_START_BIT        0b01000000
#define MCP3002_SGL_BIT          0b00100000
#define MCP3002_DIFF_BIT         0b00000000
#define MCP3002_SIGN_BIT         0b00000000
#define MCP3002_ODD_BIT          0b00010000
#define MCP3002_MSBF_BIT         0b00001000

#define MCP3002_SPEED            500000       // SPI clock range : 500,000 through 32,000,000
#define MCP3002_CHANNEL0         0
#define RP_SPI_CHANNEL0          0            // Raspberry Pi has two SPI channel.
#define DATALEN                  2
#define MCP3002_RESOLUTION       1024
#define MCP3002_INPUTMODE_SINGLE 1            // Input is from a single channel.
#define MCP3002_INPUTMODE_DIFF   0            // Input is the difference between both channels.

class MCP3002 {

public:
  MCP3002(                                    // Constructor with default value
    int theChannelOfRP = RP_SPI_CHANNEL0,
    int theMCP3002lChannel = MCP3002_CHANNEL0,
    int theMCP3002Speed = MCP3002_SPEED,
    int theMCP3002InputMode = MCP3002_INPUTMODE_DIFF);
  virtual ~MCP3002();                         // Destructor
  int SPISetUp();                             // SPI setup
  int WriteRead();                            // Send setting and recieve return value.

private:
  struct MCP3002Parameters{
    int channel;                              // A/D converter channel 0/1
    int speed;                                // SPI speed
    int inputMode;                            // A/D converter mode 1(Single-end)/0(Pseudo-differential)
  } MCP3002Param;                            // Struct for A/D channel and SPI speed with RP
  unsigned char data[DATALEN];                // buffer to send/recieve for SPI communication
  int channelOfRP;                            // channel for RP communication
};

#endif
