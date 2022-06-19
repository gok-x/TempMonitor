#include <stdio.h>
#include <memory>
#include "TemperatureData.hpp"
#include "Console.hpp"
#include "PeriodicMeasurer.hpp"
#include "Thermistor.hpp"

int
main(int argc, char *argv[])
{
    std::shared_ptr<TemperatureData> temperatureData(new TemperatureData());

    std::shared_ptr<Console> console(new Console(temperatureData));
    
    std::shared_ptr<Thermistor> thermistor(new Thermistor());
    std::unique_ptr<Measurer> measurer(new PeriodicMeasurer(thermistor, temperatureData));
    if(measurer->MeasureTemperature() == -1){
        printf("error\n");
        return 0;
    }
    return 0;
}
