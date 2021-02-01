#include "Lab1_2.h"


using namespace laba12;

int main() {
	Ellipse el;
	int menu = 11;
	std::cout << "Enter 0 if you want to use default ellipse" << std::endl << "If you want to use non-default ellipse - enter 1" << std::endl;
	menu = GetMenu(1);
	if (menu == 1) {
		std::cout << "Enter x of the 1st focus, y of the 1st focus, x of the 2nd focus, y of the 2nd focus and the sum of distances to focuses one by one using enter:" << std::endl;
		double q = GetDouble();
		double w = GetDouble();
		double e = GetDouble();
		double r = GetDouble();
		double t = GetDouble();
		try {
			Ellipse eli(q, w, e, r, t);
			el = eli;
		}
		catch (std::invalid_argument err) {
			std::cout << err.what() << std::endl;
		}
	}
	menu = 11;
	while (menu != 0) {
		std::cout << std::endl << "0 - Quit" << std::endl << "1 - Change F1" << std::endl << "2 - Change F2" << std::endl << "3 - Change sum of distances to focuses" << std::endl << "4 - Output F1" << std::endl << "5 - Output F2" << std::endl << "6 - Output sum of distances to focuses" << std::endl << "7 - Get focal distance" << std::endl << "8 - Get excentricity" << std::endl << "9 - Get approximate ellipse length" << std::endl << "10 - Get ellipse area" << std::endl << "11 - Get minimum distance between focus and point of ellipse" << std::endl << "12 - Get maximum distance between focus and point of ellipse" << std::endl << "13 - Get y coordinate by given x" << std::endl << "Enter the number to continue:";
		menu = GetMenu(13);
		std::cout << std::endl;
		if (menu == 1 || menu == 2) {
			std::cout << "Enter x and y of the focus one by one using enter:" << std::endl;
			double a = GetDouble();
			double b = GetDouble();
			try {
				if (menu == 1) { el.setF1(Point(a, b)); }
				if (menu == 2) { el.setF2(Point(a, b)); }
			}
			catch (std::invalid_argument err) {
				std::cout << err.what() << std::endl;
			}
		}
		if (menu == 3) {
			std::cout << "Enter the sum:" << std::endl;
			double a = GetDouble();
			try {
				el.setaxis(a);
			}
			catch (std::invalid_argument err) {
				std::cout << err.what() << std::endl;
			}
		}
		if (menu == 4) std::cout << "F1 is:" << " (" << el.getF1().x << ", " << el.getF1().y << ")" << std::endl;
		if (menu == 5) std::cout << "F2 is:" << " (" << el.getF2().x << ", " << el.getF2().y << ")" << std::endl;
		if (menu == 6) std::cout << "Sum of distances to focuses is:" << el.getaxis() << std::endl;
		if (menu == 7) std::cout << "Focal distance is:" << el.getc() << std::endl;
		if (menu == 8) std::cout << "Excentricity is:" << el.getexcentricity() << std::endl;
		if (menu == 9) std::cout << "Length of ellipse is:" << el.getlen() << std::endl;
		if (menu == 10) std::cout << "Ellipse area is:" << el.getarea() << std::endl;
		if (menu == 11) std::cout << "Minimum distance is:" << el.mindistance() << std::endl;
		if (menu == 12) std::cout << "Maximum distance is:" << el.maxdistance() << std::endl;
		if (menu == 13) {
			double y1, y2;
			std::cout << "Enter the x:";
			double a = GetDouble();
			try {
				el.gety(a, &y1, &y2);
				std::cout << std::endl << "y(" << a << ")is:" << y1 << std::endl;
				std::cout << "y(" << a << ")is:" << y2 << std::endl;
			}
			catch (const std::invalid_argument& ex) {
				std::cout << ex.what() << '\n';
			}
		}
	}
	return 0;
}