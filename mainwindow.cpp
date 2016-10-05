#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new StopWatchTimer;
    connect(ui->startStop_button,SLOT(click()),timer,SIGNAL(start_stop()));
    connect(ui->clear_button,SLOT(click()),timer,SIGNAL(clear()));
}

MainWindow::~MainWindow()
{
    delete timer;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}
