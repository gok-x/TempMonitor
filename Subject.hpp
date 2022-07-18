#ifndef _SUBJECT_HPP_
#define _SUBJECT_HPP_

#include "Observer.hpp"
#include <list> 
#include <memory>

class Subject : public std::enable_shared_from_this<Subject>{

public:
  virtual ~Subject();
  
  virtual void Attach(std::unique_ptr<Observer>);
  virtual void Detach(std::unique_ptr<Observer>);
  virtual void Notify();

protected:
  Subject();

private:
  std::list<std::unique_ptr<Observer>> observers;

};

#endif
