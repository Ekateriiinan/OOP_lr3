#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <vector>
#include <cmath>
#include <utility>

class Figure {
protected:
    double x, y;
    double radius;
    int vertices;

public:
    Figure(double x, double y, double radius, int vertices);
    virtual ~Figure() = default;

    virtual std::pair<double, double> getCenter() const;
    virtual double area() const = 0;
    virtual std::vector<std::pair<double, double>> getVertices() const = 0;
    virtual Figure* clone() const = 0;

    virtual bool operator==(const Figure& other) const;
    Figure& operator=(const Figure& other);
    virtual operator double() const;

    friend std::ostream& operator<<(std::ostream& os, const Figure& fig);
};

#endif