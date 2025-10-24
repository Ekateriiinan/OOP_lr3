#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure {
public:
    Square(double x, double y, double radius);
    double area() const override;
    std::vector<std::pair<double, double>> getVertices() const override;
    Square* clone() const override;
};

#endif