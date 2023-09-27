// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "Calc.h"
#include "trapz.h"
#include "Simpson.h"

using namespace std;

double integralFunc(double x) { //функция
    return 3 * x * x + 2 * x;
}

int main()
{
    try {
        setlocale(LC_ALL, "Russian");
        double step = 0.01;
        int countOfPoints = 100;
        double a = 0;
        double b = 2;
        Trapz integralTrapz(countOfPoints, step);
        double resultByTrapz = integralTrapz.calc(integralFunc, a, b);
        cout << "Метод трапеции: " << resultByTrapz << endl;
        Simpson integralSimpson(countOfPoints, step);
        double resultBySimspon = integralSimpson.calc(integralFunc, a, b);
        cout << "Метод Симпсона: " << resultBySimspon << endl;
    }
    catch (const exception&) {
        cerr << "Ошибка: Параметры введены неверно" << endl;// Вывод сообщения об ошибке на экран
        return 1;
    }
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
