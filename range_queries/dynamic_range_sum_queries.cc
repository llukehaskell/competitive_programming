#include <cstdlib>
#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    int n, q, k, a, b = 0; // array size, # of queries, idx to be updated, lower sum range, upper sum range
    ll u = 0; // updated value
    cin >> n >> q;
    ll arr[n * 2]; //segment tree setup (index 0 never used)

    for (int i = n; i < (n * 2); ++i) { // add elements to the right half of the array
        cin >> arr[i];
    }

    for (int i = (n - 1); i > 0; --i) { // add parent elements of the segment tree
        arr[i] = (arr[(2 * i)] + arr[(2 * i) + 1]);
    }

    int sel = 0; // selector for input(1 || 2) aka update array or find value
    for (int i = 0; i < q; ++i) {
        cin >> sel;
        if (sel == 1) { // update array 
            cin >> k >> u;
            k += n - 1;
            arr[k] = u;
            for (k /= 2; k > 0; k /= 2) { // update the seg tree (in O(log(n)) time)
                arr[k] = (arr[(2 * k)] + arr[(2 * k) + 1]);
            }
        } else { // get sum of range
            cin >> a >> b;
            a += n - 1;
            b += n - 1;
            ll sum = 0;
            while (a <= b) {
                if ((a % 2) == 1) {
                    sum += arr[a++ /* use then increment */];
                }
                if ((b % 2) == 0) {
                    sum += arr[b-- /* use then decrement */];
                }
                a /= 2;
                b /= 2; // O(log(n))
            }
            cout << sum << "\n";
        }
    }
}

/*
g++ -o dynamic_range_sum_queries.out dynamic_range_sum_queries.cc && ./dynamic_range_sum_queries.out
*/