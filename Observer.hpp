#ifndef _OBSERVER_HPP_
#define _OBSERVER_HPP_

#include <memory>


class Subject;

class Observer {
public:
    virtual ~Observer();
    virtual void Update(std::shared_ptr<Subject> theChangedSubject) = 0;

protected:
    Observer();
};

#endif
