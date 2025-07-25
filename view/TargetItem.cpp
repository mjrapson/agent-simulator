#include "TargetItem.h"

#include "model/Target.h"

#include <QBrush>

namespace view
{
TargetItem::TargetItem(model::Target* target, QGraphicsItem* parent)
    : QGraphicsPolygonItem(parent)
    , m_target{target}
{
    setPolygon(QPolygonF(QRectF(0, 0, 20, 20)));
    setBrush(Qt::green);

    update();
}

void TargetItem::update()
{
    setPos(m_target->position().x(), m_target->position().y());
}
}
