#include <stdio.h>
#include <memory>
#include "TemperatureData.hpp"
#include "Console.hpp"
#include "PeriodicMeasurer.hpp"
#include "SingleMeasurer.hpp"
#include "Thermistor.hpp"

int
main(int argc, char *argv[])
{
    std::shared_ptr<TemperatureData> temperatureData(new TemperatureData());
    std::shared_ptr<Thermistor> thermistor(new Thermistor());
    auto periodicMeasurer = std::make_unique<PeriodicMeasurer>(thermistor, temperatureData);
    auto singleMeasurer = std::make_unique<SingleMeasurer>(thermistor, temperatureData);
    //std::unique_ptr<Measurer> periodicMeasurer(new PeriodicMeasurer(thermistor, temperatureData));

    {
        auto console = std::make_unique<Console>(temperatureData);
        temperatureData->Attach(std::move(console));

        for(int i = 0; i < 3; i++){
            singleMeasurer->MeasureTemperature();
            printf("%d\n", i);
        }

    }
    
    auto console = std::make_unique<Console>(temperatureData);
    temperatureData->Attach(std::move(console));
     
    if(periodicMeasurer->MeasureTemperature() == -1){
        printf("error\n");
        return 0;
    }
    return 0;
}
