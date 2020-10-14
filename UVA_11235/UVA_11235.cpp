/**
 * [UVA 11235] - Frequent values
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2176
 *
 * We build a segment tree for the problem using an array of repeated
 * occurrences. This will help determine what is the most common element. The
 * only trick is to change the query bounds to contain only full sequences of
 * repeated numbers, and not just part of it.
 *
 * Time complexity is O(n) for building the tree, O(log n) for every query
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 3;
int seg_tree[3 * N];
int a[N];
int freqs[N];

void build_seg_tree(int node, int start, int end) {
    if (start == end) {
        seg_tree[node] = freqs[start];
        return;
    }

    int n1 = node * 2;
    int n2 = node * 2 + 1;
    int m = start + (end - start) / 2;
    build_seg_tree(n1, start, m);
    build_seg_tree(n2, m + 1, end);

    seg_tree[node] = max(seg_tree[n1], seg_tree[n2]);
}

int get_value(int node, int start, int end, int i, int j) {
    if (j < start || i > end) {
        return 0;
    }

    if (i <= start && j >= end) {
        return seg_tree[node];
    }

    int m = start + (end - start) / 2;
    int n1 = node * 2;
    int n2 = node * 2 + 1;
    return max(get_value(n1, start, m, i, j), get_value(n2, m + 1, end, i, j));
}

int main(int argc, char const *argv[]) {
    while (true) {
        int n;
        cin >> n;
        if (!n) break;

        int q;
        cin >> q;

        for (int i = 1; i <= n; i++) cin >> a[i];

        freqs[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (a[i] == a[i - 1])
                freqs[i] = freqs[i - 1] + 1;
            else
                freqs[i] = 1;
        }

        build_seg_tree(1, 1, n);

        for (int k = 0; k < q; k++) {
            int i, j;
            cin >> i >> j;

            if (a[i] == a[j]) {
                cout << j - i + 1 << endl;
            } else {
                int upper = upper_bound(a + i, a + j + 1, a[i]) - a;
                int ans = max(0, upper - i);
                i = upper;
                int lower = lower_bound(a + i, a + j + 1, a[j]) - a;
                ans = max(ans, j - lower + 1);
                j = lower - 1;
                cout << max(ans, get_value(1, 1, n, i, j)) << endl;
            }
        }
    }
    return 0;
}