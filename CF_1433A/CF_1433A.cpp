#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        int result = 0;

        result += ((x % 10) - 1) * 10;

        int inc = 1;
        while (x > 0) {
            result += inc;
            inc++;
            x /= 10;
        }

        cout << result << '\n';
    }

    return 0;
}