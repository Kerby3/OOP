#include <iostream>
#pragma once

class Point
{
private:
	double x;
	double y;
	double z;
public:
	Point(double x = 0, double y = 0, double z = 0) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	double getX();
	double getY();
	double getZ();
};

class Vector {
private:
	double x;
	double y;
	double z;
	Point point1;
	Point point2;
public:
	Vector(double x = 0, double y = 0, double z = 0) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector(Point point1, Point point2) {
		this->point1 = point1;
		this->point2 = point2;
	}
	double getX();
	double getY();
	double getZ();
	int printCoordinates(); //вывод координат вектора
	
	void getCoordinatesByPoints(); //получение координат вектора по 2 точкам
	double getLengthP(); //длина вектора по точкам
	double getLengthC(); //длина вектора по координатам
	Vector sumVector(Vector vector2);
	Vector difVector(Vector vector2);
	Vector reverseVector(); //обратный вектор
	Vector unitVector(); //единичный вектор
	double scalarMultipleP(Vector vector2); //скалярное произведение
	double scalarMultipleC(Vector vector2); //скалярное произведение
	Vector vectorMultiple(Vector vector2); //вектороное произведение
	double mixedMultiple(Vector vector2, Vector vector3); //смешанное произведение
	double angleBetweenVectors(Vector vector2); //угол между векторами
	double distanceBetweenVectors(Vector vector2); //расстояние между векторами
	bool isCollinear(Vector vector2); //проверка на коллинеарность
	bool isCoplanar(Vector vector2, Vector vector3); //проверка на компланарность
};