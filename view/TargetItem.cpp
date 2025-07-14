#include "TargetItem.h"

#include "model/Target.h"

#include <QBrush>

namespace view
{
TargetItem::TargetItem(model::Target* target, QGraphicsItem* parent)
    : QGraphicsPolygonItem(parent)
    , m_target{target}
{
    QPolygonF triangle;
    triangle << QPointF(0, -20) << QPointF(10, 10) << QPointF(-10, 10);
    setPolygon(QPolygonF(QRectF(0, 0, 20, 20)));
    setBrush(Qt::green);

    update();
}

void TargetItem::update()
{
    setPos(m_target->x(), m_target->y());
}
}
