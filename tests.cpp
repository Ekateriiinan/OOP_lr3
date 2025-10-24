#include <gtest/gtest.h>
#include "triangle.h"
#include "square.h"
#include "octagon.h"
#include "figure_array.h"

TEST(FigureTest, AreaCalculation) {
    Triangle t(0, 0, 1.0);
    Square s(0, 0, 1.0);
    Octagon o(0, 0, 1.0);
    
    EXPECT_NEAR(t.area(), 1.299, 0.001);
    EXPECT_NEAR(s.area(), 2.0, 0.001);
    EXPECT_NEAR(o.area(), 2.828, 0.001);
}

TEST(FigureTest, VerticesCount) {
    Triangle t(0, 0, 1.0);
    Square s(0, 0, 1.0);
    Octagon o(0, 0, 1.0);
    
    EXPECT_EQ(t.getVertices().size(), 3);
    EXPECT_EQ(s.getVertices().size(), 4);
    EXPECT_EQ(o.getVertices().size(), 8);
}

TEST(FigureTest, CenterAndConversion) {
    Square s(2.0, 3.0, 1.0);
    auto center = s.getCenter();
    
    EXPECT_DOUBLE_EQ(center.first, 2.0);
    EXPECT_DOUBLE_EQ(center.second, 3.0);
    EXPECT_NEAR(static_cast<double>(s), 2.0, 0.001);
}

TEST(FigureTest, Equality) {
    Triangle t1(0, 0, 1.0);
    Triangle t2(0, 0, 1.0);
    Triangle t3(1, 1, 2.0);
    
    EXPECT_TRUE(t1 == t2);
    EXPECT_FALSE(t1 == t3);
}

TEST(FigureArrayTest, BasicOperations) {
    FigureArray array;
    array.addFigure(new Triangle(0, 0, 1.0));
    array.addFigure(new Square(0, 0, 1.0));
    
    EXPECT_EQ(array.size(), 2);
    
    double total = array.getTotalArea();
    EXPECT_NEAR(total, 3.299, 0.001);
    
    array.removeFigure(0);
    EXPECT_EQ(array.size(), 1);
}

TEST(FigureArrayTest, CopyAndMove) {
    FigureArray array;
    array.addFigure(new Triangle(0, 0, 1.0));
    
    FigureArray copied = array;
    EXPECT_EQ(copied.size(), 1);
    
    FigureArray moved = std::move(array);
    EXPECT_EQ(moved.size(), 1);
    EXPECT_EQ(array.size(), 0);
}