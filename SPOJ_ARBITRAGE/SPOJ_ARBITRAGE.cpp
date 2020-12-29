/**
 * [SPOJ ARBITRAG] - Arbitrage
 * https://www.spoj.com/problems/ARBITRAG/
 *
 * Straightforward Floyd-Warshall implementation adapted to the problem, where
 * in each iteration we check for the arbitrage discrepancy, instead of the sum.
 *
 * Time complexity is O(n^3) for the number of nodes
 **/

#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> nodes;
int n, m;
double v[30][30];

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int c = 1;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            nodes[s] = i;
        }

        memset(v, 0, sizeof(v));

        cin >> m;

        for (int i = 0; i < m; i++) {
            string s1, s2;
            double d;
            cin >> s1 >> d >> s2;

            int a = nodes[s1];
            int b = nodes[s2];

            v[a][b] = d;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (v[j][k] < v[j][i] * v[i][k]) {
                        v[j][k] = v[j][i] * v[i][k];
                    }
                }
            }
        }

        bool f = true;

        for (int i = 0; i < n; i++) {
            if (v[i][i] > 1) f = false;
        }

        cout << "Case " << c << ": ";
        if (f)
            cout << "No" << '\n';
        else
            cout << "Yes" << '\n';

        c++;
    }

    return 0;
}