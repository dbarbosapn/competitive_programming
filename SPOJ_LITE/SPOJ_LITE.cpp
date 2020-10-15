/**
 * [SPOJ LITE] - Light Switching
 * https://www.spoj.com/problems/LITE/en/
 *
 * Simple segment tree implementation but with lazy updates. The only tricky
 * part is understanding which is the value to update. So, we do a trick where
 * the new value of a node is the length of the segment minus the node's value.
 * This works because it means that the lights that were ON are now off and
 * vice-versa.
 *
 * Time complexity for queries and updates is O(log n)
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
vector<int> tree(N * 4);
vector<int> lazy(N * 4);

void update_lazy(int node, int start, int end) {
    int l = end - start + 1;
    lazy[node] = lazy[node] % 2 ? 1 : 0;

    if (lazy[node]) tree[node] = l - tree[node];

    // Not leaf
    if (start != end) {
        int n1 = node * 2;
        int n2 = node * 2 + 1;
        lazy[n1] += lazy[node];
        lazy[n2] += lazy[node];
    }

    lazy[node] = 0;
}

void update_value(int node, int start, int end, int i, int j) {
    if (lazy[node]) update_lazy(node, start, end);

    if (start > j || end < i) return;

    if (start >= i && end <= j) {
        lazy[node]++;
        update_lazy(node, start, end);
        return;
    }

    int m = start + (end - start) / 2;
    int n1 = node * 2;
    int n2 = node * 2 + 1;
    update_value(n1, start, m, i, j);
    update_value(n2, m + 1, end, i, j);

    tree[node] = tree[n1] + tree[n2];
}

int get_value(int node, int start, int end, int i, int j) {
    if (lazy[node]) update_lazy(node, start, end);

    if (start > j || end < i) return 0;

    if (start >= i && end <= j) return tree[node];

    int m = start + (end - start) / 2;
    int n1 = node * 2;
    int n2 = node * 2 + 1;
    return get_value(n1, start, m, i, j) + get_value(n2, m + 1, end, i, j);
}

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int op, i, j;
        cin >> op >> i >> j;

        if (op) {
            cout << get_value(1, 1, n, i, j) << endl;
        } else {
            update_value(1, 1, n, i, j);
        }
    }

    return 0;
}
