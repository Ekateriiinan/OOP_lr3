#include "square.h"

Square::Square(double x, double y, double radius) 
    : Figure(x, y, radius, 4) {}

double Square::area() const {
    return 2.0 * radius * radius;
}

std::vector<std::pair<double, double>> Square::getVertices() const {
    std::vector<std::pair<double, double>> result;
    for (int i = 0; i < vertices; ++i) {
        double angle = 2.0 * M_PI * i / vertices - M_PI / 4.0;
        result.emplace_back(x + radius * cos(angle), 
                           y + radius * sin(angle));
    }
    return result;
}

Square* Square::clone() const {
    return new Square(*this);
}