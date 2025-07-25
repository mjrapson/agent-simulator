#include "GraphicsScene.h"

#include "AgentItem.h"

namespace view
{
GraphicsScene::GraphicsScene(QObject *parent)
    : QGraphicsScene{parent}
{
}

GraphicsScene::~GraphicsScene() = default;

void GraphicsScene::addAgent(std::unique_ptr<AgentItem> agent)
{
    addItem(agent.get());
    m_agents.push_back(std::move(agent));
}

void GraphicsScene::update()
{
    for (auto&& agent : m_agents)
    {
        agent->update();
    }
}
}
