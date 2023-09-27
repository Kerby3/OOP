#include "trapz.h"

double Trapz::calc(double(*function)(double), double a, double b) {
	double result = 0; //результат
	this->step = (b - a) / this->countOfPoints; //расчитываем шаг
	result = this->step * (function(a) + function(b)) / 2;
	for (int i = 1; i <= this->countOfPoints - 1; i++) {
		result += this->step * function(a + this->step * i);
	}
	return result;
}
