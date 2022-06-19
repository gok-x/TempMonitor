#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include "Thermistor.hpp"

float
Thermistor::GetTemperature(int numshots)
{
  // From ADC value, culculate thermistar resistance.
  float measuredADVal = 0.0;
  for (int i = 0; i < numshots; i++) {
    measuredADVal += (float)WriteRead();
  }
  measuredADVal /= (float)numshots;

  //printf("ADC ave value = %4.2f\n", measuredADVal);
  resistance = (MCP3002_RESOLUTION - measuredADVal) / measuredADVal * CONST_R;
  //printf("resistance = %4.2f\n", resistance);

  // Intermediate value derived from resistance
  float calcFromResistance = log(resistance / refResistance) / (CONST_B);

  // Intermediate value from reference temperature of using thermistor
  float calcFromConstTemp = 1.0 / (CONST_T + ABSTEMP);

  // Calculate temperature from Intermediate values
  temperature = 1.0 / (calcFromResistance + calcFromConstTemp) - ABSTEMP;

  return temperature;
}

Thermistor::~Thermistor()
{
}
