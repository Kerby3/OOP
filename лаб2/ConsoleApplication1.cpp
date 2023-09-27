// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "Geometry.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Vector vector1(2, 1, 3);
    Vector vector2(3, 1, 2);
    Vector vector3(1, 2, 3);
    cout << "Сложение векторов" << endl;
    cout << vector1.sumVector(vector2).printCoordinates() << endl;
    cout << "\nВычитание векторов" << endl;
    cout << vector1.difVector(vector2).printCoordinates() << endl;
    cout << "\nОбратный вектор" << endl;
    cout << vector1.reverseVector().printCoordinates() << endl;
    cout << "\nЕдиничный вектор" << endl;
    cout << vector1.unitVector().printCoordinates() << endl;
    cout << "\nСкалярное произведение" << endl;
    cout << vector1.scalarMultipleC(vector2) << endl;
    cout << "\nВекторное произведение" << endl;
    cout << vector1.vectorMultiple(vector2).printCoordinates() << endl;
    cout << "\nУгол между векторами" << endl;
    cout << vector1.angleBetweenVectors(vector2) << endl;
    cout << "\nРасстояние между векторами" << endl;
    cout << vector1.distanceBetweenVectors(vector2) << endl;
    cout << "\nКоллинеарны ли векторы?" << endl;
    cout << vector1.isCollinear(vector2) << endl;
    cout << "\nСмешанное произведение" << endl;
    cout << vector1.mixedMultiple(vector2, vector3) << endl;
    cout << "\nКокомпланарны ли векторы?" << endl;
    cout << vector1.isCoplanar(vector2, vector3) << endl;

    Point point1(4, 6, 5);
    Point point2(5, 4, 6);
    Point point3(5, 6, 4);
    Point point4(6, 4, 5);
    Vector vector1P(point1, point2);
    Vector vector2P(point3, point4);
    cout << "\nСкалярное произведение по точкам вектора" << endl;
    cout << vector1P.scalarMultipleP(vector2P);
    cout << "\nДлина вектора по точкам" << endl;
    cout << vector1P.getLengthP() << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
