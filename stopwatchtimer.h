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
public:
    explicit StopWatchTimer(QObject *parent = 0);

    void start();
    void stop();
    void clear();

    string formatNumbers(int);

signals:

public slots:
};

#endif // STOPWATCHTIMER_H
