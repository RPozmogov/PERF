// PERF_TASK1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    if(argc > 3){
        std::cout << "Введено слишком много параметров\n";
        return 0;
    }
    int n = std::stoi(argv[1]);
    if (n < 1) {
        std::cout << "n не может быть меньше 1\n";
        return 0;
    }
    int m = std::stoi(argv[2]);
    if (m < 1) {
        std::cout << "m не может быть меньше 1\n";
        return 0;
    }
    std::vector<int> v;
    for (int i = 0; i <= n - 1; i++) {
        v.push_back(i + 1);
    }
    int tmp = 0;
    int i = 0;
    int j = m;
    std::string resp /*= std::to_string(pivot)*/;
    int pivot = v[0];
    while (tmp != v[0]) {
        j--;
        if (j == 0) {
            tmp = v[i];
            resp += std::to_string(pivot);
            pivot = tmp;
            j = m - 1;
        }       
        i++;
        if (i == v.size())
            i = 0;
    }
    std::cout << resp << std::endl;
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
