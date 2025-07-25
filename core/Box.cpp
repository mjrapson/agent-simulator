#include "Box.h"

namespace core
{
Box::Box(double x, double y, double width, double height)
    : m_x{x}
    , m_y{y}
    , m_width{width}
    , m_height{height}
{
}

double Box::x() const
{
    return m_x;
}

double Box::y() const
{
    return m_y;
}

double Box::width() const
{
    return m_width;
}

double Box::height() const
{
    return m_height;
}
}
