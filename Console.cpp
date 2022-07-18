#include "Console.hpp"

Console::Console(std::shared_ptr<TemperatureData> t){
    subject = t;
}

Console::~Console(){
}

void Console::Update(std::shared_ptr<Subject> theChangedSubject){
    if(theChangedSubject == subject){
         Draw();
    }
}

void Console::Draw(){
    struct tm *pnow = subject->GetLastTime();
    char strDateNow[16];
    char strTimeNow[16];
    sprintf(strDateNow, "%04d-%02d-%02d", pnow->tm_year+1900, pnow->tm_mon+1, pnow->tm_mday);
    sprintf(strTimeNow, "%02d:%02d:%02d", pnow->tm_hour, pnow->tm_min, pnow->tm_sec);
    printf("%s %s %4.2f\n", strDateNow, strTimeNow, subject->GetLastTemperatureData());
}
