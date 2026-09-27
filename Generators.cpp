#include "Generators.h"
#include <stdexcept>

Point Point::operator+(const Point& other) const {
    return {x + other.x, y + other.y};
}

Point Point::operator/(double num) const {
    return {x / num, y / num};
}