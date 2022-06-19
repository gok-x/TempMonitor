#ifndef _CONSOLE_HPP_
#define _CONSOLE_HPP_

#include <stdio.h>
#include <memory>
#include "TemperatureData.hpp"
#include "Observer.hpp"
#include "View.hpp"


class Console: public Observer, public View, public std::enable_shared_from_this<Console>{
public:
    Console(std::shared_ptr<TemperatureData>);
    virtual ~Console();
    
    virtual void Update(Subject*);

    virtual void Draw();

private:
    std::weak_ptr<TemperatureData> subject;

};

#endif
