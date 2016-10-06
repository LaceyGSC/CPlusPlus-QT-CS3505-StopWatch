#include "stopwatchtimer.h"
#include <iostream>

//Constructs the QTimer timer and QTime time
StopWatchTimer::StopWatchTimer(QObject *parent) : QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateClock()));

    timer->start(100);

    offset = 0;

    time.start();
}


//Returns the hundredths of a second of elapsed time as two digit string
QString StopWatchTimer::getHundred(int temp)
{
    QString output;
    int hundredths = (temp/10)%100;
    output += twoDigitNumber(hundredths);
    emit updateHundred(output);
    return output;

}

//Returns the seconds of elapsed time as two digit string
QString StopWatchTimer::getSecond(int temp)
{
    QString output;
    int seconds = (temp/1000)%60;
    output += twoDigitNumber(seconds);
    emit updateSecond(output);

    return output;

}

//Returns the minutes of elapsed time as two digit string
QString StopWatchTimer::getMinute(int temp)
{
    QString output;
    int minutes = temp/60000;
    output = twoDigitNumber(minutes);

    emit updateMinute(output);

    return output;

}

//Takes in the values and formats with leading zero if needed
QString StopWatchTimer::twoDigitNumber(int input)
{
    input=input%100;
    QString output;
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

//Emits the times to the UI for updating
void StopWatchTimer::updateClock()
{

    int temp = time.elapsed()+offset;

    std::cout << temp << "\n";

//    getHundred(temp);
//    getMinute(temp);
//    getSecond(temp);

}

//starts or stops the stopwatch, keeps track of offset time
void StopWatchTimer::start_stop()
{
    if(stopped)
    {
        time.start();
    }
    else
    {
      stopped = true;
      offset += time.restart();
    }
}

//clears stopwatched
void StopWatchTimer::clear()
{
   stopped = true;
   offset = 0;
   time.start();
}
