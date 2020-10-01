/**
 * [SPOJ ADDREV] Adding Reversed Numbers
 * https://www.spoj.com/problems/ADDREV/
 *
 * The only tricky part is how to reverse the numbers. After that is sorted out,
 * the solution is pretty straight-forward. Take the A and B, reverse them, add
 * them, reverse again and print.
 *
 * Time complexity is O(n) where N is the number of digits of the biggest number
 * per test case.
 **/

#include <iostream>

using namespace std;

int reverse(int val) {
    int result = 0;
    while (val > 0) {
        result *= 10;
        result += val % 10;
        val /= 10;
    }
    return result;
}

int main(int argc, char const *argv[]) {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int revA = reverse(a);
        int revB = reverse(b);
        cout << reverse(revA + revB) << '\n';
    }

    return 0;
}
