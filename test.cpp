#include "pch.h"
#include "../Domain/Point.h"
#include "../Domain/Circle.h"
#include "../Domain/Point.cpp"
#include "../Domain/Circle.cpp"
#include <sstream>

TEST(OperatorEqual_Point_Success) {
    Point p1(5, 6);
    Point p2(5, 6);
    EXPECT_TRUE(p1 == p2);
}

TEST(OperatorInequal_Point_Success) {
    Point p1(5, 6);
    Point p2(7, 8);
    EXPECT_TRUE(p1 != p2);
}

TEST(OperatorAdd_Point_Success) {
    Point p(1, 2);
    Point result = p + 3;
    EXPECT_EQ(result.getX(), 4);
    EXPECT_EQ(result.getY(), 5);
}

TEST(OperatorSubtract_Point_Success) {
    Point p(5, 6);
    Point result = p - 2;
    EXPECT_EQ(result.getX(), 3);
    EXPECT_EQ(result.getY(), 4);
}

TEST(ConstructorInvalidRadius_Circle_ExpectThrow) {
    Point center(0, 0);
    EXPECT_THROW(Circle c(center, -1), std::invalid_argument);
}

TEST(ToString_Circle_Success) {
    Point center(2, 3);
    Circle c(center, 4);
    EXPECT_EQ(c.ToString(), "Circle with center (2, 3) and radius 4");
}

TEST(ReadFromInput_Circle_Success) {
    std::istringstream input("4 5 6");
    Shape* shape = Circle::ReadFromInput(input);
    Circle* c = dynamic_cast<Circle*>(shape);
    ASSERT_NE(c, nullptr);
    EXPECT_EQ(c->ToString(), "Circle with center (4, 5) and radius 6");
    delete c;
}