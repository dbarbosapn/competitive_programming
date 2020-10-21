/**
 * [SPOJ MSE06H] - Japan
 * https://www.spoj.com/problems/MSE06H/en/
 *
 * Simple implementation with fenwick tree. The trick is that, every time we
 * check for crossings, we update the tree. We basically add one crossing for
 * every city above it on the west side.
 *
 * The time complexity will be O(k*log(k))
 **/

#include <bits/stdc++.h>

const int N = 1e3 + 10;
const int K = 1e6 + 10;

using namespace std;

long long read(int i, int *bit) {
    long long sum = 0;

    while (i > 0) {
        sum += bit[i];
        i -= (i & -i);
    }

    return sum;
}

void update(int from, int to, int val, int *bit) {
    while (from <= to) {
        bit[from] += val;
        from += (from & -from);
    }
}

bool comparator(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first) {
        return p1.second < p2.second;
    }

    return p1.first < p2.first;
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int bit[N] = {0};
        pair<int, int> highways[K];

        int n, m, k;
        cin >> n >> m >> k;

        for (int j = 0; j < k; j++) {
            int a, b;
            cin >> a >> b;
            highways[j].first = a;
            highways[j].second = b;
        }

        sort(highways, highways + k, comparator);

        long long crossings = 0;

        for (int j = 0; j < k; j++) {
            crossings += read(m, bit) - read(highways[j].second, bit);
            update(highways[j].second, m, 1, bit);
        }

        cout << "Test case " << i << ": " << crossings << '\n';
    }

    return 0;
}