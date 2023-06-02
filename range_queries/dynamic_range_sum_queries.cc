#include <cstdlib>
#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    // setup
    int n, q, k, u, a, b = 0;
    cin >> n >> q;
    ll arr[n + 1];
    ll orig_arr[n];

    // main
    arr[0] = 0; // fill first slot of array
    for (int i = 1; i <= n; ++i) {
        cin >> orig_arr[i - 1]; // keep an intact version of the original input array to be cahnged by 2ku
        arr[i] = orig_arr[i - 1];
        arr[i] += arr[i - 1]; // add previous entry to current to create an increasing list of numbers
    }

    int tmp = 0;
    for (int i = 0; i < q; ++i) {
        cin >> tmp;
        if (tmp == 2) {
            cin >> a >> b;
            // print (must be like this and not an array of answers bc of big number overflow stuff)
            cout << (arr[b] - arr[a - 1]) << "\n"; // super clever and smart math
        } else /*tmp == 1*/ {
            cin >> k >> u;
            for (int j = k; j <= n; ++j) { // for every idx of arr from k to the end,
                arr[j] -= (orig_arr[k - 1] - u); // update arr to reflect 2ku change
            }
            orig_arr[k - 1] = u; // make 2ku change in original array
        }
    }
}

/*
g++ -o dynamic_range_sum_queries.out dynamic_range_sum_queries.cc && ./dynamic_range_sum_queries.out
*/