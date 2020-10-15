/**
 * [SPOJ RACETIME] - Race Against Time
 * https://www.spoj.com/problems/RACETIME/en/
 *
 * We're using Sqrt Decomposition. Every block, is a vector which holds the
 * actual values but in a sorted order. Then, on every modify call, we find out
 * where in the block it should be put and we swap it and re-sort. On every
 * query, we find out the respective blocks to search for and, if the block is
 * fully inside the range, we just use the fact that it is sorted to get the
 * number of values smaller or equal to K. If the block is not fully inside the
 * range, we just iterate through the indexes that are.
 *
 * Time complexity will be determined by Sqrt Decomposition. O(sqrt(n)) for each
 * query
 **/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector<int> blocks[400];
int a[N], heads[N], tails[N], block_pointer[N];

void update_value(int i, int value) {
    int block = block_pointer[i];

    int index = lower_bound(blocks[block].begin(), blocks[block].end(), a[i]) -
                blocks[block].begin();

    a[i] = value;
    blocks[block][index] = value;

    sort(blocks[block].begin(), blocks[block].end());
}

int find_value(int start, int end, int k) {
    int r = 0;

    for (int i = block_pointer[start]; i <= block_pointer[end]; i++) {
        if (heads[i] >= start && tails[i] <= end) {
            r += upper_bound(blocks[i].begin(), blocks[i].end(), k) -
                 blocks[i].begin();
        } else {
            for (int j = max(start, heads[i]); j <= min(end, tails[i]); j++) {
                if (a[j] <= k) r++;
            }
        }
    }

    return r;
}

void build_blocks(int block_size, int n) {
    int block_num = 1;
    for (int i = 1; i <= n; i += block_size) {
        heads[block_num] = i;

        int j;
        for (j = i; j < i + block_size && j <= n; j++) {
            int val;
            cin >> val;
            a[j] = val;
            block_pointer[j] = block_num;
            blocks[block_num].push_back(val);
        }
        tails[block_num] = j - 1;

        sort(blocks[block_num].begin(), blocks[block_num].end());

        block_num++;
    }
}

int main(int argc, char const *argv[]) {
    int n, m;
    cin >> n >> m;

    int block_size = sqrt(n);

    build_blocks(block_size, n);

    while (m--) {
        char op;
        cin >> op;

        if (op == 'M') {
            int i, val;
            cin >> i >> val;

            update_value(i, val);
        } else {
            int s, e, val;
            cin >> s >> e >> val;

            cout << find_value(s, e, val) << endl;
        }
    }

    return 0;
}
