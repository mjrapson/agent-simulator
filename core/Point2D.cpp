#pragma once

#include "Point2D.h"

namespace core
{
Point2D::Point2D(double x, double y)
    : m_x{x}
    , m_y{y}
{
}

double Point2D::x() const
{
    return m_x;
}

double Point2D::y() const
{
    return m_y;
}
}
