#pragma once

namespace core
{
class Vector2D
{
public:
    Vector2D(double dx, double dy);

    double x() const;
    double y() const;
    double angle() const;
    double magnitude() const;

private:
    double m_x{0.0};
    double m_y{0.0};
    double m_angle{0.0};
    double m_magnitude{0.0};
};
}
