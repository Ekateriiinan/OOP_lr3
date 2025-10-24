#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure {
public:
    Triangle(double x, double y, double radius);
    double area() const override;
    std::vector<std::pair<double, double>> getVertices() const override;
    Triangle* clone() const override;
};

#endif