//Compiler: MSVC v143 (Visual Studio 2022)

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


void printInputMessage(int n, const Point& x0, const vector<Point>& base_points) {
    cout << "Number of points to generate (n): " << n << endl;
    cout << "Initial point (x0): (" << x0.x << ", " << x0.y << ")" << endl;
    cout << "Base points size: " << base_points.size() << endl;
}


void getPoints(ofstream& out, int n, const Point& x0, const vector<Point>& base_points) {
    SequenceGenerator generator(x0, base_points);
    for (int i = 0; i < n; ++i) {
        Point p = generator();
        out << p.x << " " << p.y << "\n";
    }
}

void printOutputMessage(int n) {
    cout << "Generated " << n << " points and saved to output.txt" << endl;
}

void writeOutputInfo(int n, const Point& x0, const vector<Point>& base_points) {
    ofstream out("output.txt");
    checkOut(out);
    getPoints(out, n, x0, base_points);
    printOutputMessage(n);
    out.close();
}


int main() {
    try {
        int n;
        Point x0;
        vector<Point> base_points;

        getInputData(n, x0, base_points);
        printInputMessage(n, x0, base_points);
        writeOutputInfo(n, x0, base_points);
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

}


