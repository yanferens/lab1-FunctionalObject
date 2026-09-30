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

Point SequenceGenerator::operator()() {
    if (first_call) {
        first_call = false;
        return current_y;
    }

    int idx = _randomNumbers.next();
    const Point& b_k = base_points[idx - 1];

    current_y = (b_k + current_y) / 2.0;
    return current_y;
}

bool SequenceGenerator::set(const std::vector<Point>& bases, const Point& x0) {
    if (bases.empty()) {
        return false;
    }
    _randomNumbers = RandomIntGenerator(1, bases.size());
    base_points = bases;
    first_call = true;
    current_y = x0;
    return true;
}

SequenceGenerator::SequenceGenerator(Point x0, const std::vector<Point>& bases) : SequenceGenerator() {

    if (!set(bases, x0)) {
        throw std::invalid_argument("Base points vector cannot be empty!");
    }
}