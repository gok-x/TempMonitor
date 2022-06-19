#include "Subject.hpp"

Subject::Subject(){}
Subject::~Subject(){}

void Subject::Attach(std::shared_ptr<Observer> o){
    observers.push_back(o);
}

void Subject::Detach(std::shared_ptr<Observer> o){
    for(auto itr = observers.begin(); itr != observers.end();){
        if(*itr == o){
            itr = observers.erase(itr);
        } else {
	    itr++;
	}
    }
}

void Subject::Notify(){
    for(auto itr = observers.begin(); itr != observers.end(); itr++){
        (*itr)->Update(this);
    }
}
