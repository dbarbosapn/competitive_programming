#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int ans = -1;

        int n;
        cin >> n;

        int a[n + 2];
        a[0] = INT_MAX;
        a[n + 1] = INT_MAX;

        int m = -1;
        for (int i = 1; i <= n; i++) {
            int v;
            cin >> v;

            m = max(m, v);
            a[i] = v;
        }

        for (int i = 1; i <= n; i++) {
            if (a[i] == m && (a[i - 1] < a[i] || a[i + 1] < a[i])) {
                ans = i;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}