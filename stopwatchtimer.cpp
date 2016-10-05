#include "stopwatchtimer.h"

StopWatchTimer::StopWatchTimer(QObject *parent) : QObject(parent)
{
    timer.start(10);
    time.start();
}

std::string StopWatchTimer::formatedNumbers(){
    std::string output;
    int temp = time.elapsed()+offset;
    int minutes = temp/60000;
    int seconds = (temp/1000)%60;
    int hundredths = (temp/10)%100;

    output = twoDigitNumber(minutes);
    output += ':';
    output += twoDigitNumber(seconds);
    output += ':';
    output += twoDigitNumber(hundredths);
    return output;
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
    return output;
}

//starts or stops the stopwatch, keeps track of offset time
void StopWatchTimer::start_stop(){
    if(stopped){
        time.start();
    } else {
      stopped = true;
      offset += time.restart();
    }
}

//clears stopwatched
void StopWatchTimer::clear(){
   stopped = true;
   offset = 0;
   time.start();
}
