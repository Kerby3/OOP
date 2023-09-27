#include "Geometry.h"
#include <math.h>
#define _USE_MATH_DEFINES

double Point::getX() {
	return this->x;
}

double Point::getY() {
	return this->y;
}

double Point::getZ() {
	return this->z;
}



double Vector::getX() {
	return this->x;
}

double Vector::getY() {
	return this->y;
}

double Vector::getZ() {
	return this->z;
}

void Vector::getCoordinatesByPoints() {
	this->x = point2.getX() - point1.getX();
	this->y = point2.getY() - point1.getY();
	this->z = point2.getZ() - point1.getZ();
}




double Vector::getLengthP() {
	return sqrt(pow(this->point2.getX() - this->point1.getX(), 2) + pow(this->point2.getY() - this->point1.getY(), 2) + pow(this->point2.getZ() - this->point1.getZ(), 2));
}

double Vector::getLengthC() {
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

Vector Vector::sumVector(Vector vector2) {
	return Vector(this->x + vector2.x, this->y + vector2.y, this->z + vector2.z);
}

Vector Vector::difVector(Vector vector2) {
	return Vector(this->x - vector2.x, this->y - vector2.y, this->z - vector2.z);
}

Vector Vector::reverseVector() {
	return Vector(this->x * -1, this->y * -1, this->z * -1);
}

Vector Vector::unitVector() {
	return Vector(this->x / getLengthC(), this->y / getLengthC(), this->z / getLengthC());
}

double Vector::scalarMultipleP(Vector vector2) {
	return this->getLengthP() * vector2.getLengthP() * this->angleBetweenVectors(vector2);
}

double Vector::scalarMultipleC(Vector vector2) {
	return (this->x * vector2.x + this->y * vector2.y + this->z * vector2.z);
}

Vector Vector::vectorMultiple(Vector vector2) {
	return Vector(this->y * vector2.z - vector2.y * this->z, (this->x * vector2.z - vector2.x * this->z) * -1, this->x * vector2.y - vector2.x * this->y);
}

double Vector::mixedMultiple(Vector vector2, Vector vector3) {
	return ((this->x * vector2.y * vector3.z) + (vector2.x * vector3.y * this->z) + (this->y * vector2.z * vector3.x)) - ((this->z * vector2.y * vector3.x) + (vector2.x * this->y * vector3.z) + (vector3.y * vector2.z * this->x));
}

double Vector::angleBetweenVectors(Vector vector2) {
	return (this->scalarMultipleC(vector2))/(this->getLengthC() * vector2.getLengthC());
}

double Vector::distanceBetweenVectors(Vector vector2) {
	return pow((this->x - vector2.x), 2) + pow((this->y - vector2.y), 2) + pow(this->z - vector2.z, 2);
}

bool Vector::isCollinear(Vector vector2) {
	if (this->vectorMultiple(vector2).getLengthC() == 0) {
		return true;
	} 
	return false;
}

bool Vector::isCoplanar(Vector vector2, Vector vector3) {
	if (this->mixedMultiple(vector2, vector3) == 0) {
		return true;
	}
	return false;
}

int Vector::printCoordinates() {
	std::cout << "{" << this->x << "; " << this->y << "; " << this->z << "}";
	return 0;
}