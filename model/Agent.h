#pragma once

namespace model
{
class Agent
{
public:
    Agent(double x, double y);
    ~Agent();

    void moveForward(double distance, double angle);

    double x() const;
    double y() const;

private:
    double m_x{0.0};
    double m_y{0.0};
};
}
