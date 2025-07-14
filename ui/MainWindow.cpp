#include "MainWindow.h"

#include "model/Agent.h"
#include "view/AgentItem.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPushButton>
#include <QVBoxLayout>

constexpr int WorldWidth = 500;
constexpr int WorldHeight= 500;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setMinimumSize(800, 600);

    m_agent = std::make_unique<model::Agent>(0, 0);

    createGui();

    m_simulationTimer.setInterval(16);
    connect(&m_simulationTimer, &QTimer::timeout, this, &MainWindow::stepSimulation);
}

MainWindow::~MainWindow() = default;

void MainWindow::createGui()
{
    auto* mainWidget = new QWidget{};
    auto* mainLayout = new QVBoxLayout{mainWidget};

    auto* graphicsScene = new QGraphicsScene{};
    graphicsScene->setSceneRect(-250, -250, WorldWidth, WorldHeight);

    m_agentItem = new view::AgentItem(m_agent.get());
    graphicsScene->addItem(m_agentItem);

    auto* graphicsView = new QGraphicsView{};
    graphicsView->setScene(graphicsScene);
    graphicsView->fitInView(graphicsScene->sceneRect(), Qt::KeepAspectRatio);
    mainLayout->addWidget(graphicsView);

    auto* buttonLayout = new QHBoxLayout{};
    m_startButton = new QPushButton{"Start"};
    connect(m_startButton, &QPushButton::clicked, this, &MainWindow::onStartPressed);
    buttonLayout->addStretch();
    buttonLayout->addWidget(m_startButton);
    buttonLayout->addStretch();

    mainLayout->addLayout(buttonLayout);

    setCentralWidget(mainWidget);
}

void MainWindow::stepSimulation()
{
    m_agent->moveForward(1.0, -90.0);
    m_agentItem->update();
}

void MainWindow::onStartPressed()
{
    m_startButton->setEnabled(false);
    m_simulationTimer.start();
}
