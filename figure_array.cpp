#include "figure_array.h"

FigureArray::~FigureArray() {
    for (auto fig : figures) {
        delete fig;
    }
}

void FigureArray::addFigure(Figure* fig) {
    figures.push_back(fig);
}

void FigureArray::removeFigure(int index) {
    if (index >= 0 && index < figures.size()) {
        delete figures[index];
        figures.erase(figures.begin() + index);
    }
}

Figure* FigureArray::getFigure(int index) const {
    if (index >= 0 && index < figures.size()) {
        return figures[index];
    }
    return nullptr;
}

std::pair<double, double> FigureArray::getTotalCenter() const {
    double totalX = 0, totalY = 0;
    for (const auto& fig : figures) {
        auto center = fig->getCenter();
        totalX += center.first;
        totalY += center.second;
    }
    if (!figures.empty()) {
        totalX /= figures.size();
        totalY /= figures.size();
    }
    return {totalX, totalY};
}

double FigureArray::getTotalArea() const {
    double total = 0;
    for (const auto& fig : figures) {
        total += fig->area();
    }
    return total;
}

size_t FigureArray::size() const {
    return figures.size();
}

FigureArray::FigureArray(const FigureArray& other) {
    for (const auto& fig : other.figures) {
        figures.push_back(fig->clone());
    }
}

FigureArray::FigureArray(FigureArray&& other) noexcept : figures(std::move(other.figures)) {
    other.figures.clear();
}

FigureArray& FigureArray::operator=(const FigureArray& other) {
    if (this != &other) {
        for (auto fig : figures) {
            delete fig;
        }
        figures.clear();
        for (const auto& fig : other.figures) {
            figures.push_back(fig->clone());
        }
    }
    return *this;
}

FigureArray& FigureArray::operator=(FigureArray&& other) noexcept {
    if (this != &other) {
        for (auto fig : figures) {
            delete fig;
        }
        figures = std::move(other.figures);
        other.figures.clear();
    }
    return *this;
}