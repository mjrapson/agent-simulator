#include "model/Target.h"

#include <qmath.h>

namespace model
{
Target::Target(double x, double y)
    : m_x{x}
    , m_y{y}
{
}

Target::~Target() = default;

double Target::x() const
{
    return m_x;
}

double Target::y() const
{
    return m_y;
}
}
