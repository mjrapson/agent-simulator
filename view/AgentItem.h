#pragma once

#include <QGraphicsPolygonItem>

namespace model
{
class Agent;
}

namespace view
{
class AgentItem : public QGraphicsPolygonItem
{
public:
    explicit AgentItem(model::Agent* agent, QGraphicsItem* parent = nullptr);

    void update();

private:
    model::Agent* m_agent{nullptr};
};
}
