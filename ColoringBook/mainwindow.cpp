#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect(ui->pushButton_red,SIGNAL(clicked()),this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_red_clicked()
{
   /* QPalette pal = pushButton_red->palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    button->setAutoFillBackground(true);
    button->setPalette(pal);
    button->update();*/
    color=Qt::red;
   // QObject::sender()->objectName();

}

void MainWindow::on_pushButton_blue_clicked()
{
    color = Qt::blue;

}

void MainWindow::on_pushButton_green_clicked()
{
    color = Qt::green;
}


void MainWindow::on_pushButton_6_clicked()
{



//    QPalette pal = ui->pushButton_6->palette();
//    pal.setColor(QPalette::Button, QColor(Qt::blue));
//    ui->pushButton_6->setAutoFillBackground(true);
//    ui->pushButton_6->setPalette(pal);
//    ui->pushButton_6->update();

    QColor col = QColor(color);
    if(col.isValid()) {
       QString qss = QString("background-color: %1").arg(col.name());
       ui->pushButton_6->setStyleSheet(qss);
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    QColor col = QColor(color);
    if(col.isValid()) {
       QString qss = QString("background-color: %1").arg(col.name());
       ui->pushButton_7->setStyleSheet(qss);
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    QColor col = QColor(color);
    if(col.isValid()) {
       QString qss = QString("background-color: %1").arg(col.name());
       ui->pushButton_8->setStyleSheet(qss);
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    QColor col = QColor(color);
    if(col.isValid()) {
       QString qss = QString("background-color: %1").arg(col.name());
       ui->pushButton_4->setStyleSheet(qss);
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    QColor col = QColor(color);
    if(col.isValid()) {
       QString qss = QString("background-color: %1").arg(col.name());
       ui->pushButton_9->setStyleSheet(qss);
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    QColor col = QColor(color);
    if(col.isValid()) {
       QString qss = QString("background-color: %1").arg(col.name());
       ui->pushButton_10->setStyleSheet(qss);
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    QColor col = QColor(color);
    if(col.isValid()) {
       QString qss = QString("background-color: %1").arg(col.name());
       ui->pushButton_5->setStyleSheet(qss);
    }
}


void MainWindow::on_pushButton_11_clicked()
{
    QColor col = QColor(color);
    if(col.isValid()) {
       QString qss = QString("background-color: %1").arg(col.name());
       ui->pushButton_11->setStyleSheet(qss);
    }
}


void MainWindow::on_pushButton_12_clicked()
{
    QColor col = QColor(color);
    if(col.isValid()) {
       QString qss = QString("background-color: %1").arg(col.name());
       ui->pushButton_12->setStyleSheet(qss);
    }
}

