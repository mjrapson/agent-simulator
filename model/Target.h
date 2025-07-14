#pragma once

namespace model
{
class Target
{
public:
    Target(double x, double y);
    ~Target();

    double x() const;
    double y() const;

private:
    double m_x{0.0};
    double m_y{0.0};
};
}
