#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->hundredLCD->display("00");
    ui->secondLCD->display("00");
    ui->minuteLCD->display("00");

    //connect buttons to the StopWatchTimer
    connect(ui->clear_button,SIGNAL(clicked(bool)),&timer,SLOT(resetClock()));
    connect(ui->startStop_button,SIGNAL(clicked(bool)),&timer,SLOT(start_stop()));
    connect(&timer,SIGNAL(updateButton(QString)),this,SLOT(on_pushButton_clicked(QString)));

    //connects the StopWatchTimer to the display
    connect(&timer,SIGNAL(updateHundred(QString)),ui->hundredLCD,SLOT(display(QString)));
    connect(&timer,SIGNAL(updateSecond(QString)),ui->secondLCD,SLOT(display(QString)));
    connect(&timer,SIGNAL(updateMinute(QString)),ui->minuteLCD,SLOT(display(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(QString buttonValue)
{
    ui->startStop_button->setText(buttonValue);
}


