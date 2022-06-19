#ifndef _PERIODICMEASURER_HPP_
#define _PERIODICMEASURER_HPP_

#include <memory>
#include "Measurer.hpp"
#include "Thermistor.hpp"
#include "TemperatureData.hpp"

class PeriodicMeasurer : public Measurer {

public:
  PeriodicMeasurer(std::shared_ptr<Thermistor>, std::shared_ptr<TemperatureData>, int i = 1);
  
  virtual int MeasureTemperature();

private:
  std::shared_ptr<Thermistor> thermistor;
  std::shared_ptr<TemperatureData> temperatureData;
  int interval;
};

#endif
