QMAKE_CXX	= g++
QMAKE_CC	= gcc

QT		+= core gui network widgets multimedia
RC_FILE		= chApp.rc

TARGET		= chApp
TEMPLATE	= app

CONFIG		+= c++11
CONFIG		+= release

# ---- Files ----

SOURCES += main.cpp chatwindow.cpp logindialog.cpp NetClient.cpp \
    gui.cpp \

HEADERS  += chatwindow.h logindialog.h NetClient.h \
    gui.h \

TRANSLATIONS += \
    Translations/chApp_ru.ts

tr.commands = lupdate $$_PRO_FILE_ && lrelease $$_PRO_FILE_

PRE_TARGETDEPS += tr

QMAKE_EXTRA_TARGETS += tr

FORMS    += chatwindow.ui logindialog.ui

RESOURCES += myResources.qrc

