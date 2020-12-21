#include "pch.h"
#include "../laba1-2var21/laba1-2.h"
#include "../laba1-2var21/laba1-2.cpp"

TEST(EllipseConstruct, DefaultConstructor) {
    laba12::Ellipse el;
    ASSERT_EQ(0, el.getF1().x);
    ASSERT_EQ(0, el.getF1().y);
    ASSERT_EQ(2, el.getF2().x);
    ASSERT_EQ(0, el.getF2().y);
    ASSERT_EQ(5, el.getaxis());
}
TEST(EllipseConstruct, InitializeConstructor) {
    laba12::Ellipse el(1, 1, 4, 7, 50);
    ASSERT_EQ(1, el.getF1().x);
    ASSERT_EQ(1, el.getF1().y);
    ASSERT_EQ(4, el.getF2().x);
    ASSERT_EQ(7, el.getF2().y);
    ASSERT_EQ(50, el.getaxis());
}
TEST(EllipseConstruct, BadInput) {
    ASSERT_ANY_THROW(laba12::Ellipse el(1, 1, 1, 9, 0.5));
}

TEST(EllipseSetter, SetF1) {
    laba12::Ellipse el;
    laba12::Point a(20, 20);
    ASSERT_ANY_THROW(el.setF1(a));
    laba12::Point a1(1, 1);
    el.setF1(a1);
    ASSERT_EQ(1, el.getF1().x);
    ASSERT_EQ(1, el.getF1().y);
}
TEST(EllipseSetter, SetF2) {
    laba12::Ellipse el;
    laba12::Point a(20, 20);
    ASSERT_ANY_THROW(el.setF2(a));
    laba12::Point a1(1, 1);
    el.setF2(a1);
    ASSERT_EQ(1, el.getF2().x);
    ASSERT_EQ(1, el.getF2().y);
}
TEST(EllipseSetter, SetAxis) {
    laba12::Ellipse el;
    ASSERT_ANY_THROW(el.setaxis(0.0002));
    el.setaxis(100);
    ASSERT_EQ(100, el.getaxis());
}

TEST(Ellipse, getf) {
    laba12::Ellipse el;
    ASSERT_EQ(1, el.getf());
    laba12::Ellipse el1(0, 0, 4, 0, 10);
    ASSERT_EQ(2, el1.getf());
}
TEST(Ellipse, getexcentricity) {
    laba12::Ellipse el;
    ASSERT_EQ(0.2, el.getexcentricity());
    laba12::Ellipse el1(0, 0, 4, 0, 10);
    ASSERT_EQ(0.2, el1.getexcentricity());
}
TEST(Ellipse, getlen) {
    laba12::Ellipse el;
    ASSERT_NEAR(31.0994, el.getlen(), 0.0001);
    laba12::Ellipse el1(0, 0, 4, 0, 10);
    ASSERT_NEAR(62.1989, el1.getlen(), 0.0001);
}
TEST(Ellipse, getarea) {
    laba12::Ellipse el;
    ASSERT_NEAR(76.953, el.getarea(), 0.0001);
    laba12::Ellipse el1(0, 0, 4, 0, 10);
    ASSERT_NEAR(307.812, el1.getarea(), 0.0001);
}
TEST(Ellipse, mindistance) {
    laba12::Ellipse el;
    ASSERT_EQ(1.5, el.mindistance());
    laba12::Ellipse el1(0, 0, 4, 0, 10);
    ASSERT_EQ(3, el1.mindistance());
}
TEST(Ellipse, maxdistance) {
    laba12::Ellipse el;
    ASSERT_EQ(3.5, el.maxdistance());
    laba12::Ellipse el1(0, 0, 4, 0, 10);
    ASSERT_EQ(7, el1.maxdistance());
}
TEST(Ellipse, gety) {
    laba12::Ellipse el;
    double a, b;
    el.gety(2, &a, &b);
    ASSERT_NEAR(2.1, a, 0.0001);
    ASSERT_NEAR(-2.1, b, 0.0001);
    el.gety(3.5, &a, &b);
    ASSERT_EQ(0, a);
    ASSERT_EQ(a, b);
    el.gety(5, &a, &b);
    ASSERT_TRUE(isnan(a));
    ASSERT_TRUE(isnan(b));
    laba12::Ellipse el1(0, 0, 4, 0, 10);
    double a1, b1;
    el1.gety(5.5, &a1, &b1);
    ASSERT_NEAR(3.27261, a1, 0.00001);
    ASSERT_NEAR(-3.27261, b1, 0.00001);
    el1.gety(7, &a1, &b1);
    ASSERT_EQ(0, a1);
    ASSERT_EQ(a1, b1);
    el1.gety(100, &a1, &b1);
    ASSERT_TRUE(isnan(a1));
    ASSERT_TRUE(isnan(b1));
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}