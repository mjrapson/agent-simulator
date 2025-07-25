#pragma once

#include "core/Point2D.h"

namespace model
{
class SimulationActor
{
public:
    SimulationActor();

    void setPosition(const core::Point2D& position);
    const core::Point2D& position() const;

    void setRotation(float degrees);
    float rotation() const;

private:
    core::Point2D m_position{core::Point2D{0.0, 0.0}};
    float m_rotation{0.0f};
};
}
