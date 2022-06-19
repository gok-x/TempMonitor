#ifndef _VIEW_HPP_
#define _VIEW_HPP_

class View{
public:
    virtual ~View();
    virtual void Draw() = 0;

protected:
    View();
};

#endif
