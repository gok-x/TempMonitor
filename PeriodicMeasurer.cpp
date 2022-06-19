#include "PeriodicMeasurer.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

PeriodicMeasurer::PeriodicMeasurer(std::shared_ptr<Thermistor> therm, std::shared_ptr<TemperatureData> temp, int i){
  thermistor = therm;
  temperatureData = temp;
  interval = i;
}

int PeriodicMeasurer::MeasureTemperature(){
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

  while(1){
    now = time(NULL);
    pnow = localtime(&now);
    
    temperature = thermistor->GetTemperature();

    temperatureData->PushBackData(pnow, temperature);
    
    sleep(interval);
  }
  return 0;
}
