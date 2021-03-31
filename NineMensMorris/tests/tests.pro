QT += testlib
QT += gui core widgets
#QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCDIR = ../

INCLUDEPATH+=$$INCDIR

SOURCES +=  \
    tst_tests.cpp \
    $$INCDIR/board.cpp \
    $$INCDIR/game.cpp \
    $$INCDIR/game_gui.cpp \
    $$INCDIR/player.cpp \
    $$INCDIR/hole.cpp

HEADERS +=  \
    $$INCDIR/board.h \
    $$INCDIR/game.h \
    $$INCDIR/game_gui.h \
    $$INCDIR/player.h \
    $$INCDIR/hole.h

RESOURCES += \
    $$INCDIR\resource.qrc
