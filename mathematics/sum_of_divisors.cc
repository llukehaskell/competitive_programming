#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>

typedef long long ll;

using namespace std;

ll divisor_of(ll x);

int main() {
    ll n = 0;
    cin >> n; // number to be divided up ↑

    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += divisor_of(i);
        sum = sum % 1000000007;
    }

    cout << sum << "\n";
}

ll divisor_of(ll x) {
    //1,2,3 dont work with the below algorithm
    if (x < 4) {
        switch (x)
        {
        case 3:
            return 4;
            break;
        case 2:
            return 3;
            break;
        case 1:
            return 1;
            break;        
        default:
            break;
        }
    }

    // 1 & n will always be divisors
    vector<ll> divisors(1, 1);
    divisors.push_back(x);

    ll sq = sqrt(x); // upper limit for loop

    // find all divisors from 2 to sq-1
    for (int i = 2; i < sq; ++i) {
        if (x % i == 0) {
            divisors.push_back(i);
            divisors.push_back(x / i);
        }
    }

    // determine if 'sq' is also a divisor
    if (sq * sq == x) {divisors.push_back(sq);}
    else if (x % sq == 0) {
        divisors.push_back(sq);
        divisors.push_back(x / sq);
    }

    // find sum of divisors and print
    ll sum = 0;
    for (int i = 0; i < divisors.size(); ++i) {
        sum += divisors[i];
        sum = sum % 1000000007;
        // cout << sum << "\n";
        // cout << divisors[i] << "\n\n";
    }

    return sum;
}

/*
g++ -o sum_of_divisors.out sum_of_divisors.cc && ./sum_of_divisors.out
*/