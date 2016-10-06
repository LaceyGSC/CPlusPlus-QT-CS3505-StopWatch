#ifndef STOPWATCHTIMER_H
#define STOPWATCHTIMER_H
#include <QObject>
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
    std::string twoDigitNumber(int);
public:
    explicit StopWatchTimer(QObject *parent = 0);

    std::string getHundred(int);
    std::string getSecond(int);
    std::string getMinute(int);
    //returns a formatted string of numbers which can be placed in the textbox
    std::string formatedNumbers();

signals:
    void updatedClock();

public slots:
    //contains logic to start and stop timer.
    void start_stop();
    //clears the function
    void clear();

private slots:
    void timerUp();
};

#endif // STOPWATCHTIMER_H
