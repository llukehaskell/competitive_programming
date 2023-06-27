#include <cstdlib>
#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

// all employees eventually answer to employee #1 (at least in all the test cases they do)
// there is always at least one employee with no subordinates aka no circles (again at least in all the test cases)

struct employee {
    vector<int> childs;
    int subs = -1; // # of subordinates, -1 for unknown
};

int main() {
    // setup
    int n = 0; // # of employees
    cin >> n;
    employee tree[n + 1]; 

    for (int i = 2; i <= n; ++i) {
        int tmp = 0;
        cin >> tmp;
        tree[tmp].childs.push_back(i); // at this new employee's direct superior, add this employee's employee number to their list of children 
    }

    // main
    // find an employee with no subs
    int x; // index of an employee w no subs
    for (int i = n; i >= 1; --i) {
        if (tree[i].childs.size() == 0) {
            tree[i].subs = 0;
            x = i;
            break;
        }
    }

    // todo


    // print 
    for (int i = 1; i <= n; ++i) {
        cout << tree[i].subs << " ";
    }
}

/*
g++ -o subordinates.out subordinates.cc && ./subordinates.out
*/