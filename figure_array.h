#ifndef FIGURE_ARRAY_H
#define FIGURE_ARRAY_H

#include "figure.h"
#include <vector>

class FigureArray {
private:
    std::vector<Figure*> figures;

public:
    ~FigureArray();
    void addFigure(Figure* fig);
    void removeFigure(int index);
    Figure* getFigure(int index) const;
    std::pair<double, double> getTotalCenter() const;
    double getTotalArea() const;
    size_t size() const;

    FigureArray() = default;
    FigureArray(const FigureArray& other);
    FigureArray(FigureArray&& other) noexcept;
    FigureArray& operator=(const FigureArray& other);
    FigureArray& operator=(FigureArray&& other) noexcept;
};

#endif