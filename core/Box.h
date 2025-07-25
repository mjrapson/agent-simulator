#pragma once

namespace core
{
class Box
{
public:
    Box(double x, double y, double width, double height);

    double x() const;
    double y() const;
    double width() const;
    double height() const;

private:
    double m_x{0.0};
    double m_y{0.0};
    double m_width{0.0};
    double m_height{0.0};
};
}
