#include <cstdlib>
#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    // setup
    int n, q, a, b = 0;
    cin >> n >> q;
    ll arr[n + 1];

    // main
    arr[0] = 0; // fill first slot of array
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        arr[i] += arr[i - 1]; // add previous entry to current to create an increasing list of numbers
    }
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        // print (must be like this and not an array of answers bc of big number overflow stuff)
        cout << (arr[b] - arr[a - 1]) << "\n"; // super clever and smart math
    }
}

/*
g++ -o static_range_sum_queries.out static_range_sum_queries.cc && ./static_range_sum_queries.out
*/