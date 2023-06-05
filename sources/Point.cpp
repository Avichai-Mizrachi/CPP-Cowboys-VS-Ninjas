#include "Point.hpp"

namespace ariel
{
    Point::Point(double x, double y) : x(x), y(y) {}

    // Calculates the distance between two points
    double Point::distance(Point other)
    {
        double distance = sqrt(pow((this->getX()) - (other.getX()), 2) + pow((this->getY()) - (other.getY()), 2));
        return distance;
    }

    // Print the point
    string Point::print()
    {
        return "(" + to_string(x) + " , " + to_string(y) + ")";
    }

    // Moving toward another point (enemy point)
    Point Point::moveTowards(Point &original, Point &target, double distance)
    {
        // In case the distance is negative
        if (distance < 0)
        {
            throw invalid_argument("Distance cannot be negative");
        }

        // In case the distance is bigger than
        // the distance between the two points
        else if (distance > original.distance(target))
        {
            return Point(target.getX(), target.getY());
        }

        // The code calculates a new point that lies at
        // a certain distance between two given points (original and target).
        double x1 = original.getX();
        double y1 = original.getY();
        double x2 = target.getX();
        double y2 = target.getY();
        double x3 = x1 + (distance * (x2 - x1) / original.distance(target));
        double y3 = y1 + (distance * (y2 - y1) / original.distance(target));
        return Point(x3, y3);
    }
}