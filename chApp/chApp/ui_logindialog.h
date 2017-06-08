/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QGridLayout *gridLayout;
    QDialogButtonBox *buttonBox;
    QVBoxLayout *verticalLayout;
    QLineEdit *inputServer;
    QLineEdit *inputName;
    QLabel *errorMessage;
    QVBoxLayout *verticalLayout_2;
    QLabel *name;
    QLabel *adress;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->setWindowModality(Qt::ApplicationModal);
        LoginDialog->resize(400, 185);
        LoginDialog->setStyleSheet(QStringLiteral(""));
        LoginDialog->setModal(true);
        gridLayout = new QGridLayout(LoginDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        buttonBox = new QDialogButtonBox(LoginDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStyleSheet(QLatin1String("QPushButton:hover{\n"
"border-width: 0px;\n"
"\n"
"color: rgb(11, 11, 11);\n"
"border-radius: 20%;\n"
"\n"
"}\n"
"QPushButton {\n"
"border: 2px solid #8f8f91;\n"
"border-radius: 6px;\n"
"\n"
"background-color: rgb(245, 245, 245);\n"
"min-width: 80px;\n"
"font: 75  11pt \"Colibri\";\n"
"outline: none;\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"border: red; \n"
"}\n"
"\n"
"QPushButton:default {\n"
"border-color: green; \n"
"}"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        inputServer = new QLineEdit(LoginDialog);
        inputServer->setObjectName(QStringLiteral("inputServer"));
        inputServer->setAcceptDrops(true);
        inputServer->setStyleSheet(QLatin1String("QLineEdit:focus#findPattern, QLineEdit:focus#findChange {\n"
"    border-color: @focused-border-focus-color;\n"
"    border-style: @focused-border-style;\n"
"    border-width: @focused-border-width;\n"
"}"));

        verticalLayout->addWidget(inputServer);

        inputName = new QLineEdit(LoginDialog);
        inputName->setObjectName(QStringLiteral("inputName"));
        inputName->setStyleSheet(QLatin1String("QLineEdit:focus#findPattern, QLineEdit:focus#findChange {\n"
"    border-color: @focused-border-focus-color;\n"
"    border-style: @focused-border-style;\n"
"    border-width: @focused-border-width;\n"
"}"));

        verticalLayout->addWidget(inputName);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        errorMessage = new QLabel(LoginDialog);
        errorMessage->setObjectName(QStringLiteral("errorMessage"));

        gridLayout->addWidget(errorMessage, 2, 0, 1, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        name = new QLabel(LoginDialog);
        name->setObjectName(QStringLiteral("name"));

        verticalLayout_2->addWidget(name);

        adress = new QLabel(LoginDialog);
        adress->setObjectName(QStringLiteral("adress"));
        adress->setStyleSheet(QStringLiteral("font: 75  11pt \"Colibri\";"));

        verticalLayout_2->addWidget(adress);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        QWidget::setTabOrder(inputServer, inputName);
        QWidget::setTabOrder(inputName, buttonBox);

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Login", Q_NULLPTR));
        inputServer->setText(QString());
        inputServer->setPlaceholderText(QString());
        errorMessage->setText(QString());
        name->setText(QApplication::translate("LoginDialog", "Server adress:", Q_NULLPTR));
        adress->setText(QApplication::translate("LoginDialog", "User name:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
