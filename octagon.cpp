#include "octagon.h"

Octagon::Octagon(double x, double y, double radius) 
    : Figure(x, y, radius, 8) {}

double Octagon::area() const {
    return 2.0 * sqrt(2.0) * radius * radius;
}

std::vector<std::pair<double, double>> Octagon::getVertices() const {
    std::vector<std::pair<double, double>> result;
    for (int i = 0; i < vertices; ++i) {
        double angle = 2.0 * M_PI * i / vertices - M_PI / 8.0;
        result.emplace_back(x + radius * cos(angle), 
                           y + radius * sin(angle));
    }
    return result;
}

Octagon* Octagon::clone() const {
    return new Octagon(*this);
}