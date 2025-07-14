QT += core gui widgets

TARGET = AgentSimulator

TEMPLATE = app

SOURCES +=  main.cpp\
            mainwindow.cpp \
            model/agent.cpp \
            view/AgentItem.cpp

HEADERS  += mainwindow.h \
            model/agent.h \
            view/AgentItem.h
