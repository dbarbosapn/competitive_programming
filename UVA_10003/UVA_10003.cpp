/**
 * [UVA 10003] - Cutting Sticks
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=944
 *
 * First, we're building an array that contains the possible cut locations.
 * Then, we will consider that dp[left][right] returns the best cut between left
 * and right. Then, all we need to do, is for every i between left and right, we
 * calculate the cost and update dp[left][right] if it is better.
 *
 * Time complexity is quadratic per test case
 **/

#include <bits/stdc++.h>

using namespace std;

#define N 52

int cut[N], dp[N][N];

void solve(int left, int right) {
    if (dp[left][right] != -1) return;

    if (left + 1 == right) {
        dp[left][right] = 0;
        return;
    }

    int answer = INT_MAX;

    for (int i = left + 1; i < right; i++) {
        solve(left, i);
        solve(i, right);
        answer =
            min(answer, dp[left][i] + dp[i][right] + cut[right] - cut[left]);
    }

    dp[left][right] = answer;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int l, n;
    while (cin >> l && l) {
        cin >> n;

        memset(cut, 0, sizeof(cut));
        memset(dp, -1, sizeof(dp));

        cut[n + 1] = l;
        cut[0] = 0;

        for (int i = 1; i <= n; i++) cin >> cut[i];

        solve(0, n + 1);

        cout << "The minimum cutting is " << dp[0][n + 1] << ".\n";
    }

    return 0;
}