//#include <stdexcept>
#pragma once
#include <vector>
#include <stdexcept>
template <typename T>
class Array3D
{
public:
	//int size;
	Array3D(int dim1, int dim2, int dim3);
	T& operator()(int i, int j, int k);

	std::vector<T> GetValues0(int i);
	std::vector<T> GetValues1(int j);
	std::vector<T> GetValues2(int k);
	std::vector<T> GetValues01(int i, int j);
	std::vector<T> GetValues02(int i, int k);
	std::vector<T> GetValues12(int j, int k);
	void SetValues0(int i, std::vector<std::vector<T>> arr);
	void SetValues1(int j, std::vector<std::vector<T>> arr);
	void SetValues2(int k, std::vector<std::vector<T>> arr);
	void SetValues01(int i, int j, std::vector<T> arr);
	void SetValues02(int i, int k, std::vector<T> arr);
	void SetValues12(int j, int k, std::vector<T> arr);
	void FillOnes();
	void FillZeros();
	void FillNum(T num);
	int GetSize();
private:
	std::vector<T> arr;
	int dim0, dim1, dim2;
};

