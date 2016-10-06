#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new StopWatchTimer;

    ui->hundredLCD->display("00");
    ui->secondLCD->display("00");
    ui->minuteLCD->display("00");

    connect(ui->startStop_button,SLOT(click()),timer,SIGNAL(start_stop()));
    connect(ui->clear_button,SLOT(click()),timer,SIGNAL(clear()));
    connect(this,SLOT(upDateTime()),timer,SIGNAL(updatedClock()));
}

void MainWindow::upDateTime(){
    //throw new std::string("Timer_Works!");
    TimeSet time = timer->getTime();
    ui->hundredLCD->display(QString::fromStdString(time.hndr));
    ui->secondLCD->display(QString::fromStdString(time.sec));
    ui->minuteLCD->display(QString::fromStdString(time.min));
    ui->hundredLCD->show();

}

MainWindow::~MainWindow()
{
    delete timer;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}

