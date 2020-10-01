/**
 * [CodeForces 1077A] Frog Jumping
 * https://codeforces.com/problemset/problem/1077/A
 *
 * This is more of a mathematical problem. With a simple formula, we can know
 * the frog's position for every K. Therefore, for each test case, we just
 * calculate the value and print it out.
 * The only tricky part is that we need to use long long variables because
 * values can be really large.
 *
 * The time complexity is O(1) for each test case.
 **/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long a, b, k;
        cin >> a >> b >> k;

        long long x;
        if (k % 2 == 0) {
            x = (k / 2) * (a - b);
        } else {
            x = (k / 2) * (a - b) + a;
        }

        cout << x << '\n';
    }
    return 0;
}
