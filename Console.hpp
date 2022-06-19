#ifndef _CONSOLE_HPP_
#define _CONSOLE_HPP_

#include <stdio.h>
#include <memory>
#include "TemperatureData.hpp"
#include "Observer.hpp"
#include "View.hpp"


class Console: public Observer, public View{
public:
    Console(TemperatureData*);
    virtual ~Console();
    
    virtual void Update(Subject*);

    virtual void Draw();

private:
    TemperatureData* subject;

};

#endif
