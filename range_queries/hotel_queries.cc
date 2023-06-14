#include <cstdlib>
#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    // setup
    int n, m = 0; // # of hotels, # of groups
    cin >> n >> m;

    int treesize = 1; // for finding the closest power of 2 greater than n
    while (true) {
        if (treesize >= n) {
            break;
        }
        treesize *= 2;
    }

    ll hotels[treesize * 2]; // segment tree setup (index 0 never used)

    for (int i = 0; i < (treesize * 2); ++i) { //setting all elements to zero
        hotels[i] = 0;
    }

    for (int i = 0; i < n; ++i) { // add elements to the right half of the hotels array
        cin >> hotels[treesize + i];
    }

    for (int i = (treesize - 1); i > 0; --i) { // add parent elements of the segment tree
        hotels[i] = max(hotels[(2 * i)], hotels[(2 * i) + 1]);
    }

    // main
    ll gs = 0; // group size
    for (int i = 0; i < m; ++i) {
        cin >> gs;
        if (gs > hotels[1]) { // if gs is bigger than the biggest hotel size, they can't fit anywhere
            cout << 0 << "\n";
        } else { 
            int k = 1; // index
            while (k < treesize) { // while we are still traversing the non-leaf nodes
                if (hotels[k * 2] >= gs) { // if left child has space 
                    k = k * 2;
                } else { // else go to right child
                    k = (k * 2) + 1;
                }
            }

            // print
            cout << (k - treesize + 1) << "\n";

            // update tree
            hotels[k] = hotels[k] - gs;
            while (k != 1) {
                k = k / 2;
                hotels[k] = max(hotels[(2 * k)], hotels[(2 * k) + 1]);
            }
        }
    }
}

/*
g++ -o hotel_queries.out hotel_queries.cc && ./hotel_queries.out
*/