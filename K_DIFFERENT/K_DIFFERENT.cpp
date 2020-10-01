/**
 * [Kattis different] A Different Problem
 * https://open.kattis.com/problems/different
 *
 * Nothing fancy here. Take both numbers, subtract them, print.
 *
 * Time complexity of O(1), for each test case.
 **/

#include <iostream>

#define ll long long

using namespace std;

int main(int argc, char const *argv[]) {
    ll a, b;

    while (cin >> a >> b) {
        if (a > b) {
            ll temp = a;
            a = b;
            b = temp;
        }

        cout << b - a << '\n';
    }

    return 0;
}
