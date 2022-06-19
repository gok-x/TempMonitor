#ifndef _THERMISTOR_H_
#define _THERMISTOR_H_

#include "MCP3002.hpp"

#define CONST_B  3435
#define CONST_T  25
#define CONST_R  10000
#define ABSTEMP  273
#define NUMSHOTS 10

class Thermistor : public MCP3002 {

public:
  void  SetRefResistance(float refResistance);       // Registance which devides voltage
  float GetTemperature(int numshots = NUMSHOTS);     // GetTemperature
  ~Thermistor();                                     // Destructor

private:
  float temperature;
  float resistance;
  float refResistance;
};

inline
void
Thermistor::SetRefResistance(float theRefResistance)
{
  refResistance = theRefResistance;
}

#endif
