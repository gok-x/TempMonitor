#include <stdio.h>
#include <memory>
#include "TemperatureData.hpp"
#include "Console.hpp"
#include "PeriodicMeasurer.hpp"
#include "Thermistor.hpp"
#include "MqttTemperaturePublisher.hpp"

int
main(int argc, char *argv[])
{
    TemperatureData* temperatureData(new TemperatureData());

    Console* console(new Console(temperatureData));
    
    Thermistor* thermistor(new Thermistor());
    Measurer* measurer(new PeriodicMeasurer(thermistor, temperatureData));
    MqttTemperaturePublisher* mqttPublisher(new MqttTemperaturePublisher("tcp://192.168.11.12:1883", "homeIoT/coolant", "DesktopPC_1"));
    temperatureData->Attach(mqttPublisher);
    if(measurer->MeasureTemperature() == -1){
        printf("error\n");
        temperatureData->Detach(mqttPublisher);
        return 0;
    }
    temperatureData->Detach(mqttPublisher);
    return 0;
}
