#include <cstdlib>
#include <iostream>
#include <vector>

const int INF = 32000;

int main() {
    int a, b, counter = 0;
    std::cin >> a >> b;

    std::vector<std::vector<int>> min_cut(a + 1, std::vector<int>(b + 1, INF));

    // marking off the diagonal since we know squares don't need to be looked at any longer (cut count of 0)
    for (int i = 0; i <= std::min(a, b); ++i) {
        min_cut[i][i] = 0;
    }

    // for every spot in the matrix
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            
            // for every spot find the minimum previous solution
            for (int k = 1; k < a; ++k) {
                min_cut[i][j] = std::min(
                    min_cut[i][j],
                    min_cut[k][j] + min_cut[i - k][j] + 1);
            }
            for (int k = 1; k < b; ++k) {
                min_cut[i][j] = std::min(
                    min_cut[i][j],
                    min_cut[i][k] + min_cut[i][j - k] + 1);
            }
        }
    }

    // for (int i = 0; i <= a; ++i){
    //     for (int j = 0; j <= b; ++j){
    //         std::cout << min_cut[i][j] << " ";
    //     }
    //     std::cout << '\n';
    // }

    std::cout << min_cut[a][b];
}


/*
g++ -o rectangle_cutting.out rectangle_cutting.cc && ./rectangle_cutting.out
*/