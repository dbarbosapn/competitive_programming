/**
 * [SPOJ ASSIGN] - Assignments
 * https://www.spoj.com/problems/ASSIGN/en/
 *
 * Here, we use an integer's bits to find wether a topic is taken or not. Then,
 * we do simple recursion on those.
 * With help from:
 * https://www.geeksforgeeks.org/bitmasking-and-dynamic-programming-set-1-count-ways-to-assign-unique-cap-to-every-person/
 *
 * Time complexity is quadratic, defined by the knapsack algorithm.
 **/

#include <bits/stdc++.h>

using namespace std;

#define N 20
long long dp[1 << N];

int set_bits(int i) {
    int count = 0;
    while (i) {
        if (i & 1) count++;
        i >>= 1;
    }

    return count;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int topics[n][n];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) cin >> topics[i][j];

        memset(dp, 0, sizeof(dp));

        dp[0] = 1;
        for (int i = 0; i < (1 << n); i++) {
            int taken = set_bits(i);

            for (int j = 0; j < n; j++) {
                if (topics[taken][j] == 0 || (i & (1 << j))) continue;

                dp[i | (1 << j)] = dp[i | (1 << j)] + dp[i];
            }
        }

        cout << dp[(1 << n) - 1] << '\n';
    }
    return 0;
}