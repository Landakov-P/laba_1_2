#include "Lab1_2.h"

namespace laba12 {

	double GetDouble() {
		double i;
		std::cin >> i;
		while (!std::cin.good()) {
			std::cout << "\nBad input, try again: ";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> i;
		}
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		return i;
	}

	int GetMenu(int max) {
		int i;
		std::cin >> i;
		while (!std::cin.good() || (i < 0 || i>max)) {
			std::cout << "\nBad input, try again: ";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cin >> i;
		}
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		return i;
	}

	Ellipse::Ellipse() {
		f1.x = 0;
		f1.y = 0;
		f2.x = 2;
		f2.y = 0;
		a = 5;
	}

	Ellipse::Ellipse(double f1x, double f1y, double f2x, double f2y, double baxis) {
		Point F1(f1x, f1y);
		Point F2(f2x, f2y);
		if (sqrt((F1.x - F2.x) * (F1.x - F2.x) + (F1.y - F2.y) * (F1.y - F2.y)) / 2 > baxis) {
			f1.x = 0;
			f1.y = 0;
			f2.x = 2;
			f2.y = 0;
			a = 5;
			throw std::invalid_argument("There cannot be an ellipse with such parameters, default ellipse was made");
		}
		else {
			f1 = F1;
			f2 = F2;
			a = baxis;
		}
	}

	Ellipse& Ellipse::setF1(Point F1) {
		if (sqrt((F1.x - f2.x) * (F1.x - f2.x) + (F1.y - f2.y) * (F1.y - f2.y)) / 2 > a)
			throw std::invalid_argument("Point cannot be the focus. It hasn't changed");
		f1 = F1;
		return *this;
	}

	Ellipse& Ellipse::setF2(Point F2) {
		if (sqrt((f1.x - F2.x) * (f1.x - F2.x) + (f1.y - F2.y) * (f1.y - F2.y)) / 2 > a)
			throw std::invalid_argument("Point cannot be the focus. It hasn't changed");
		f2 = F2;
		return *this;
	}

	Ellipse& Ellipse::setaxis(double baxis) {
		if (sqrt((f1.x - f2.x) * (f1.x - f2.x) + (f1.y - f2.y) * (f1.y - f2.y)) / 2 > baxis)
			throw std::invalid_argument("Too small sum. It hasn't changed");
		a = baxis;
		return *this;
	}

	Point Ellipse::getF1()const {
		return f1;
	}

	Point Ellipse::getF2()const {
		return f2;
	}

	double Ellipse::getaxis()const {
		return a;
	}

	double Ellipse::getc()const {
		return sqrt((f1.x - f2.x) * (f1.x - f2.x) + (f1.y - f2.y) * (f1.y - f2.y)) / 2;
	}

	double Ellipse::getexcentricity()const {
		return getc() / a;
	}

	double Ellipse::getlen()const {
		double b = sqrt(a * a - getc() * getc());
		return 4 * (3.1415926 * a * b * (a - b) * (a - b)) / (a + b);
	}

	double Ellipse::getarea()const {
		double b = sqrt(a * a - getc() * getc());
		return 3.1415926 * a * b;
	}

	double Ellipse::mindistance()const {
		return (a / 2) - getc();
	}

	double Ellipse::maxdistance()const {
		return (a / 2) + getc();
	}

	void Ellipse::gety(double x, double* y1, double* y2)const {
		double b = sqrt(a * a - getc() * getc());
		double y = b * b * (1 - (x * x / a / a));
		if (y < 0)
			throw std::invalid_argument("the ordinate does not belong to the ellipse. Try again.");
		*y1 = sqrt(y);
		*y2 = -sqrt(y);
	}
}