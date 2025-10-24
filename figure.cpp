#include "figure.h"

Figure::Figure(double x, double y, double radius, int vertices) 
    : x(x), y(y), radius(radius), vertices(vertices) {}

std::pair<double, double> Figure::getCenter() const {
    return {x, y};
}

Figure::operator double() const {
    return area();
}

bool Figure::operator==(const Figure& other) const {
    return x == other.x && y == other.y && 
           radius == other.radius && vertices == other.vertices;
}

Figure& Figure::operator=(const Figure& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        radius = other.radius;
        vertices = other.vertices;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Figure& fig) {
    auto vertices = fig.getVertices();
    for (size_t i = 0; i < vertices.size(); ++i) {
        os << "Vertex " << i + 1 << ": (" << vertices[i].first 
           << ", " << vertices[i].second << ")";
        if (i != vertices.size() - 1) os << "\n";
    }
    return os;
}