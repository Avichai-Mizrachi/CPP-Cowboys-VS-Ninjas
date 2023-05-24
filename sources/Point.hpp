#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <float.h>
#include <stdexcept>

using namespace std;

namespace ariel
{
    class Point
    {

    private:
        double y;
        double x;

    public:
        Point(double x, double y);
        double distance(Point other);
        double getX() { return x; }
        double getY() { return y; }
        void setX(double xPoint) { x = xPoint; }
        void setY(double yPoint) { y = yPoint; }
        virtual string print();
        static Point moveTowards(Point &original, Point &target, double distance);
    };
}