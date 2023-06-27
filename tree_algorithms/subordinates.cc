#include <cstdlib>
#include <iostream>

typedef long long ll;

using namespace std;

struct node {
    int parent = 0;
    int subs = 0; // # of subordinates
};

int main() {
    // setup
    int n = 0; // # of employees
    cin >> n;
    node tree[n + 1]; 

    // main
    int tmp = 0;
    for (int i = 0; i < (n - 1); ++i) {
        cin >> tree[i + 2].parent;
        int j = i + 2;
        while (j != 1) {
            tree[tree[j].parent].subs++; // add 1 to the parent of the new employee since they have a new subordinate
            j = tree[j].parent; // update subindex 'j' 
        }
    }

    //print 
    for (int i = 1; i <= n; ++i) {
        cout << tree[i].subs << " ";
    }
}

/*
g++ -o subordinates.out subordinates.cc && ./subordinates.out
*/