// лаб3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <vector>
#include <iostream>
//#include "Array3D.h"
#include "Array3D.cpp"

//template <typename T>
int main()
{
    
    Array3D<int> arr(2, 2, 2);
    arr(0, 0, 0) = 1;
    arr(0, 0, 1) = 2;
    arr(0, 1, 0) = 3;
    arr(0, 1, 1) = 4;
    arr(1, 0, 0) = 5;
    arr(1, 0, 1) = 6;
    arr(1, 1, 0) = 7;
    arr(1, 1, 1) = 8;

    std::vector<int> slice0 = arr.GetValues0(0);
    std::cout << "Slice 0:";
    for (int value : slice0) {
        std::cout << value << std::endl;
    }
    std::cout << std::endl;

    std::vector<int> slice1 = arr.GetValues1(0);
    std::cout << "Slice 1:";
    for (int value : slice1) {
        std::cout << value << std::endl;
    }
    std::cout << std::endl;

    std::vector<int> slice2 = arr.GetValues2(0);
    std::cout << "Slice 2:";
    for (int value : slice2) {
        std::cout << value << std::endl;
    }
    std::cout << std::endl;

    std::vector<int> slice01 = arr.GetValues01(0, 0);
    std::cout << "Slice 01:";
    for (int value : slice01) {
        std::cout << value << std::endl;
    }
    std::cout << std::endl;

    std::vector<int> slice02 = arr.GetValues02(0,0);
    std::cout << "Slice 02:";
    for (int value : slice02) {
        std::cout << value << std::endl;
    }
    std::cout << std::endl;

    std::vector<int> slice12 = arr.GetValues12(0, 0);
    std::cout << "Slice 12:";
    for (int value : slice12) {
        std::cout << value << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;
    
    std::vector<std::vector<int>> inputArr1 = { {10, 11}, {20, 21} };
    arr.SetValues0(0, inputArr1);
    slice0 = arr.GetValues0(0);

    std::cout << "Slice 0:";
    for (int value : slice0) {
        std::cout << value << std::endl;
    }
    
    std::cout << std::endl;

    std::vector<int> inputArr2 = {30, 31};
    arr.SetValues12(0, 0, inputArr2);
    slice12 = arr.GetValues12(0,0);
    slice12 = arr.GetValues12(0, 0);
    std::cout << "Slice 12:";
    for (int value : slice12) {
        std::cout << value << std::endl;
    }

    std::cout << std::endl;

    Array3D<int> arr1(2, 2, 2);
    arr1.FillNum(5);
    std::vector<int> slice0Ofarr1 = arr1.GetValues0(0);
    std::cout << "Slice 0:";
    for (int value : slice0Ofarr1) {
        std::cout << value << std::endl;
    }
    std::cout << std::endl;

    std::vector<int> slice1Ofarr1 = arr1.GetValues1(0);
    std::cout << "Slice 1:";
    for (int value : slice0Ofarr1) {
        std::cout << value << std::endl;
    }
    std::cout << std::endl;

    std::vector<int> slice2Ofarr1 = arr1.GetValues2(0);
    std::cout << "Slice 2:";
    for (int value : slice2Ofarr1) {
        std::cout << value << std::endl;
    }
    std::cout << std::endl;
    return 0;
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
