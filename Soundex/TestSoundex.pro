GOOGLETEST_DIR = C:\Qt\googletest
include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
  soundex.h \
  tst_soundex.h

SOURCES += \
  soundex.cpp \
  testSoundexMain.cpp
