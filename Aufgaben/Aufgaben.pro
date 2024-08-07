QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += console
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    S105_Aufgaben.cpp \
    S105_Pascal_Dreieck.cpp \
    S109_funktionszeiger_trapez.cpp \
    S60_namespaces.cpp \
    S65_ein_ausgabe.cpp \
    S70_format_flags.cpp \
    S75_format_manipulatoren.cpp \
    S77_Aufgabe_iomanip.cpp \
    S78_param_swaP.cpp \
    main.cpp

HEADERS += \
    main.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
