#ifndef _SUBJECT_HPP_
#define _SUBJECT_HPP_

#include "Observer.hpp"
#include <list> 
#include <memory>

class Subject {

public:
  virtual ~Subject();
  
  virtual void Attach(Observer*);
  virtual void Detach(Observer*);
  virtual void Notify();

protected:
  Subject();

private:
  std::list<Observer*> observers;

};

#endif
