/**
 * [UVA 10819] - Trouble of 13-Dots
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1760
 *
 * Straight forward 0-1 Knapsack problem. The tricky part is the 200$ credit. A
 * few conditions on the knapsack method solve it. Basically, if we're outside
 * the range to buy that item, even with credit, we return a really small value
 * that will make sure the item is not chosen.
 *
 * Time complexity is quadratic, defined by the knapsack algorithm.
 **/

#include <bits/stdc++.h>

using namespace std;

#define N 100
#define P 4000
#define M 10000

int n, m;
int cost[N];
int value[N];
int dp[N][M + (M / 2000) * 200];

int knapsack(int i, int c) {
    if ((c > m && m < 1800) || (c > m + 200)) return -P;

    if (i == n) {
        if (c > m && c <= 2000) return -P;
        return 0;
    }

    if (dp[i][c] != -1) return dp[i][c];

    dp[i][c] = max(value[i] + knapsack(i + 1, c + cost[i]), knapsack(i + 1, c));
    return dp[i][c];
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> m >> n) {
        for (int i = 0; i < n; i++) cin >> cost[i] >> value[i];
        memset(dp, -1, sizeof(dp));

        cout << knapsack(0, 0) << '\n';
    }
    return 0;
}
