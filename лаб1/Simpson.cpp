#include "Simpson.h"
double Simpson::calc(double(*function)(double), double a, double b) {
	double result = 0; //результат
	this->step = (b - a) / (2 * this->countOfPoints);
	result = function(a) + function(b);
	for (int i = 1; i <= 2 * this->countOfPoints - 1; i++) {
		if (i % 2 == 0) {
			result += 2 * function(a + this->step * i);
		}
		else {
			result += 4 * function(a + this->step * i);
		}
	}
	result = result * this->step / 3;
	return result;
}
