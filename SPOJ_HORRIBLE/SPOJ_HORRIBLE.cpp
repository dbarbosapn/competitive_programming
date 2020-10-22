/**
 * [SPOJ HORRIBLE] - Horrible Queries
 * https://www.spoj.com/problems/HORRIBLE/en/
 *
 * The way this is solved, looks like magic. I just followed this:
 * https://cp-algorithms.com/data_structures/fenwick.html
 *
 * The time complexity will be O(log n) per query
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
long long tree1[N];
long long tree2[N];

void add(long long *tree, int n, int i, long long val) {
    while (i <= n) {
        tree[i] += val;
        i += i & -i;
    }
}

void range_add(int n, int start, int end, long long val) {
    add(tree1, n, start, val);
    add(tree1, n, end + 1, -val);
    add(tree2, n, start, val * (start - 1));
    add(tree2, n, end + 1, -val * end);
}

long long sum(long long *tree, int i) {
    long long result = 0;
    while (i > 0) {
        result += tree[i];
        i -= i & -i;
    }

    return result;
}

long long prefix_sum(int i) { return sum(tree1, i) * i - sum(tree2, i); }

long long range_sum(int start, int end) {
    return prefix_sum(end) - prefix_sum(start - 1);
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;

        memset(tree1, 0, sizeof(tree1));
        memset(tree2, 0, sizeof(tree2));

        while (c--) {
            int c_type;
            cin >> c_type;

            if (c_type) {
                int p, q;
                cin >> p >> q;

                cout << range_sum(p, q) << '\n';
            } else {
                int p, q, v;
                cin >> p >> q >> v;

                range_add(n, p, q, v);
            }
        }
    }

    return 0;
}
