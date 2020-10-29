/**
 * [UVA 531] - Compromise
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=472
 *
 * Very straightforward LCS print problem using strings instead of chars.
 *
 * Time complexity is O(n*m) (n and m being sizes of the texts)
 **/

#include <bits/stdc++.h>

using namespace std;

string lcs(vector<string>& t1, vector<string>& t2) {
    int m = t1.size();
    int n = t2.size();

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (t1[i - 1] == t2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int index = dp[m][n];

    string arr[index];

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (t1[i - 1] == t2[j - 1]) {
            arr[--index] = t1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    string result;
    for (i = 0; i < dp[m][n]; i++) {
        if (i != 0) result += ' ';
        result += arr[i];
    }

    return result;
}

int main(int argc, char const* argv[]) {
    string cur_word;
    while (cin >> cur_word) {
        vector<string> t1;
        vector<string> t2;

        t1.push_back(cur_word);

        cin >> cur_word;
        while (cur_word != "#") {
            t1.push_back(cur_word);
            cin >> cur_word;
        }

        cin >> cur_word;
        while (cur_word != "#") {
            t2.push_back(cur_word);
            cin >> cur_word;
        }

        cout << lcs(t1, t2) << '\n';
    }
    return 0;
}
