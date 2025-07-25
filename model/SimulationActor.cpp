#include "SimulationActor.h"

namespace model
{
SimulationActor::SimulationActor()
{
}

void SimulationActor::setPosition(const core::Point2D& position)
{
    m_position = position;
}

const core::Point2D& SimulationActor::position() const
{
    return m_position;
}

void SimulationActor::setRotation(float degrees)
{
    m_rotation = degrees;
}

float SimulationActor::rotation() const
{
    return m_rotation;
}
}
