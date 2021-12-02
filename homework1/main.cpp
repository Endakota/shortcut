#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
bool isRight(double x0, double y0, double x, double y) {
	if (x0 > 0) return (y0 / x0 * x - y >= 0) ? true : false;
	else return(y - y0 / x0 * x > 0) ? true : false;

}
double distance(double x0, double y0, double x, double y) {
	return (y0 == 0 && x0 != 0) ? fabs(y) : (x0 == 0 && y0 != 0) ? fabs(x) : fabs(y0 / x0 * x - y) / sqrt(y0 * y0 / x0 / x0 + 1);
}
int main()
{
	double x0, y0;
	double distance0, distanceR = 0, distanceL = 0;
	double xrightm = 0, xleftm = 0, yrightm = 0, yleftm = 0;
	ifstream file("in.txt");
	if (!file.is_open()) {
		cout << "OpenError";
	}
	else {
		file >> x0 >> y0;
		double x, y;
		while (file >> x >> y) {
			distance0 = fabs(distance(x0, y0, x, y));
			if (isRight(x0, y0, x, y)) {
				if (distance0 >= distanceR) {
					distanceR = distance0;
					xrightm = x;
					yrightm = y;
				}
			}
			else {
				if (distance0 >= distanceL) {
					distanceL = distance0;
					xleftm = x;
					yleftm = y;
				}
			}
		}
		cout << "Leftmost: " << xleftm << " " << yleftm << endl;
		cout << "Rightmost: " << xrightm << " " << yrightm << endl;
	}

	return 0;
}