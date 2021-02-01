#ifndef LAB1_2_H
#define LAB1_2_H

#include <iostream>
#include <math.h>

namespace laba12 {

	struct Point {
		double x, y;
		Point(double x0 = 0, double y0 = 0) :x(x0), y(y0) {}
	};

	double GetDouble();
	int GetMenu(int max);

	class Ellipse {
	private:
		Point f1;
		Point f2;
		double a;
	public:
		Ellipse();
		Ellipse(double f1x, double f1y, double f2x, double f2y, double a);
		Ellipse& setF1(Point F1);
		Ellipse& setF2(Point F2);
		Ellipse& setaxis(double baxis);
		Point getF1()const;
		Point getF2()const;
		double getaxis()const;
		double getc()const;
		double getexcentricity()const;
		double getlen()const;
		double getarea()const;
		double mindistance()const;
		double maxdistance()const;
		void gety(double x, double* y1, double* y2)const;
	};
}


#endif // !LAB1_2_H

