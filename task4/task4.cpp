// PERF_TASK4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <fstream>

int getSize(const std::string path) {
	
	std::ifstream in(path);
	int size = 0;
	int a;
	while (!in.eof() && in >> a)
	{
		size++;
	}
	in.close();
	return size;
}

int* readArrFromFile(const std::string path, int size) {
	std::ifstream in(path);
	int* arr = new int[size];
	//std::string t;
	int t;
	int i = 0;
	while (in >> t) {
		arr[i++] = t;
	}
	in.close();
	return arr;
}

void bubbleSort(int* arr, int size)
{
	int temp;
	while (size--)
	{
		bool swapped = false;

		for (int i = 0; i < size; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}

int main(int argc, char* argv[])
{
	int size = getSize(argv[1]);
	int* arr = readArrFromFile(argv[1], size);
	int medianInd;
	int median;
	bubbleSort(arr, size);
	int turns = 0;
	medianInd = size / 2;
	if (medianInd < 0) {
		std::cout << turns;
		return 0;
	}
	if (size % 2 == 0) {
		medianInd -= 1;
		median = (arr[medianInd] + arr[medianInd + 1]) / 2;
	}
	else
	{
		median = arr[medianInd];
	}
	for (int i = 0; i < size; i++) {
		turns += abs(arr[i] - median);
	}
	std::cout << turns;
	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
