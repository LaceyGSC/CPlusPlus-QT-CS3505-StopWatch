#ifndef STOPWATCHTIMER_H
#define STOPWATCHTIMER_H
#include <QObject>
#include <QTimerEvent>
#include <QString>
#include <QTimer>
#include <QTime>
#include <string>


class StopWatchTimer : public QObject
{
    Q_OBJECT
private:
    QTime time;
    QTimer* timer;
    bool stopped;
    unsigned long long offset;

    //formats ints into two digit strings
    QString twoDigitNumber(int);


public:
    explicit StopWatchTimer();

    //returns a formatted string of numbers which can be placed in the textbox
    std::string formatedNumbers();
    QString getHundred(int temp);
    QString getSecond(int temp);
    QString getMinute(int temp);

signals:
    void updateHundred(QString output);
    void updateMinute(QString output);
    void updateSecond(QString output);

    //clears the function
   // void resetClock();

public slots:
    //contains logic to start and stop timer.
    void start_stop();
    void updateClock();
    void resetClock();
};

#endif // STOPWATCHTIMER_H
