#ifndef _PERIODICMEASURER_HPP_
#define _PERIODICMEASURER_HPP_

#include <memory>
#include "Measurer.hpp"
#include "Thermistor.hpp"
#include "TemperatureData.hpp"

class PeriodicMeasurer : public Measurer {

public:
  PeriodicMeasurer(Thermistor*, TemperatureData*, int i = 1);
  
  virtual int MeasureTemperature();

private:
  Thermistor* thermistor;
  TemperatureData* temperatureData;
  int interval;
};

#endif
