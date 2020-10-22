/**
 * [SPOJ UPDATEIT] - Update the array !
 * https://www.spoj.com/problems/UPDATEIT/en/
 *
 * A trick is done so that the array is updated only once. For every update, we
 * increment the left cell with the value, and decrement on the cell next to the
 *'right'. This way, when traversing, we can obtain the finished array.
 *
 * The time complexity will be O(k*log(k))
 **/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n, u;
        cin >> n >> u;

        long long a[n] = {0};

        while (u--) {
            int l, r, v;
            cin >> l >> r >> v;

            a[l] += v;

            if (r < n - 1) a[r + 1] -= v;
        }

        for (int i = 1; i < n; i++) a[i] += a[i - 1];

        int q;
        cin >> q;

        while (q--) {
            int i;
            cin >> i;
            cout << a[i] << '\n';
        }
    }

    return 0;
}
