/********************************************************************************
** Form generated from reading UI file 'chatwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QAction *actionSetColorscheme;
    QAction *actionDark;
    QAction *actionDefault;
    QAction *actionChatty;
    QAction *actionCezch;
    QAction *action13;
    QAction *action15;
    QAction *action20;
    QAction *action25;
    QAction *actionLoad_history;
    QAction *action13_2;
    QAction *action15_2;
    QAction *action20_2;
    QAction *action25_2;
    QAction *actionNiklas;
    QAction *actionPrevious_message;
    QAction *actionNikki_Beach;
    QAction *actionShe_squats_bro;
    QAction *actionchApp;
    QAction *actionMonokai;
    QAction *actionLight;
    QAction *actionImage;
    QAction *actionRadiance;
    QAction *actionEnglish;
    QAction *actionRussian;
    QAction *actionUkrainian;
    QAction *actionAbout;
    QAction *actionContact_Developer;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *sendButton;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *messageInput;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *roomTree;
    QTextBrowser *messageHistory;
    QMenuBar *menuBar;
    QMenu *menuCustomize;
    QMenu *menuChange_theme;
    QMenu *menuChange_font;
    QMenu *menuSize;
    QMenu *menuChange_smiley_size;
    QMenu *menuHistory;
    QMenu *menuMessage;
    QMenu *menuLanguages;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName(QStringLiteral("ChatWindow"));
        ChatWindow->resize(1030, 795);
        actionSetColorscheme = new QAction(ChatWindow);
        actionSetColorscheme->setObjectName(QStringLiteral("actionSetColorscheme"));
        actionSetColorscheme->setCheckable(true);
        actionDark = new QAction(ChatWindow);
        actionDark->setObjectName(QStringLiteral("actionDark"));
        actionDefault = new QAction(ChatWindow);
        actionDefault->setObjectName(QStringLiteral("actionDefault"));
        actionChatty = new QAction(ChatWindow);
        actionChatty->setObjectName(QStringLiteral("actionChatty"));
        actionCezch = new QAction(ChatWindow);
        actionCezch->setObjectName(QStringLiteral("actionCezch"));
        action13 = new QAction(ChatWindow);
        action13->setObjectName(QStringLiteral("action13"));
        action15 = new QAction(ChatWindow);
        action15->setObjectName(QStringLiteral("action15"));
        action20 = new QAction(ChatWindow);
        action20->setObjectName(QStringLiteral("action20"));
        action25 = new QAction(ChatWindow);
        action25->setObjectName(QStringLiteral("action25"));
        actionLoad_history = new QAction(ChatWindow);
        actionLoad_history->setObjectName(QStringLiteral("actionLoad_history"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/image/envelope.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad_history->setIcon(icon);
        action13_2 = new QAction(ChatWindow);
        action13_2->setObjectName(QStringLiteral("action13_2"));
        action15_2 = new QAction(ChatWindow);
        action15_2->setObjectName(QStringLiteral("action15_2"));
        action20_2 = new QAction(ChatWindow);
        action20_2->setObjectName(QStringLiteral("action20_2"));
        action25_2 = new QAction(ChatWindow);
        action25_2->setObjectName(QStringLiteral("action25_2"));
        actionNiklas = new QAction(ChatWindow);
        actionNiklas->setObjectName(QStringLiteral("actionNiklas"));
        actionPrevious_message = new QAction(ChatWindow);
        actionPrevious_message->setObjectName(QStringLiteral("actionPrevious_message"));
        actionNikki_Beach = new QAction(ChatWindow);
        actionNikki_Beach->setObjectName(QStringLiteral("actionNikki_Beach"));
        actionShe_squats_bro = new QAction(ChatWindow);
        actionShe_squats_bro->setObjectName(QStringLiteral("actionShe_squats_bro"));
        actionchApp = new QAction(ChatWindow);
        actionchApp->setObjectName(QStringLiteral("actionchApp"));
        actionMonokai = new QAction(ChatWindow);
        actionMonokai->setObjectName(QStringLiteral("actionMonokai"));
        actionLight = new QAction(ChatWindow);
        actionLight->setObjectName(QStringLiteral("actionLight"));
        actionImage = new QAction(ChatWindow);
        actionImage->setObjectName(QStringLiteral("actionImage"));
        actionRadiance = new QAction(ChatWindow);
        actionRadiance->setObjectName(QStringLiteral("actionRadiance"));
        actionEnglish = new QAction(ChatWindow);
        actionEnglish->setObjectName(QStringLiteral("actionEnglish"));
        actionRussian = new QAction(ChatWindow);
        actionRussian->setObjectName(QStringLiteral("actionRussian"));
        actionUkrainian = new QAction(ChatWindow);
        actionUkrainian->setObjectName(QStringLiteral("actionUkrainian"));
        actionAbout = new QAction(ChatWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionContact_Developer = new QAction(ChatWindow);
        actionContact_Developer->setObjectName(QStringLiteral("actionContact_Developer"));
        centralWidget = new QWidget(ChatWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        gridLayout->addWidget(sendButton, 1, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        messageInput = new QLineEdit(centralWidget);
        messageInput->setObjectName(QStringLiteral("messageInput"));

        horizontalLayout_2->addWidget(messageInput);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        roomTree = new QTreeWidget(centralWidget);
        roomTree->headerItem()->setText(0, QString());
        roomTree->setObjectName(QStringLiteral("roomTree"));

        horizontalLayout->addWidget(roomTree);

        messageHistory = new QTextBrowser(centralWidget);
        messageHistory->setObjectName(QStringLiteral("messageHistory"));
        QFont font;
        font.setFamily(QStringLiteral("Geeza Pro"));
        font.setPointSize(15);
        messageHistory->setFont(font);
        messageHistory->setMouseTracking(false);
        messageHistory->setAcceptDrops(false);
        messageHistory->setAutoFillBackground(true);
        messageHistory->setAcceptRichText(false);

        horizontalLayout->addWidget(messageHistory);

        horizontalLayout->setStretch(1, 75);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        ChatWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ChatWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1030, 19));
        menuCustomize = new QMenu(menuBar);
        menuCustomize->setObjectName(QStringLiteral("menuCustomize"));
        menuChange_theme = new QMenu(menuCustomize);
        menuChange_theme->setObjectName(QStringLiteral("menuChange_theme"));
        menuChange_font = new QMenu(menuCustomize);
        menuChange_font->setObjectName(QStringLiteral("menuChange_font"));
        menuSize = new QMenu(menuChange_font);
        menuSize->setObjectName(QStringLiteral("menuSize"));
        menuChange_smiley_size = new QMenu(menuCustomize);
        menuChange_smiley_size->setObjectName(QStringLiteral("menuChange_smiley_size"));
        menuHistory = new QMenu(menuBar);
        menuHistory->setObjectName(QStringLiteral("menuHistory"));
        menuMessage = new QMenu(menuBar);
        menuMessage->setObjectName(QStringLiteral("menuMessage"));
        menuLanguages = new QMenu(menuBar);
        menuLanguages->setObjectName(QStringLiteral("menuLanguages"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        ChatWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ChatWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setIconSize(QSize(21, 21));
        mainToolBar->setFloatable(true);
        ChatWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ChatWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ChatWindow->setStatusBar(statusBar);

        menuBar->addAction(menuCustomize->menuAction());
        menuBar->addAction(menuHistory->menuAction());
        menuBar->addAction(menuMessage->menuAction());
        menuBar->addAction(menuLanguages->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuCustomize->addAction(menuChange_theme->menuAction());
        menuCustomize->addAction(menuChange_font->menuAction());
        menuCustomize->addAction(menuChange_smiley_size->menuAction());
        menuChange_theme->addAction(actionDark);
        menuChange_theme->addAction(actionDefault);
        menuChange_theme->addAction(actionchApp);
        menuChange_theme->addAction(actionMonokai);
        menuChange_theme->addAction(actionLight);
        menuChange_theme->addAction(actionImage);
        menuChange_theme->addAction(actionRadiance);
        menuChange_font->addAction(menuSize->menuAction());
        menuSize->addAction(action13);
        menuSize->addAction(action15);
        menuSize->addAction(action20);
        menuSize->addAction(action25);
        menuChange_smiley_size->addAction(action13_2);
        menuChange_smiley_size->addAction(action15_2);
        menuChange_smiley_size->addAction(action20_2);
        menuChange_smiley_size->addAction(action25_2);
        menuHistory->addAction(actionLoad_history);
        menuMessage->addAction(actionPrevious_message);
        menuLanguages->addAction(actionEnglish);
        menuLanguages->addAction(actionRussian);
        menuLanguages->addAction(actionUkrainian);
        menuAbout->addAction(actionAbout);
        mainToolBar->addAction(actionLoad_history);

        retranslateUi(ChatWindow);

        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChatWindow)
    {
        ChatWindow->setWindowTitle(QApplication::translate("ChatWindow", "chApp", Q_NULLPTR));
        actionSetColorscheme->setText(QApplication::translate("ChatWindow", "Change color", Q_NULLPTR));
        actionDark->setText(QApplication::translate("ChatWindow", "Dark", Q_NULLPTR));
        actionDefault->setText(QApplication::translate("ChatWindow", "Default", Q_NULLPTR));
        actionChatty->setText(QApplication::translate("ChatWindow", "Chatty", Q_NULLPTR));
        actionCezch->setText(QApplication::translate("ChatWindow", "Czech", Q_NULLPTR));
        action13->setText(QApplication::translate("ChatWindow", "13", Q_NULLPTR));
        action15->setText(QApplication::translate("ChatWindow", "15", Q_NULLPTR));
        action20->setText(QApplication::translate("ChatWindow", "20", Q_NULLPTR));
        action25->setText(QApplication::translate("ChatWindow", "25", Q_NULLPTR));
        actionLoad_history->setText(QApplication::translate("ChatWindow", "Load history", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionLoad_history->setToolTip(QApplication::translate("ChatWindow", "Load one more day of history", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action13_2->setText(QApplication::translate("ChatWindow", "13", Q_NULLPTR));
        action15_2->setText(QApplication::translate("ChatWindow", "15", Q_NULLPTR));
        action20_2->setText(QApplication::translate("ChatWindow", "20", Q_NULLPTR));
        action25_2->setText(QApplication::translate("ChatWindow", "25", Q_NULLPTR));
        actionNiklas->setText(QApplication::translate("ChatWindow", "Nikki", Q_NULLPTR));
        actionPrevious_message->setText(QApplication::translate("ChatWindow", "Insert previous message", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionPrevious_message->setShortcut(QApplication::translate("ChatWindow", "Up", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionNikki_Beach->setText(QApplication::translate("ChatWindow", "Nikki Beach", Q_NULLPTR));
        actionShe_squats_bro->setText(QApplication::translate("ChatWindow", "They Squat Bro", Q_NULLPTR));
        actionchApp->setText(QApplication::translate("ChatWindow", "chApp", Q_NULLPTR));
        actionMonokai->setText(QApplication::translate("ChatWindow", "Monokai", Q_NULLPTR));
        actionLight->setText(QApplication::translate("ChatWindow", "Light", Q_NULLPTR));
        actionImage->setText(QApplication::translate("ChatWindow", "Image", Q_NULLPTR));
        actionRadiance->setText(QApplication::translate("ChatWindow", "Radiance", Q_NULLPTR));
        actionEnglish->setText(QApplication::translate("ChatWindow", "English", Q_NULLPTR));
        actionRussian->setText(QApplication::translate("ChatWindow", "Russian", Q_NULLPTR));
        actionUkrainian->setText(QApplication::translate("ChatWindow", "Ukrainian", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("ChatWindow", "About", Q_NULLPTR));
        actionContact_Developer->setText(QApplication::translate("ChatWindow", "Contact Developer", Q_NULLPTR));
        sendButton->setText(QApplication::translate("ChatWindow", "Send", Q_NULLPTR));
        messageInput->setPlaceholderText(QApplication::translate("ChatWindow", "Enter your message here", Q_NULLPTR));
        menuCustomize->setTitle(QApplication::translate("ChatWindow", "Customize", Q_NULLPTR));
        menuChange_theme->setTitle(QApplication::translate("ChatWindow", "Change theme", Q_NULLPTR));
        menuChange_font->setTitle(QApplication::translate("ChatWindow", "Change font", Q_NULLPTR));
        menuSize->setTitle(QApplication::translate("ChatWindow", "Size", Q_NULLPTR));
        menuChange_smiley_size->setTitle(QApplication::translate("ChatWindow", "Change smiley size", Q_NULLPTR));
        menuHistory->setTitle(QApplication::translate("ChatWindow", "History", Q_NULLPTR));
        menuMessage->setTitle(QApplication::translate("ChatWindow", "Message", Q_NULLPTR));
        menuLanguages->setTitle(QApplication::translate("ChatWindow", "Languages", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("ChatWindow", "Info", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
