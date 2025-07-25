#pragma once

#include "Point2D.h"
#include "Vector2D.h"

namespace core
{
Point2D operator+(const Point2D& point, const Vector2D& vector);

Vector2D operator*(const Vector2D& vector, const double scalar);

Vector2D normalize(const Vector2D& vector);

Vector2D distanceVectorBetween(const Point2D& from, const Point2D& to);
Vector2D normalizedDistanceVectorBetween(const Point2D& from, const Point2D& to);
Vector2D forwardVectorFromAngle(double angle);
}
