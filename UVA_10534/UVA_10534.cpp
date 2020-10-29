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
