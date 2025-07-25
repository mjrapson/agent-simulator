#pragma once

#include <QMainWindow>

#include <QTimer>

#include <memory>
#include <vector>

namespace model
{
class Agent;
class Target;
}

namespace view
{
class AgentItem;
class GraphicsScene;
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
    void processAgents();

private slots:
    void onStartPressed();

private:
    QTimer m_simulationTimer;

    QPushButton* m_startButton{nullptr};

    view::GraphicsScene* m_graphicsScene{nullptr};

    std::unique_ptr<model::Target> m_target{nullptr};

    std::vector<std::unique_ptr<model::Agent>> m_agents;

    view::TargetItem* m_targetItem{nullptr};
};
