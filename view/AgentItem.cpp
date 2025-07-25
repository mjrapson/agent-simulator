#include "AgentItem.h"

#include "model/Agent.h"

#include <QBrush>

namespace view
{
AgentItem::AgentItem(model::Agent* agent, QGraphicsItem* parent)
    : QGraphicsPolygonItem(parent)
    , m_agent{agent}
{
    QPolygonF triangle;
    triangle << QPointF(0, -20) << QPointF(10, 10) << QPointF(-10, 10);
    setPolygon(triangle);
    setBrush(Qt::cyan);

    update();
}

void AgentItem::update()
{
    setPos(m_agent->position().x(), m_agent->position().y());
    setRotation(m_agent->rotation() + 90);
}
}
