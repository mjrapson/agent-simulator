#pragma once

namespace core
{
class Point2D
{
public:
    Point2D(double x, double y);

    double x() const;
    double y() const;

private:
    double m_x{0.0};
    double m_y{0.0};
};
}
