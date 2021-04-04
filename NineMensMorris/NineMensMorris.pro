QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    board.cpp \
    game.cpp \
    game_gui.cpp \
    hole.cpp \
    logwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    player_gui.cpp

HEADERS += \
    board.h \
    game.h \
    game_gui.h \
    hole.h \
    logwindow.h \
    mainwindow.h \
    player.h \
    player_gui.h

FORMS += \
    mainwindow.ui

QT += testlib
TEMPLATE = app

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
