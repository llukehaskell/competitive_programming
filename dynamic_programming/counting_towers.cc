#include <cstdlib>
#include <iostream>
#include <map>

typedef long long ll;

using namespace std;

int main() {
    // setup
    int t, n, count = 0; //tests, height, counter 
    ll p, s, d = 0; //perm, single star, double star
    map<int, ll> tower_log;

    cin >> t;

    // main
    for (int i = 0; i < t; ++i) {
        cin >> n;
        count = 1;
        s = 1; 
        d = 1;
        p = 2;
        if (tower_log.find(n) != tower_log.end()) {
            // print
            cout << tower_log[n] << "\n";
        } else {
            while (count != n) {
                s = (3 * (s) + p) % 1000000007;
                d = (d + p) % 1000000007;
                p = (s + d) % 1000000007;
                count++;
            }
            tower_log.insert(pair<int, ll>(n, p));
            // print
            cout << p << "\n";
        }
    }
}

/*
g++ -o counting_towers.out counting_towers.cc && ./counting_towers.out
*/