TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        pelaaja.cpp \
        peli_loop_countdown.cpp \
        tallentaja.cpp

HEADERS += \
    pelaaja.h \
    peli_loop_countdown.h \
    tallentaja.h
