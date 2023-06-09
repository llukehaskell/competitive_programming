#include <cstdlib>
#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    // setup
    int n, m = 0; // # of hotels, # of groups
    cin >> n >> m;
    ll hotels[n * 2]; // segment tree setup (index 0 never used)

    for (int i = n; i < (n * 2); ++i) { // add elements to the right half of the hotels array
        cin >> hotels[i];
    }

    for (int i = (n - 1); i > 0; --i) { // add parent elements of the segment tree
        hotels[i] = max(hotels[(2 * i)], hotels[(2 * i) + 1]);
    }

    // main
    ll gs = 0; // group size 
    for (int i = 0; i < m; ++i) {
        cin >> gs;
        if (gs > hotels[1]) { // if gs is bigger than the biggest hotel size, they can't fit anywhere
            cout << 0 << "\n";
        }
        
    }
}

/*
g++ -o hotel_queries.out hotel_queries.cc && ./hotel_queries.out
*/