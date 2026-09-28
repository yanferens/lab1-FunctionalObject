#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

#include "Generators.h"

using namespace std;

void checkIn(ifstream& in) {
    if (!in.is_open()) {
        throw runtime_error("Failed to open input file");
    }
}

void checkOut(ofstream& out) {
    if (!out.is_open()) {
        throw runtime_error("Failed to open output file");
    }
}

int getN(ifstream& in) {
    int n;
    if (!(in >> n) || n <= 0) {
        throw runtime_error("Invalid or non-positive value");
    }
    return n;
}

Point getX0(ifstream& in) {
    Point x0;
    if (!(in >> x0.x >> x0.y)) {
        throw runtime_error("Failed to read initial point x0");
    }
    return x0;
}

void checkBasePoints(const vector<Point>& base_points) {
    if (base_points.empty()) {
        throw runtime_error("No base points found in input file");
    }
}

vector<Point> inputBasePoints(ifstream& in) {
    Point b;
    vector<Point> base_points;
    while (in >> b.x >> b.y) {
        base_points.push_back(b);
    }
    checkBasePoints(base_points);
    return base_points;
}

void getInputData(int& n, Point& x0, vector<Point>& base_points) {
    ifstream in("input.txt");
    checkIn(in);
    n = getN(in);
    x0 = getX0(in);
    base_points = inputBasePoints(in);
    in.close();
}

int main() {

}

