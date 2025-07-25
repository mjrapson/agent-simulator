#include "MainWindow.h"

#include "core/Point2D.h"
#include "core/VectorMath.h"
#include "model/Agent.h"
#include "model/Target.h"
#include "view/AgentItem.h"
#include "view/GraphicsScene.h"
#include "view/TargetItem.h"

#include <QGraphicsView>
#include <QPushButton>
#include <QVBoxLayout>

constexpr int WorldWidth = 500;
constexpr int WorldHeight= 500;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setMinimumSize(800, 600);

    for(auto i = 0; i < 4; ++i)
    {
        auto agent = std::make_unique<model::Agent>();
        agent->setPosition(core::Point2D{25.0 * i, 10.0 * i});
        m_agents.push_back(std::move(agent));
    }

    m_target = std::make_unique<model::Target>();
    m_target->setPosition(core::Point2D{0, -100});

    createGui();

    m_simulationTimer.setInterval(16);
    connect(&m_simulationTimer, &QTimer::timeout, this, &MainWindow::stepSimulation);
}

MainWindow::~MainWindow() = default;

void MainWindow::createGui()
{
    auto* mainWidget = new QWidget{};
    auto* mainLayout = new QVBoxLayout{mainWidget};

    m_graphicsScene = new view::GraphicsScene{this};
    m_graphicsScene->setSceneRect(-250, -250, WorldWidth, WorldHeight);
    for(auto&& agent : m_agents)
    {
        m_graphicsScene->addAgent(std::make_unique<view::AgentItem>(agent.get()));
    }

    m_targetItem = new view::TargetItem(m_target.get());
    m_graphicsScene->addItem(m_targetItem);

    auto* graphicsView = new QGraphicsView{};
    graphicsView->setScene(m_graphicsScene);
    graphicsView->fitInView(m_graphicsScene->sceneRect(), Qt::KeepAspectRatio);
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
    processAgents();

    m_graphicsScene->update();
}

void MainWindow::processAgents()
{
    constexpr auto agentSpeed = 40.0;
    const auto deltaTime = m_simulationTimer.interval() / 1000.0;
    for(auto&& agent : m_agents)
    {
        const auto position = agent->position();
        const auto direction = core::forwardVectorFromAngle(agent->rotation());

        const auto newPosition = position + (direction * agentSpeed * deltaTime);

        agent->setPosition(newPosition);
    }
}

void MainWindow::onStartPressed()
{
    m_startButton->setEnabled(false);
    m_simulationTimer.start();
}
