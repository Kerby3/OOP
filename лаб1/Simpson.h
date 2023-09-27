#pragma once
#include "Calc.h"

class Simpson : public Calc
{
public:
	Simpson(int countOfPoints, double step) : Calc(countOfPoints, step) {}
	double calc(double(*function)(double), double a, double b) override;
};

