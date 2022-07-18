#include "SingleMeasurer.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

SingleMeasurer::SingleMeasurer(std::shared_ptr<Thermistor> therm, std::shared_ptr<TemperatureData> temp){
  thermistor = therm;
  temperatureData = temp;
}

int SingleMeasurer::MeasureTemperature(){
  // current time
  time_t now;
  struct tm *pnow;
  
  // temperature
  float temperature;

  if(thermistor == NULL || temperatureData == NULL){
    printf("Instance does not exist.\n");
    return -1;
  }

  // initial setup before SPI communication start
  thermistor->SPISetUp();
  thermistor->SetRefResistance(10000.0);

  now = time(NULL);
  pnow = localtime(&now);
    
  temperature = thermistor->GetTemperature();

  temperatureData->PushBackData(pnow, temperature);
    
  return 0;
}
