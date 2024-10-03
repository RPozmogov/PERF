// PERF_TASK2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

int findPosition(float x1, float x2, float y1, float y2, float radius) {
    float dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    if (dist > radius) 
        return 2;
    else if (dist < radius)
        return 1;
    else
        return 0;
}

int main(int argc, char* argv[])
{
    float x1, x2, y1, y2, radius;
    std::ifstream in(argv[1]);
    in >> x1 >> y1 >> radius;
    in.close();
    std::ifstream inp(argv[2]);
    int i = 0;
    while ((inp >> x2 >> y2) or (i == 100)) {
        i++;
        std::cout << findPosition(x1, x2, y1, y2, radius) << std::endl;
    }
    inp.close();
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