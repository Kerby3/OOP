#pragma once
#include "Calc.h"
class Trapz : public Calc 
{
public:
	Trapz(int countOfPoints, double step) : Calc(countOfPoints, step) {}
	double calc(double(*function)(double), double a, double b) override;
};

