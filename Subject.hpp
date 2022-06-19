#ifndef _SUBJECT_HPP_
#define _SUBJECT_HPP_

#include "Observer.hpp"
#include <list> 
#include <memory>

class Subject {

public:
  virtual ~Subject();
  
  virtual void Attach(std::shared_ptr<Observer>);
  virtual void Detach(std::shared_ptr<Observer>);
  virtual void Notify();

protected:
  Subject();

private:
  std::list<std::shared_ptr<Observer>> observers;

};

#endif
