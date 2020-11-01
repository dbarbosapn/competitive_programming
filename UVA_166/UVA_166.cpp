/**
 * [UVA 166] - Making Change
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=102
 *
 * First, we build an array that contains, for each price, the minimum of coins,
 * if unlimited, needed for that price. Then, using DFS to decide if we should
 * or not take a certain coin.
 *
 * The time complexity for this solution will be O(n^3)
 **/

#include <bits/stdc++.h>

using namespace std;

const int coins[] = {5, 10, 20, 50, 100, 200};

int c[6];
int dp_min[1005];

void setup_min() {
    for (int i = 0; i < 1005; i++) dp_min[i] = INT_MAX;

    dp_min[0] = 0;

    for (int i = 0; i < 6; i++)
        for (int j = coins[i]; j < 1005; j++)
            dp_min[j] = min(dp_min[j], dp_min[j - coins[i]] + 1);
}

bool read_coins() {
    bool r = false;
    for (int i = 0; i < 6; i++) {
        cin >> c[i];
        r = r || c[i];
    }
    return r;
}

int change(int a, int coin) {
    if (a < -500 || a > 500) return INT_MAX;

    if (a <= 0 && coin < 0) return dp_min[-a];

    if (coin < 0) return INT_MAX;

    if (!c[coin]) return change(a, coin - 1);

    c[coin]--;
    int take_coin = change(a - coins[coin], coin);

    c[coin]++;
    int not_take_coin = change(a, coin - 1);

    return min(take_coin + 1, not_take_coin);
}

int main(int argc, char const *argv[]) {
    setup_min();

    while (read_coins()) {
        int a, b;
        scanf("%d.%d", &a, &b);
        int val = a * 100 + b;
        printf("%3d\n", change(val, 5));
    }

    return 0;
}
