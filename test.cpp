#include "gtest/gtest.h"
#include "Ellipse.h"

using namespace laba12;

TEST(Constructors, EmptyConstructor) {
	Ellipse el;
	EXPECT_EQ(0, el.getF1().x);
	EXPECT_EQ(0, el.getF1().y);
	EXPECT_EQ(2, el.getF2().x);
	EXPECT_EQ(0, el.getF2().y);
	EXPECT_EQ(5, el.getaxis());
}

TEST(Constructors, DefaultConstructors) {
	Ellipse el(-2, 0, 2, 0, 4);
	EXPECT_EQ(-2, el.getF1().x);
	EXPECT_EQ(0, el.getF1().y);
	EXPECT_EQ(2, el.getF2().x);
	EXPECT_EQ(0, el.getF2().y);
	EXPECT_EQ(4, el.getaxis());
	EXPECT_ANY_THROW(Ellipse el2(0, 10, 0, -10, 2));
}


TEST(Setters, SetF1) {
	Ellipse el;
	Point p(2, 10);
	el.setF1(p);
	EXPECT_EQ(2, el.getF1().x);
	EXPECT_EQ(10, el.getF1().y);
	p = { 0,100 };
	EXPECT_ANY_THROW(el.setF1(p));
}

TEST(Setters, SetF2) {
	Ellipse el;
	Point p(2, 5);
	el.setF2(p);
	EXPECT_EQ(2, el.getF2().x);
	EXPECT_EQ(5, el.getF2().y);
	p = { 0,100 };
	EXPECT_ANY_THROW(el.setF2(p));
}


TEST(Setters, SetAxis) {
	Ellipse el;
	el.setaxis(20);
	EXPECT_EQ(20, el.getaxis());
	EXPECT_ANY_THROW(el.setaxis(0.01));
}


TEST(Getters, GetC) {
	Ellipse el(-2, 0, 2, 0, 4);
	EXPECT_NEAR(2.0, el.getc(), 0.1);
}

TEST(Getters, getExcentricity) {
	Ellipse el(-2, 0, 2, 0, 4);
	EXPECT_NEAR(0.5, el.getexcentricity(), 0.1);
}

TEST(Getters, getLen) {
	Ellipse el(-2, 0, 2, 0, 4);
	EXPECT_NEAR(6.69, el.getlen(), 0.1);
}

TEST(Getters, getArea) {
	Ellipse el(-2, 0, 2, 0, 4);
	EXPECT_NEAR(43.53, el.getarea(), 0.1);
}

TEST(Getters, getY) {
	Ellipse el(-2, 0, 2, 0, 4);
	double y1, y2;
	el.gety(2, &y1, &y2);
	EXPECT_NEAR(2.99, y1, 0.1);
	EXPECT_NEAR(-2.99, y2, 0.1);
}