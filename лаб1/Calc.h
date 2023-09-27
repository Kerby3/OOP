#pragma once
#include <stdexcept> // Библиотека для обработки исключений
class Calc
{
	public:
		Calc(int countOfPoints, double step) {
			if (countOfPoints < 2 || step <= 0.0)
				throw std::exception(); // Генерируем исключение
			else {
				this->countOfPoints = countOfPoints;
				this->step = step;
			}
		}
		virtual double calc(double(*function)(double), double a, double b);
	protected:

		int countOfPoints = 0; //число отрезков
		double step = 0.0; //шаг
};

