/**
 * [UVA 108] - Maximum Sum
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=44
 *
 * We first create a new matrix where each cell contains the sum of all the
 * cells on the original matrix above that one (inclusive). Then, go through all
 * the rows and cols and keep updating the max.
 *
 * The time complexity for this solution will be O(n^3)
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int a[N][N];

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];

    int sums[n + 1][n + 1];
    memset(sums, 0, sizeof(sums));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            sums[j][i] = sums[j - 1][i] + a[j - 1][i - 1];
        }
    }

    int result = INT_MIN;

    for (int top = 1; top <= n; top++) {
        for (int bottom = top; bottom <= n; bottom++) {
            for (int left = 1; left <= n; left++) {
                int sum = 0;
                for (int right = left; right <= n; right++) {
                    sum += sums[bottom][right] - sums[top - 1][right];
                    result = max(result, sum);
                }
            }
        }
    }
    cout << result << endl;

    return 0;
}
