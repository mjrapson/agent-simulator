#include "model/agent.h"

#include <qmath.h>

namespace model
{
Agent::Agent(double x, double y)
    : m_x{x}
    , m_y{y}
{
}

Agent::~Agent() = default;

void Agent::moveForward(double distance, double angle)
{
    const auto angleRadians = qDegreesToRadians(angle);
    m_x += distance * std::cos(angleRadians);
    m_y += distance * std::sin(angleRadians);
}

double Agent::x() const
{
    return m_x;
}

double Agent::y() const
{
    return m_y;
}
}
