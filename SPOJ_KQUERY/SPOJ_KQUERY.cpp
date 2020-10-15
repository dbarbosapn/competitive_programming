/**
 * [SPOJ KQUERY] - K-query
 * https://www.spoj.com/problems/KQUERY/en/
 *
 * Since the value checking in the segment tree will be different everytime, we
 * save the actual values in a sorted vector, and when we need to get the value,
 * we can just check the number of positions in the vector after we find the
 * first value bigger than K.
 *
 * Time complexity will be roughly O(nlogn)
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 3e4 + 5;

int a[N];
vector<int> tree[N * 3];

int get_value(int node, int k, int start, int end, int i, int j) {
    if (i > end || j < start) {
        return 0;
    }

    if (start >= i && end <= j) {
        vector<int>::iterator k_bound =
            upper_bound(tree[node].begin(), tree[node].end(), k);
        return tree[node].end() - k_bound;
    }

    int m = start + (end - start) / 2;
    int n1 = node * 2;
    int n2 = node * 2 + 1;
    return get_value(n1, k, start, m, i, j) +
           get_value(n2, k, m + 1, end, i, j);
}

void build_tree(int node, int start, int end) {
    tree[node] = vector<int>();

    if (start == end) {
        tree[node].push_back(a[start]);
        return;
    }

    int m = start + (end - start) / 2;
    int n1 = node * 2;
    int n2 = node * 2 + 1;
    build_tree(n1, start, m);
    build_tree(n2, m + 1, end);

    for (int v : tree[n1]) tree[node].push_back(v);
    for (int v : tree[n2]) tree[node].push_back(v);
    sort(tree[node].begin(), tree[node].end());
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    build_tree(1, 1, n);

    int q;
    cin >> q;

    while (q--) {
        int i, j, k;
        cin >> i >> j >> k;

        cout << get_value(1, k, 1, n, i, j) << endl;
    }

    return 0;
}
