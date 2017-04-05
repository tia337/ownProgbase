#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_editingFinished()
{
    QLabel * lbl = this->findChild<QLabel*>("label_10");
    QLineEdit * edit = this->findChild<QLineEdit*>("lineEdit");
    QString editInputString = edit->text();
    lbl->setText(editInputString);

}

void MainWindow::on_lineEdit_3_editingFinished()
{
    QLabel * lbl = this->findChild<QLabel*>("label_11");
    QLineEdit * edit = this->findChild<QLineEdit*>("lineEdit_3");
    QString editInputString = edit->text();
    lbl->setText(editInputString);

}

void MainWindow::on_lineEdit_4_editingFinished()
{
    QLabel * lbl = this->findChild<QLabel*>("label_12");
    QLineEdit * edit = this->findChild<QLineEdit*>("lineEdit_4");
    QString editInputString = edit->text();
    lbl->setText(editInputString);
}


void MainWindow::on_lineEdit_5_editingFinished()
{
    QLabel * lbl = this->findChild<QLabel*>("label_13");
    QLineEdit * edit = this->findChild<QLineEdit*>("lineEdit_5");
    QString editInputString = edit->text();
    lbl->setText(editInputString);
}

//void MainWindow::closeEvent (QCloseEvent *event)
//{
//    // use this to cleanup allocated memory

//    for (TaxiDriver * st : students) {
//        delete st;
//    }
//    qDebug() << "Window closed!";
//    event->accept();
//}
