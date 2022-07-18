#ifndef _SINGLEMEASURER_HPP_
#define _SINGLEMEASURER_HPP_

#include <memory>
#include "Measurer.hpp"
#include "Thermistor.hpp"
#include "TemperatureData.hpp"

class SingleMeasurer : public Measurer {

public:
  SingleMeasurer(std::shared_ptr<Thermistor>, std::shared_ptr<TemperatureData>);
  
  virtual int MeasureTemperature();

private:
  std::shared_ptr<Thermistor> thermistor;
  std::shared_ptr<TemperatureData> temperatureData;
};

#endif