QT += core gui widgets

TARGET = AgentSimulator

TEMPLATE = app

SOURCES +=  main.cpp\
            model/Agent.cpp \
            ui/MainWindow.cpp \
            view/AgentItem.cpp

HEADERS  += model/Agent.h \
            ui/MainWindow.h \
            view/AgentItem.h
