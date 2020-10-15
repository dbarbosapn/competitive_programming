/**
 * [UVA 11297] - Census
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2272
 *
 * The trick in this problem is the fact that we're not in a 1D space, but 2D
 * instead. To fix this, we're creating an array of segment trees, one for each
 * row. On each node, we save a pair with the minimum value and maximum value
 * for that segment.
 *
 * Time complexity for building the tree is O(n^2) and for each query
 * O(n*log(n))
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 501;
int c[N][N];
pair<int, int> tree[N][4 * N];

void update_value(int node, int start, int end, int x, int y, int val) {
    if (start == end && start == y) {
        tree[x][node] = {val, val};
        return;
    }

    int m = start + (end - start) / 2;
    int n1 = node * 2;
    int n2 = node * 2 + 1;
    if (y <= m)
        update_value(n1, start, m, x, y, val);
    else
        update_value(n2, m + 1, end, x, y, val);

    int p1 = max(tree[x][n1].first, tree[x][n2].first);
    int p2 = min(tree[x][n1].second, tree[x][n2].second);

    tree[x][node] = {p1, p2};
}

pair<int, int> get_value(int node, int start, int end, int row, int i, int j) {
    if (i > end || j < start) {
        return {INT32_MIN, INT32_MAX};
    }

    if (start >= i && end <= j) {
        return tree[row][node];
    }

    int m = start + (end - start) / 2;
    int n1 = node * 2;
    int n2 = node * 2 + 1;
    pair<int, int> p1 = get_value(n1, start, m, row, i, j);
    pair<int, int> p2 = get_value(n2, m + 1, end, row, i, j);

    return {max(p1.first, p2.first), min(p1.second, p2.second)};
}

void build_tree(int row, int node, int start, int end) {
    if (start == end) {
        tree[row][node] = pair<int, int>(c[row][start], c[row][start]);
        return;
    }

    int m = start + (end - start) / 2;
    int n1 = node * 2;
    int n2 = node * 2 + 1;
    build_tree(row, n1, start, m);
    build_tree(row, n2, m + 1, end);

    int p1 = max(tree[row][n1].first, tree[row][n2].first);
    int p2 = min(tree[row][n1].second, tree[row][n2].second);

    tree[row][node] = pair<int, int>(p1, p2);
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> c[i][j];

    for (int row = 1; row <= n; row++) build_tree(row, 1, 1, n);

    int q;
    cin >> q;
    while (q--) {
        char op;
        cin >> op;

        if (op == 'c') {
            int x, y, v;
            cin >> x >> y >> v;
            update_value(1, 1, n, x, y, v);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            int greatest = INT32_MIN, least = INT32_MAX;

            for (int row = x1; row <= x2; row++) {
                pair<int, int> val = get_value(1, 1, n, row, y1, y2);
                greatest = max(greatest, val.first);
                least = min(least, val.second);
            }

            cout << greatest << ' ' << least << endl;
        }
    }

    return 0;
}
