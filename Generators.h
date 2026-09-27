#pragma once

#include <vector>
#include <random>

struct Point {
    double x = 0.0;
    double y = 0.0;
    Point operator+(const Point &other) const;
    Point operator/(double num) const;
};
