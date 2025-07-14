#pragma once

#include <QMainWindow>

#include <QTimer>

#include <memory>

namespace model
{
class Agent;
class Target;
}

namespace view
{
class AgentItem;
class TargetItem;
}

class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createGui();
    void stepSimulation();

private slots:
    void onStartPressed();

private:
    QTimer m_simulationTimer;

    QPushButton* m_startButton{nullptr};

    std::unique_ptr<model::Agent> m_agent{nullptr};
    std::unique_ptr<model::Target> m_target{nullptr};

    view::AgentItem* m_agentItem{nullptr};
    view::TargetItem* m_targetItem{nullptr};
};
