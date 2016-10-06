#include "stopwatchtimer.h"

StopWatchTimer::StopWatchTimer(QObject *parent) : QObject(parent)
{
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this, SLOT(timerUp()));
    timer->start(10);
    time.start();
}

std::string StopWatchTimer::getHundred(int temp)
{
    std::string output;
    int hundredths = (temp/10)%100;
    output = twoDigitNumber(hundredths);
    return output;
}

std::string StopWatchTimer::getSecond(int temp)
{
    int seconds = (temp/1000)%60;
    std::string output = twoDigitNumber(seconds);
    return output;
}

std::string StopWatchTimer::getMinute(int temp)
{
    std::string output;
    int minutes = temp/60000;
    output = twoDigitNumber(minutes);
    return output;

}


std::string StopWatchTimer::twoDigitNumber(int input)
{
    input=input%100;
    std::string output;
    if(input<10)
    {
        output+="0";
    }
    else
    {
        output+=input/10 + 48; // add first ascii charactor
        input = input % 10;
    }
    output+=input+48; //add ascii charactor
    return output;
}

//starts or stops the stopwatch, keeps track of offset time
void StopWatchTimer::start_stop()
{
    if(stopped){
        time.start();
    } else {
      stopped = true;
      offset += time.restart();
    }
}

void StopWatchTimer::timerUp(){
    emit updatedClock();
}

//clears stopwatched
void StopWatchTimer::clear(){
   stopped = true;
   offset = 0;
   time.start();
}
