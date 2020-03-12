QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

APP = $$PWD/..

include($${APP}/msshtunnel.pri)

SOURCES +=  tst_msshtunneltest.cpp
