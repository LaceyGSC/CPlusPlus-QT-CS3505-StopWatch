#include "stopwatchtimer.h"

StopWatchTimer::StopWatchTimer(QObject *parent) : QObject(parent)
{
    timer.start(10);
    time.stop();
    time.clear();
}

std::string StopWatchTimer::formatedNumbers(){
}

std::string StopWatchTimer::twoDigitNumber(int input){
    input=input%100;
    std::string output;
    if(input<10){
        output+="0";
    } else{
        output+=input/10 + 48; // add first ascii charactor
        input = input % 10;
    }
    output+=input+48; //add ascii charactor
}

void StopWatchTimer::start_stop(){}
void StopWatchTimer::clear(){}
