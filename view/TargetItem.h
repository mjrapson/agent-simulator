#pragma once

#include <QGraphicsPolygonItem>

namespace model
{
class Target;
}

namespace view
{
class TargetItem : public QGraphicsPolygonItem
{
public:
    explicit TargetItem(model::Target* agent, QGraphicsItem* parent = nullptr);

    void update();

private:
    model::Target* m_target{nullptr};
};
}
