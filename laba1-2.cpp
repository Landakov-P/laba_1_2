#include <iostream>
#include <math.h>
#include "laba1-2.h"

namespace laba12 {

	double GetDouble() {
		double i;
		std::cin >> i;
		while (!std::cin.good()) {
			std::cout << "\nBad input, try again: ";
			std::cin.clear();
			std::cin.ignore(1000,'\n');
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
		bigaxis = 5;
	}

	Ellipse::Ellipse(double f1x, double f1y, double f2x, double f2y, double baxis) {
		Point F1(f1x, f1y);
		Point F2(f2x, f2y);
		if (abs(sqrt((F1.x - F2.x) * (F1.x - F2.x) + (F1.y - F2.y) * (F1.y - F2.y))) / 2 > baxis) {
			f1.x = 0;
			f1.y = 0;
			f2.x = 2;
			f2.y = 0;
			bigaxis = 5;
			throw std::invalid_argument("There cannot be an ellipse with such parameters, default ellipse was made");
		}
		else {
			f1 = F1;
			f2 = F2;
			bigaxis = baxis;
		}
	}

	Ellipse& Ellipse::setF1(Point F1) {
		if ((abs(sqrt((F1.x - f2.x) * (F1.x - f2.x) + (F1.y - f2.y) * (F1.y - f2.y)))) > bigaxis) {
			throw std::invalid_argument("Point cannot be the focus. It hasn't changed");
		}
		else {
			f1 = F1;
		}
		return *this;
	}
	Ellipse& Ellipse::setF2(Point F2) {
		if ((abs(sqrt((f1.x - F2.x) * (f1.x - F2.x) + (f1.y - F2.y) * (f1.y - F2.y)))) > bigaxis) {
			throw std::invalid_argument("Point cannot be the focus. It hasn't changed");
		}
		else {
			f2 = F2;
		}
		return *this;
	}
	Ellipse& Ellipse::setaxis(double baxis) {
		if ((abs(sqrt((f1.x - f2.x) * (f1.x - f2.x) + (f1.y - f2.y) * (f1.y - f2.y)))) > baxis) {
			throw std::invalid_argument("Too small sum. It hasn't changed");
		}
		else {
			bigaxis = baxis;
		}
		return *this;
	}
	Point Ellipse::getF1() {
		return f1;
	}
	Point Ellipse::getF2() {
		return f2;
	}
	double Ellipse::getaxis() {
		return bigaxis;
	}
	double Ellipse::getf() {
		return abs(sqrt((f1.x - f2.x) * (f1.x - f2.x) + (f1.y - f2.y) * (f1.y - f2.y)))/2;
	}
	double Ellipse::getexcentricity() {
		return abs(sqrt((f1.x - f2.x) * (f1.x - f2.x) + (f1.y - f2.y) * (f1.y - f2.y))) / 2 / bigaxis;
	}
	double Ellipse::getlen() {
		double b = sqrt(bigaxis * bigaxis - abs(sqrt((f1.x - f2.x) * (f1.x - f2.x) + (f1.y - f2.y) * (f1.y - f2.y))) * abs(sqrt((f1.x - f2.x) * (f1.x - f2.x) + (f1.y - f2.y) * (f1.y - f2.y))) / 4);
		return 4 * ((3.1415926 * bigaxis * b + (bigaxis - b) * (bigaxis - b)) / (bigaxis + b));
	}
	double Ellipse::getarea() {
		return (3.1415926 * bigaxis * sqrt(bigaxis * bigaxis - abs(sqrt((f1.x - f2.x) * (f1.x - f2.x) + (f1.y - f2.y) * (f1.y - f2.y))) * abs(sqrt((f1.x - f2.x) * (f1.x - f2.x) + (f1.y - f2.y) * (f1.y - f2.y))) / 4));
	}
	double Ellipse::mindistance() {
		return (bigaxis / 2) - abs(sqrt((f1.x - f2.x) * (f1.x - f2.x) + (f1.y - f2.y) * (f1.y - f2.y))) / 2;
	}
	double Ellipse::maxdistance() {
		return bigaxis - ((bigaxis / 2) - abs(sqrt((f1.x - f2.x) * (f1.x - f2.x) + (f1.y - f2.y) * (f1.y - f2.y))) / 2);
	}
	void Ellipse::gety(double x, double* y1, double* y2) {
		double a = bigaxis;
		double m = f1.x;
		double l = f1.y;
		double k = f2.x;
		double h = f2.y;
		double q = (k - x) * (k - x);
		double w = (x - m) * (x - m);
		*y1 = (a * a * h + a * a * l + sqrt(a * a * a * a * a * a - 2 * a * a * a * a * h * h + 4 * a * a * a * a * h * l - 2 * a * a * a * a * l * l - 2 * a * a * a * a * q - 2 * a * a * a * a * w + a * a * h * h * h * h - 4 * a * a * h * h * h * l + 6 * a * a * h * h * l * l + 2 * a * a * h * h * q + 2 * a * a * h * h * w - 4 * a * a * h * l * l * l - 4 * a * a * h * l * q - 4 * a * a * h * l * w + a * a * l * l * l * l + 2 * a * a * l * l * q + 2 * a * a * l * l * w + a * a * q * q - 2 * a * a * q * w + a * a * w * w) - h * h * h + h * h * l + h * l * l - h * q + h * w - l * l * l + l * q - l * w) / (2 * (a * a - h * h + 2 * h * l - l * l));
		*y2 = (a * a * h + a * a * l - sqrt(a * a * a * a * a * a - 2 * a * a * a * a * h * h + 4 * a * a * a * a * h * l - 2 * a * a * a * a * l * l - 2 * a * a * a * a * q - 2 * a * a * a * a * w + a * a * h * h * h * h - 4 * a * a * h * h * h * l + 6 * a * a * h * h * l * l + 2 * a * a * h * h * q + 2 * a * a * h * h * w - 4 * a * a * h * l * l * l - 4 * a * a * h * l * q - 4 * a * a * h * l * w + a * a * l * l * l * l + 2 * a * a * l * l * q + 2 * a * a * l * l * w + a * a * q * q - 2 * a * a * q * w + a * a * w * w) - h * h * h + h * h * l + h * l * l - h * q + h * w - l * l * l + l * q - l * w) / (2 * (a * a - h * h + 2 * h * l - l * l));
	}
}