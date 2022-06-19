#include <stdio.h>
#include <memory>
#include "TemperatureData.hpp"
#include "Console.hpp"
#include "PeriodicMeasurer.hpp"
#include "Thermistor.hpp"

int
main(int argc, char *argv[])
{
    TemperatureData* temperatureData(new TemperatureData());

    Console* console(new Console(temperatureData));
    
    Thermistor* thermistor(new Thermistor());
    Measurer* measurer(new PeriodicMeasurer(thermistor, temperatureData));
    if(measurer->MeasureTemperature() == -1){
        printf("error\n");
        return 0;
    }
    return 0;
}
