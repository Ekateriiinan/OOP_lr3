#include "triangle.h"

Triangle::Triangle(double x, double y, double radius) 
    : Figure(x, y, radius, 3) {}

double Triangle::area() const {
    return (3.0 * sqrt(3.0) * radius * radius) / 4.0;
}

std::vector<std::pair<double, double>> Triangle::getVertices() const {
    std::vector<std::pair<double, double>> result;
    for (int i = 0; i < vertices; ++i) {
        double angle = 2.0 * M_PI * i / vertices - M_PI / 2.0;
        result.emplace_back(x + radius * cos(angle), 
                           y + radius * sin(angle));
    }
    return result;
}

Triangle* Triangle::clone() const {
    return new Triangle(*this);
}
