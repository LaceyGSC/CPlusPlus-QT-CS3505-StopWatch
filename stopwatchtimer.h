#ifndef STOPWATCHTIMER_H
#define STOPWATCHTIMER_H
#include <QObject>
#include <QTimer>


class StopWatchTimer : public QObject
{
    Q_OBJECT
private:
    QTime time;
    QTimer timer;
    bool stopped;
    unsigned long long offset;
    std::string twoDigitNumber(int);
public:
    explicit StopWatchTimer(QObject *parent = 0);

    //returns a formatted string of numbers which can be placed in the textbox
    std::string formatedNumbers();

signals:

public slots:
    //contains logic to start and stop timer.
    void start_stop();
    //clears the function
    void clear();
};

#endif // STOPWATCHTIMER_H
