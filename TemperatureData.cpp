#include "TemperatureData.hpp"

TemperatureData::TemperatureData(int storeNum){
    storableNum = storeNum;
}

void TemperatureData::PushBackData(struct tm *time, float temperature){
    if(timeData.size() < storableNum){
        timeData.push_back(time);
    } else {
        timeData.erase(timeData.begin());
        timeData.push_back(time);
    }

    if(temperatureData.size() < storableNum){
        temperatureData.push_back(temperature);
    }else{
        temperatureData.erase(temperatureData.begin());
        temperatureData.push_back(temperature);
    }

    Notify();
}

float TemperatureData::GetLastTemperatureData(){
    return temperatureData.back();
}

struct tm* TemperatureData::GetLastTime(){
    struct tm *pnow = timeData.back();

    return pnow;
}
