/**
 * [UVA 12532] - Interval Product
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3977
 *
 * Simple segment tree implementation where the value of a node is the product
 * of the child nodes. Leaf nodes, if the correspondant value in the array is
 * positive, get 1, negative get -1 and zero gets 0. When updating a value in
 * the array, the correspondant node path is updated too.
 *
 * Time complexity will be roughly O(log n), after building the tree. Which
 * takes O(n).
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 3;
int a[N], tree[N * 3];

void update_value(int node, int start, int end, int index) {
    if (start > index || end < index) {
        return;
    }

    if (start >= index && end <= index) {
        tree[node] = a[index];
        return;
    }

    int m = start + (end - start) / 2;
    int n1 = node * 2;
    int n2 = node * 2 + 1;
    update_value(n1, start, m, index);
    update_value(n2, m + 1, end, index);

    tree[node] = tree[n1] * tree[n2];
}

int get_value(int node, int start, int end, int i, int j) {
    if (i > end || j < start) {
        return 1;
    }

    if (start >= i && end <= j) {
        return tree[node];
    }

    int m = start + (end - start) / 2;
    int n1 = node * 2;
    int n2 = node * 2 + 1;
    return get_value(n1, start, m, i, j) * get_value(n2, m + 1, end, i, j);
}

void build_tree(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
        return;
    }

    int m = start + (end - start) / 2;
    int n1 = node * 2;
    int n2 = node * 2 + 1;
    build_tree(n1, start, m);
    build_tree(n2, m + 1, end);

    tree[node] = tree[n1] * tree[n2];
}

int main(int argc, char const *argv[]) {
    int n, k;
    while (cin >> n >> k) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i]) a[i] /= abs(a[i]);
        }

        build_tree(1, 1, n);

        while (k--) {
            char op;
            int i, j;
            cin >> op >> i >> j;

            if (op == 'C') {
                if (j) j /= abs(j);
                a[i] = j;
                update_value(1, 1, n, i);
            } else {
                int v = get_value(1, 1, n, i, j);
                if (v > 0) {
                    cout << '+';
                } else if (v < 0) {
                    cout << '-';
                } else {
                    cout << 0;
                }
            }
        }

        cout << endl;
    }

    return 0;
}
