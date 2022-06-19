/*
  MCP3002 specification : http://ww1.microchip.com/downloads/en/DeviceDoc/21294E.pdf
*/

#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include "MCP3002.hpp"

MCP3002::MCP3002(int theChannelOfRP, int theMCP3002lChannel, int theMCP3002Speed, int theMCP3002InputMode)
{
  // Parameters
  channelOfRP          = theChannelOfRP;
  MCP3002Param.channel = theMCP3002lChannel;
  MCP3002Param.speed   = theMCP3002Speed;
  MCP3002Param.inputMode = theMCP3002InputMode;
}

int
MCP3002::SPISetUp()
{
  return wiringPiSPISetup(channelOfRP, MCP3002Param.speed);
}

int
MCP3002::WriteRead()
{
  // set buffer for inquiry
  data[0]  = MCP3002_START_BIT | MCP3002_DIFF_BIT | MCP3002_SIGN_BIT | MCP3002_MSBF_BIT;

  // if host requests to use other than differential mode of MCP3002, set to use single-end mode
  data[0] |= (MCP3002Param.inputMode != MCP3002_INPUTMODE_DIFF) ? MCP3002_SGL_BIT : 0;

  // if host requests to use other than channel #0 of MCP3002, set to use channel #1
  data[0] |= (MCP3002Param.channel != MCP3002_CHANNEL0) ? MCP3002_ODD_BIT : 0;

  wiringPiSPIDataRW(channelOfRP, data, DATALEN);  // Write and receive from same buffer
  return (int)((data[0] << 8 | data[1]) & 0x3FF);
}

MCP3002::~MCP3002()
{
}
