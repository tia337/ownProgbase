/********************************************************************************
** Form generated from reading UI file 'aboutwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTWINDOW_H
#define UI_ABOUTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AboutWindow
{
public:
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QDialog *AboutWindow)
    {
        if (AboutWindow->objectName().isEmpty())
            AboutWindow->setObjectName(QStringLiteral("AboutWindow"));
        AboutWindow->resize(400, 300);
        AboutWindow->setStyleSheet(QStringLiteral("background-color: rgb(255, 206, 206);"));
        label_4 = new QLabel(AboutWindow);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(150, 0, 81, 41));
        QFont font;
        font.setFamily(QStringLiteral("URW Chancery L"));
        font.setPointSize(25);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(7);
        label_4->setFont(font);
        label_4->setStyleSheet(QLatin1String("\n"
"font: 57  25pt \"URW Chancery L\";"));
        label_5 = new QLabel(AboutWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(21, 51, 83, 18));
        label_5->setStyleSheet(QStringLiteral("font: 75  13pt \"colibri\";"));
        label_6 = new QLabel(AboutWindow);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(109, 51, 20, 18));
        label_6->setStyleSheet(QStringLiteral("font: 75  13pt \"colibri\";"));
        label_7 = new QLabel(AboutWindow);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 80, 62, 18));
        label_7->setStyleSheet(QStringLiteral("font: 75  13pt \"colibri\";"));
        label_8 = new QLabel(AboutWindow);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(90, 80, 53, 18));
        label_8->setStyleSheet(QStringLiteral("font: 75  13pt \"colibri\";"));
        label_9 = new QLabel(AboutWindow);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 110, 145, 18));
        label_9->setStyleSheet(QLatin1String("font: 75  13pt \"colibri\";\n"
"gridline-color: rgb(0, 0, 0);\n"
""));
        label_9->setOpenExternalLinks(false);

        retranslateUi(AboutWindow);

        QMetaObject::connectSlotsByName(AboutWindow);
    } // setupUi

    void retranslateUi(QDialog *AboutWindow)
    {
        AboutWindow->setWindowTitle(QApplication::translate("AboutWindow", "Dialog", Q_NULLPTR));
        label_4->setText(QApplication::translate("AboutWindow", "chApp", Q_NULLPTR));
        label_5->setText(QApplication::translate("AboutWindow", "Developer:", Q_NULLPTR));
        label_6->setText(QApplication::translate("AboutWindow", "tia", Q_NULLPTR));
        label_7->setText(QApplication::translate("AboutWindow", "Version:", Q_NULLPTR));
        label_8->setText(QApplication::translate("AboutWindow", "1.0.0.1", Q_NULLPTR));
        label_9->setText(QApplication::translate("AboutWindow", "    <a href=\"https://zzitcyzdb.wixsite.com/chapp\">Developer page</a>.", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AboutWindow: public Ui_AboutWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTWINDOW_H
