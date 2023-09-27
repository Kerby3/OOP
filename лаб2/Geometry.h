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
	int printCoordinates(); //����� ��������� �������
	
	void getCoordinatesByPoints(); //��������� ��������� ������� �� 2 ������
	double getLengthP(); //����� ������� �� ������
	double getLengthC(); //����� ������� �� �����������
	Vector sumVector(Vector vector2);
	Vector difVector(Vector vector2);
	Vector reverseVector(); //�������� ������
	Vector unitVector(); //��������� ������
	double scalarMultipleP(Vector vector2); //��������� ������������
	double scalarMultipleC(Vector vector2); //��������� ������������
	Vector vectorMultiple(Vector vector2); //���������� ������������
	double mixedMultiple(Vector vector2, Vector vector3); //��������� ������������
	double angleBetweenVectors(Vector vector2); //���� ����� ���������
	double distanceBetweenVectors(Vector vector2); //���������� ����� ���������
	bool isCollinear(Vector vector2); //�������� �� ��������������
	bool isCoplanar(Vector vector2, Vector vector3); //�������� �� ��������������
};