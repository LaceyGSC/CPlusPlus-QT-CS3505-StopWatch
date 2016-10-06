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

    connect(ui->clear_button,SIGNAL(clicked(bool)),&timer,SLOT(resetClock()));//   connect(&timer,SIGNAL(resetClock()),ui->clear_button,SLOT(click()));
    connect(ui->startStop_button,SIGNAL(clicked(bool)),&timer,SLOT(start_stop()));

    connect(&timer,SIGNAL(updateHundred(QString)),ui->hundredLCD,SLOT(display(QString)));
    connect(&timer,SIGNAL(updateSecond(QString)),ui->secondLCD,SLOT(display(QString)));
    connect(&timer,SIGNAL(updateMinute(QString)),ui->minuteLCD,SLOT(display(QString)));

}

MainWindow::~MainWindow()
{
}

void MainWindow::on_pushButton_clicked()
{

}


