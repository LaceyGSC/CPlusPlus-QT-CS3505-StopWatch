#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatchtimer.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void zeroOut();
    ~MainWindow();
int test = 0;
private slots:
    void on_pushButton_clicked();
    void upDateTime();

private:
    StopWatchTimer* timer = new StopWatchTimer(this);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
