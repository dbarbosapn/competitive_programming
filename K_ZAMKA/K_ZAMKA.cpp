/**
 * [Kattis zamka] Zamka
 * https://open.kattis.com/problems/zamka
 *
 * We're using the brute-force approach here, which is enough. Take L and
 * increment it until we find a number which the digit sum of it is X. Same for
 * D but decrementing.
 *
 * Linear time complexity.
 **/

#include <iostream>

using namespace std;

int digitSum(int val) {
    int sum = 0;
    while (val > 0) {
        sum += val % 10;
        val /= 10;
    }
    return sum;
}

int main(int argc, char const *argv[]) {
    int l, d, x;
    cin >> l >> d >> x;

    int n = l;
    while (n <= d && digitSum(n) != x) {
        n++;
    }

    int m = d;
    while (m >= l && digitSum(m) != x) {
        m--;
    }

    cout << n << ' ' << m << '\n';

    return 0;
}