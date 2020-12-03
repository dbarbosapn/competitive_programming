#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int inc = 0;
        int r = 0;
        bool should_inc = false;

        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;

            if (v) {
                if (should_inc) r += inc;
                should_inc = true;
                inc = 0;
            } else {
                inc++;
            }
        }

        cout << r << '\n';
    }

    return 0;
}