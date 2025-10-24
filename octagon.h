#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"

class Octagon : public Figure {
public:
    Octagon(double x, double y, double radius);
    double area() const override;
    std::vector<std::pair<double, double>> getVertices() const override;
    Octagon* clone() const override;
};

#endif