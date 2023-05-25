#include <cstdlib>
#include <iostream>
#include <vector>

int main() {
    int a, b, counter = 0;
    std::cin >> a >> b;

    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
        counter++;
    }
    std::cout << counter;
}


/*
g++ -o rectangle_cutting.out rectangle_cutting.cc && ./rectangle_cutting.out
*/