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

    //formats ints into two digit QStrings
    QString twoDigitNumber(int);


public:
    explicit StopWatchTimer();
    ~StopWatchTimer();

    QString getHundred(int temp);
    QString getSecond(int temp);
    QString getMinute(int temp);

signals:
    void updateHundred(QString output);
    void updateMinute(QString output);
    void updateSecond(QString output);
    void updateButton(QString buttonName);


public slots:
    void start_stop();  //contains logic to start and stop timer.
    void resetClock();  //contains logic to reset the timer.
    void updateClock(); //Emits the times to the UI for updating
};



#endif // STOPWATCHTIMER_H
