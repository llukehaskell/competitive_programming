#include <cstdlib>
#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    // setup
    int n, q = 0; // size of forest, number of queries
    cin >> n >> q;

    int forest[n][n]; // 1 = tree, 0 = empty
    string row; // tmp 
    for (int i = 0; i < n; ++i) {
        cin >> row;
        for (int j = 0; j < n; ++j) {
            switch (row[j]) {
            case '.':
                forest[i][j] = 0;
                break;
            case '*':
                forest[i][j] = 1;
                break;
            default:
                std::cout << "invalid forest input\n";
                exit(0);
            }
        }
    }

    // main - 2d prefix sum (can be done during input but this works)
    
    // filling out first row & column
    for (int i = 1; i < n; ++i) {
        forest[0][i] = forest[0][i - 1] + forest[0][i];
    }
    for (int j = 1; j < n; ++j) {
        forest[j][0] = forest[j - 1][0] + forest[j][0];
    }

    // calculate the rest
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            forest[i][j] =
              forest[i - 1][j] //top rectangle
            + forest[i][j - 1] //plus left rectangle
            - forest[i - 1][j - 1] //minus overlapping space
            + forest[i][j]; //plus current cell
        }
    }

    int y1, x1, y2, x2 = 0; // query coords (in order)
    for (int i = 0; i < q; ++i) {
        cin >> y1 >> x1 >> y2 >> x2;
        y1 -= 1;
        x1 -= 1;
        y2 -= 1;
        x2 -= 1; //@cses we hate yo 1-indexed arrays bruh

        // print
        if (y1 == 0 && x1 == 0) { //if rectangle starts at the origin
            cout << forest[y2][x2] << "\n";
        }
        else if (y1 == 0) { //if rectangle is up against the top 
            cout << forest[y2][x2] - forest[y2][x1 - 1] << "\n";
        }
        else if (x1 == 0) { //if rectangle is up against the left
            cout << forest[y2][x2] - forest[y1 - 1][x2] << "\n";
        }
        else {
            cout << 
            forest[y2][x2] //rectangle from (0,0) to (y2, x2)
            - forest[y1 - 1][x2] //minus top rectangle starting at (0,0) 
            - forest[y2][x1 - 1] //minus left rectangle starting at (0,0)
            + forest[y1 - 1][x1 - 1] //plus catty cornered rectangle that was just subtracted twice 
            << "\n";
        }
    }
}

/*
g++ -o forest_queries.out forest_queries.cc && ./forest_queries.out
*/