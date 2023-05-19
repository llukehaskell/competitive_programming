#include <cstdlib>
#include <iostream>
#include <vector>

int solve(int num_coins, int desired_sum, int wallet[]);

int main () {
    int num_coins, desired_sum, local_sum, counter = 0;
    std::cin >> num_coins >> desired_sum;

    int wallet[num_coins];
    for (int i = 0; i < num_coins; ++i) {std::cin >> wallet[i];}

    // i think all the coins will be sorted but idk

    for (int i = 0; i < num_coins; ++i) {
        while (local_sum < desired_sum) {
            local_sum += wallet[i]; // get local_sum to >= the desired_sum
        }
        if (local_sum == desired_sum) {
            counter++;
        }
        // UNFINISHED
    }



    // std::cout << solve(num_coins, desired_sum, wallet);
}

int solve(int num_coins, int desired_sum, int wallet[], int local_sum) {
    if (local_sum == desired_sum) {return 1;}
    else {

        return 1 + //solve()
    }
}
    // if (desired_sum == 0) {return 1;}
    // if (desired_sum < 0) {return 0;}
    // if (num_coins <= 0) {return 0;}
    // return solve(num_coins - 1, desired_sum, wallet) + solve(num_coins, desired_sum - wallet[num_coins - 1], wallet);


/* 
g++ -o coin_combinations_I.out coin_combinations_I.cc && ./coin_combinations_I.out
*/