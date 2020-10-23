/**
 * [SPOJ MATSUM] - Matrix Summation
 * https://www.spoj.com/problems/MATSUM/
 *
 * Well known 2D fenwick tree implementation. Only trick is that we don't have
 * update queries but SET queries instead. So, we need to keep the original
 * array updated, check the difference and use it on the BIT. The IO warning
 * from SPOJ should be taken seriously. There's a lot of IO in this problem. The
 * first 3 lines of the main method are crucial.
 *
 * The time complexity will be O(log n) for each query.
 **/

#include <bits/stdc++.h>

#define N 1024

using namespace std;

int matrix[N][N];
int bit[N + 1][N + 1];

void update(int n, int x, int y, int val) {
    while (x < n) {
        int y1 = y;
        while (y1 < n) {
            bit[x][y1] += val;

            y1 += (y1 & -y1);
        }

        x += (x & -x);
    }
}

int query(int x, int y) {
    int sum = 0;

    while (x > 0) {
        int y1 = y;

        while (y1 > 0) {
            sum += bit[x][y1];
            y1 -= (y1 & -y1);
        }

        x -= (x & -x);
    }

    return sum;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        memset(matrix, 0, sizeof(matrix));
        memset(bit, 0, sizeof(bit));

        while (true) {
            string cmd;
            cin >> cmd;

            if (cmd == "END") break;

            if (cmd == "SET") {
                int x, y, num;
                cin >> x >> y >> num;

                int diff = num - matrix[x][y];
                matrix[x][y] = num;

                update(n + 1, x + 1, y + 1, diff);
            } else {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;

                int sum = query(x2 + 1, y2 + 1) - query(x1, y2 + 1) -
                          query(x2 + 1, y1) + query(x1, y1);

                cout << sum << '\n';
            }
        }
    }

    return 0;
}
