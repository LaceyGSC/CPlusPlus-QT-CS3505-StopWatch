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
    bool cleared;
    unsigned long long pausedAt;
    unsigned long long offset;
    std::string twoDigitNumber(int);
public:
    explicit StopWatchTimer(QObject *parent = 0);

    string formatedNumbers();

signals:

public slots:
    void start_stop();
    void clear();
};

#endif // STOPWATCHTIMER_H
