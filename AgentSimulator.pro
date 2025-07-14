QT += core gui widgets

TARGET = AgentSimulator

TEMPLATE = app

SOURCES +=  main.cpp\
            model/Agent.cpp \
            model/Target.cpp \
            ui/MainWindow.cpp \
            view/AgentItem.cpp \
            view/TargetItem.cpp

HEADERS  += model/Agent.h \
            model/Target.h \
            ui/MainWindow.h \
            view/AgentItem.h \
            view/TargetItem.h
