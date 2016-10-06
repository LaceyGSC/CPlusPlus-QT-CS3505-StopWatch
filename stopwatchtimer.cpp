#include "stopwatchtimer.h"
#include <QDebug>

//Constructs the QTimer timer and QTime time
StopWatchTimer::StopWatchTimer()
{
    //Constructs the timer and starts it
    timer = new QTimer(this);
    QTimer::connect(timer, SIGNAL(timeout()), this, SLOT(updateClock()));
    timer->start(10);

    //sets start time to 0
    offset = 0;
    stopped = true;
    time.start();
}

StopWatchTimer::~StopWatchTimer()
{
    delete timer;
}

//Returns the hundredths of a second of elapsed time as two digit string
QString StopWatchTimer::getHundred(int temp)
{
    int hundredths = (temp/10)%100;
    QString output = twoDigitNumber(hundredths);

    emit updateHundred(output);
    return output;
}

//Returns the seconds of elapsed time as two digit string
QString StopWatchTimer::getSecond(int temp)
{
    int seconds = (temp/1000)%60;
    QString output = twoDigitNumber(seconds);

    emit updateSecond(output);
    return output;
}

//Returns the minutes of elapsed time as two digit string
QString StopWatchTimer::getMinute(int temp)
{
    int minutes = temp/60000;
    QString output = twoDigitNumber(minutes);

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

    if(!stopped){
        int temp = time.elapsed()+offset;

        getHundred(temp);
        getMinute(temp);
        getSecond(temp);
    }

}

//starts or stops the stopwatch, keeps track of offset time
void StopWatchTimer::start_stop()
{
    if(stopped)
    {
        time.start();
        stopped = false;
    }
    else
    {
      stopped = true;
      offset += time.restart();
    }
}

//clears stopwatched
void StopWatchTimer::resetClock()
{
   stopped = true;
   offset = 0;

   getHundred(0);
   getMinute(0);
   getSecond(0);

   time.restart();
}
