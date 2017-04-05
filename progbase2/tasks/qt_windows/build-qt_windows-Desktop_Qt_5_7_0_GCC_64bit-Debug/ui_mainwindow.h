/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QFormLayout *formLayout_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *label_12;
    QLabel *label_9;
    QLabel *label_13;
    QLabel *label_10;
    QMenuBar *menuBar;
    QMenu *menuWindow;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 176, 192));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        lineEdit_3 = new QLineEdit(widget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_3);

        lineEdit_4 = new QLineEdit(widget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_4);

        lineEdit_5 = new QLineEdit(widget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_5);


        verticalLayout->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_7);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, label_11);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_8);

        label_12 = new QLabel(widget);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, label_12);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_9);

        label_13 = new QLabel(widget);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, label_13);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, label_10);


        verticalLayout->addLayout(formLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 19));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuWindow->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Name", 0));
        label_3->setText(QApplication::translate("MainWindow", "Age", 0));
        label_4->setText(QApplication::translate("MainWindow", "Salary", 0));
        label_5->setText(QApplication::translate("MainWindow", "Clients", 0));
        label_6->setText(QApplication::translate("MainWindow", "Name", 0));
        label_7->setText(QApplication::translate("MainWindow", "Age", 0));
        label_11->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "Salary", 0));
        label_12->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "Clients", 0));
        label_13->setText(QString());
        label_10->setText(QString());
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
