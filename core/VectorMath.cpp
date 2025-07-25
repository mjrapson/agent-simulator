#include "VectorMath.h"

#include <cmath>

namespace core
{
Point2D operator+(const Point2D& point, const Vector2D& vector)
{
    return Point2D{point.x() + vector.x(), point.y() + vector.y()};
}

Vector2D operator*(const Vector2D& vector, const double scalar)
{
    return Vector2D{vector.x() * scalar, vector.y() * scalar};
}

Vector2D normalize(const Vector2D& vector)
{
    const auto magnitude = vector.magnitude();
    if (magnitude == 0)
    {
        return Vector2D{0.0, 0.0};
    }

    return Vector2D{vector.x() / magnitude, vector.y() / magnitude};
}

Vector2D distanceVectorBetween(const Point2D& from, const Point2D& to);
Vector2D normalizedDistanceVectorBetween(const Point2D& from, const Point2D& to);

Vector2D forwardVectorFromAngle(double angle)
{
    const auto dx = std::cos(angle);
    const auto dy = std::sin(angle);

    return Vector2D{dx, dy};
}
}
