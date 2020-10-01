/**
 * [UVA 100] The 3n + 1 problem
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=36
 *
 * The approach here is very straight forward. We keep reading a and b values
 * until there are none and, for each pair, we create new variables to hold
 * their values. This is necessary because at the end we need to print them
 * again. Then, we create a variable that will hold the maximum value of the
 * calculations. For each value between a and b, we calculate the sequence and
 * track the number of iterations, which we want for the result. Then we just
 * print this number.
 * This algorithm could be much more efficient if there was a cache to hold
 * already calculated values. But brute-force works just fine.
 *
 * The time complexity for this solution will be roughly O(n^2).
 **/

#include <iostream>

using namespace std;

int main(int argc, char const* argv[]) {
    int a, b;

    while (cin >> a >> b) {
        int i = a;
        int j = b;

        if (i > j) {
            int tmp = i;
            i = j;
            j = tmp;
        }

        int max = 0;
        for (int k = i; k <= j; k++) {
            int cur = k;
            int cnt = 1;

            while (cur > 1) {
                cnt++;

                cur = (cur % 2 == 0) ? cur / 2 : (cur * 3) + 1;
            }

            if (cnt > max) max = cnt;
        }

        cout << a << ' ' << b << ' ' << max << '\n';
    }

    return 0;
}