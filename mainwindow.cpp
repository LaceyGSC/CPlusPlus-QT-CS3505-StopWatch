#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    StopWatchTimer timer;

    ui->hundredLCD->display("00");
    ui->secondLCD->display("00");
    ui->minuteLCD->display("00");


//    connect(&timer,SIGNAL(start_stop()),ui->startStop_button, SLOT(click()));
//    connect(&timer,SIGNAL(clear()),ui->clear_button,SLOT(click()));

    connect(&timer,SIGNAL(updateHundred(QString)),ui->hundredLCD,SLOT(display(QString)));
    connect(&timer,SIGNAL(updateSecond(QString)),ui->secondLCD,SLOT(display(QString)));
    connect(&timer,SIGNAL(updateMinute(QString)),ui->minuteLCD,SLOT(display(QString)));
}

MainWindow::~MainWindow()
{
    delete timer;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}


