#pragma once

#include <vector>
#include <random>

struct Point {
    double x = 0.0;
    double y = 0.0;
    Point operator+(const Point &other) const;
    Point operator/(double num) const;
};

class RandomIntGenerator {
private:
    std::mt19937_64 engine;
    std::uniform_int_distribution<int> distribution;

public:
    RandomIntGenerator();
    RandomIntGenerator(int min, int max);
    ~RandomIntGenerator() = default;

    RandomIntGenerator(const RandomIntGenerator&) = delete;
    RandomIntGenerator& operator=(const RandomIntGenerator&) = delete;

    RandomIntGenerator(RandomIntGenerator&&) noexcept = default;
    RandomIntGenerator& operator=(RandomIntGenerator&&) noexcept = default;

    int next();
};
