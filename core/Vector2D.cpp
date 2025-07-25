#include "Vector2D.h"

#include <cmath>

namespace core
{
Vector2D::Vector2D(double dx, double dy)
    : m_x{dx}
    , m_y{dy}
    , m_angle{std::atan2(m_y, m_x)}
    , m_magnitude{std::sqrt((m_x * m_x) + (m_y * m_y))}
{
}

double Vector2D::x() const
{
    return m_x;
}

double Vector2D::y() const
{
    return m_y;
}

double Vector2D::angle() const
{
    return m_angle;
}

double Vector2D::magnitude() const
{
    return m_magnitude;
}
}
