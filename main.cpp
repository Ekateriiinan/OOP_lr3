#include "figure_array.h"
#include "triangle.h"
#include "square.h"
#include "octagon.h"
#include <iostream>

void inputFigures(FigureArray& array) {
    std::cout << "Input figures (type: x y radius). Types: 1-Triangle, 2-Square, 3-Octagon, 0-Exit\n";
    
    int type;
    double x, y, radius;
    
    while (true) {
        std::cout << "Enter type: ";
        std::cin >> type;
        if (type == 0) break;
        
        if (type < 1 || type > 3) {
            std::cout << "Invalid type. Use 1, 2, or 3.\n";
            continue;
        }
        
        std::cout << "Enter x y radius: ";
        std::cin >> x >> y >> radius;
        
        Figure* fig = nullptr;
        switch (type) {
            case 1: fig = new Triangle(x, y, radius); break;
            case 2: fig = new Square(x, y, radius); break;
            case 3: fig = new Octagon(x, y, radius); break;
        }
        
        if (fig) {
            array.addFigure(fig);
            std::cout << "Figure added.\n";
        }
    }
}

int main() {
    FigureArray figures;
    
    inputFigures(figures);
    
    std::cout << "\n=== Figures Information ===\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "Figure " << i + 1 << ":\n";
        std::cout << *figures.getFigure(i) << "\n";
        std::cout << "Area: " << figures.getFigure(i)->area() << "\n";
        std::cout << "Center: (" << figures.getFigure(i)->getCenter().first 
                  << ", " << figures.getFigure(i)->getCenter().second << ")\n\n";
    }
    
    auto totalCenter = figures.getTotalCenter();
    double totalArea = figures.getTotalArea();
    
    std::cout << "=== Summary ===\n";
    std::cout << "Total figures: " << figures.size() << "\n";
    std::cout << "Total area: " << totalArea << "\n";
    std::cout << "Geometric center of all figures: (" 
              << totalCenter.first << ", " << totalCenter.second << ")\n";
    
    if (figures.size() >= 2) {
        std::cout << "\n=== Comparison Demo ===\n";
        bool equal = *figures.getFigure(0) == *figures.getFigure(1);
        std::cout << "First figure == Second figure: " << (equal ? "true" : "false") << "\n";
    }
    
    FigureArray copied = figures;
    std::cout << "\nCopied array size: " << copied.size() << "\n";
    
    return 0;
}