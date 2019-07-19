#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tmr=new QTimer;
    //tmr->setInterval(1000);
            connect(tmr,SIGNAL(timeout()),this,SLOT(UpdateTime()));
            ui->label->setText(QTime::currentTime().toString());
    tmr->start(1000);

    ui->label_3->setText(QString::number(maxS));
    s=0;
QDate dateToday = QDate::currentDate();
QDate dateNewYear(dateToday.year(), 12, 31);

int dateOstalos=dateToday.daysTo(dateNewYear);
ui->statusBar->showMessage("До НГ осталось -"+QString::number(dateOstalos)+" дн");

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::UpdateTime()
{
    ui->label->setText(QTime::currentTime().toString());
    ++s;
    ui->label_3->setText(QString::number(maxS-s));
}
