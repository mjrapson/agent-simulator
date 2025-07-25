QT += core gui widgets

TARGET = AgentSimulator

TEMPLATE = app

SOURCES +=  main.cpp\
core/Box.cpp \
            core/Point2D.cpp \
            core/Vector2D.cpp \
            core/VectorMath.cpp \
            model/Agent.cpp \
            model/SimulationActor.cpp \
            model/Target.cpp \
            ui/MainWindow.cpp \
            view/AgentItem.cpp \
            view/GraphicsScene.cpp \
            view/TargetItem.cpp

HEADERS  += model/Agent.h \
core/Box.h \
            core/Point2D.h \
            core/Vector2D.h \
            core/VectorMath.h \
            model/SimulationActor.h \
            model/Target.h \
            ui/MainWindow.h \
            view/AgentItem.h \
            view/GraphicsScene.h \
            view/TargetItem.h \
