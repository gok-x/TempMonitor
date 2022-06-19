#ifndef _MEASURER_HPP_
#define _MEASURER_HPP_

class Measurer {
    
public:
  virtual ~Measurer();
  virtual int MeasureTemperature() = 0;

protected:
  Measurer();

};
#endif
