#ifndef _TEMPERATUREDATA_HPP_
#define _TEMPERATUREDATA_HPP_

#include "Subject.hpp"
#include <vector>
#include <stdlib.h>
#include <time.h>

class TemperatureData : public Subject{

public:
    TemperatureData(int storeNum = 60);

    virtual void PushBackData(struct tm*, float);
    virtual float GetLastTemperatureData();
    virtual struct tm* GetLastTime();

private:
    std::vector<float> temperatureData;
    std::vector<struct tm*> timeData;
    int storableNum;
};

#endif
