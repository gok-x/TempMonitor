#include "Console.hpp"

Console::Console(std::shared_ptr<TemperatureData> t){
    subject = t;
    subject.lock()->Attach(weak_from_this().lock());
}

Console::~Console(){
    subject.lock()->Detach(weak_from_this().lock());
}

void Console::Update(Subject* theChangedSubject){
    if(theChangedSubject == subject.lock().get()){
         Draw();
    }
}

void Console::Draw(){
    struct tm *pnow = subject.lock()->GetLastTime();
    char strDateNow[16];
    char strTimeNow[16];
    sprintf(strDateNow, "%04d-%02d-%02d", pnow->tm_year+1900, pnow->tm_mon+1, pnow->tm_mday);
    sprintf(strTimeNow, "%02d:%02d:%02d", pnow->tm_hour, pnow->tm_min, pnow->tm_sec);
    printf("%s %s %4.2f\n", strDateNow, strTimeNow, subject.lock()->GetLastTemperatureData());
}
