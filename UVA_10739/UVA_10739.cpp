/**
 * [UVA 10739] - String to Palindrome
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1680
 *
 * The trick is on the palin function. What we do here, is:
 *  If we've checked these two positions, s and e, already, we return the value
 *      previously calculated.
 *  If the chars are equal, then there are no moves
 *      needed and we move inside to the next chars.
 *  If they are not equal, we choose
 *      the minimum value between removing the char on s, the char on e or
 *      replacing one of them and moving inwards.
 *
 * Time complexity is O(n) for the string length.
 **/

#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001];
string cur_word;

int palin(int s, int e) {
    if (s >= e) return 0;

    if (dp[s][e] != -1) return dp[s][e];

    if (cur_word[s] == cur_word[e]) {
        dp[s][e] = palin(s + 1, e - 1);
        return dp[s][e];
    }

    dp[s][e] =
        min(palin(s + 1, e), min(palin(s + 1, e - 1), palin(s, e - 1))) + 1;

    return dp[s][e];
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        memset(dp, -1, sizeof(dp));
        cin >> cur_word;
        cout << "Case " << i << ": " << palin(0, cur_word.size() - 1) << '\n';
    }
    return 0;
}
