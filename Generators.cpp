#include "Generators.h"
#include <stdexcept>

Point Point::operator+(const Point& other) const {
    return {x + other.x, y + other.y};
}

Point Point::operator/(double num) const {
    return {x / num, y / num};
}

RandomIntGenerator::RandomIntGenerator(int min, int max)
    : engine(std::random_device{}()), distribution(min, max) {}

RandomIntGenerator::RandomIntGenerator():RandomIntGenerator(0, 0) {}

int RandomIntGenerator::next() {
    return distribution(engine);
}