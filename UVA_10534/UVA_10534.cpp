/**
 * [UVA 10534] - Wavio Sequence
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1475
 *
 * To solve this problem, we're doing the LIS problem for start to end, and from
 * end to start. Then, to find the longest wavio sequence, we put together the
 * sequences from both the sub-problems.
 *
 * Time complexity is O(n*log(n))
 **/

#include <bits/stdc++.h>

using namespace std;

void lis(vector<int>& a, vector<int>& dp) {
    vector<int> lis(a.size());
    int length = 0;

    for (int i = 0; i < a.size(); i++) {
        int index =
            lower_bound(lis.begin(), lis.begin() + length, a[i]) - lis.begin();
        lis[index] = a[i];

        if (index == length) length++;
        dp[i] = index + 1;
    }
}

int main(int argc, char const* argv[]) {
    int n;
    while (cin >> n) {
        vector<int> a(n);
        vector<int> rev_a(n);
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            a[i] = val;
            rev_a[n - i - 1] = val;
        }

        vector<int> ldp(n);
        vector<int> rdp(n);

        lis(a, ldp);
        lis(rev_a, rdp);

        int result = 0;
        for (int i = 0; i < n; i++) {
            int val = min(ldp[i], rdp[n - i - 1]);
            result = max(result, val * 2 - 1);
        }

        cout << result << '\n';
    }
    return 0;
}
