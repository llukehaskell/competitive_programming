#include <cstdlib>
#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    // setup
    int n, q, a, b = 0;
    cin >> n >> q;
    ll arr[n];
    ll res[q];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // main
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        res[i] = 0;
        for (int j = (a - 1); j <= (b - 1); ++j) {
            res[i] += arr[j];
        }
    }

    // print
    for (int i : res) {
        cout << i << "\n";
    }
}

/*
g++ -o static_range_sum_queries.out static_range_sum_queries.cc && ./static_range_sum_queries.out
*/