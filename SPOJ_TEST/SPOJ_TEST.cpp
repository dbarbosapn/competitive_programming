/**
 * [SPOJ TEST] Life, the Universe, and Everything
 * https://www.spoj.com/problems/TEST/
 *
 * The Hello World of competitive programming. Print the numbers until we
 * find 42.
 *
 * Time complexity of O(n), where n is the amount of numbers coming before 42.
 **/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int in;

    while (cin >> in) {
        if (in == 42) break;
        cout << in << '\n';
    }

    return 0;
}
