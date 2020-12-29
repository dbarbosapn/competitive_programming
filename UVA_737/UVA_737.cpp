/**
 * [UVA 737] - Gleaming the Cubes
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=678
 *
 * Classic rectangle intersection problem, adapted for 3 dimensions.
 * Inspiration on:
 * https://www.geeksforgeeks.org/total-area-two-overlapping-rectangles/
 *
 * Time complexity is O(n) for the number of cubes
 **/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n && n) {
        int ix1 = INT_MIN, iy1 = INT_MIN, iz1 = INT_MIN;
        int ix2 = INT_MAX, iy2 = INT_MAX, iz2 = INT_MAX;

        int x, y, z, l;

        for (int i = 0; i < n; i++) {
            cin >> x >> y >> z >> l;

            ix1 = max(ix1, x);
            iy1 = max(iy1, y);
            iz1 = max(iz1, z);
            ix2 = min(ix2, x + l);
            iy2 = min(iy2, y + l);
            iz2 = min(iz2, z + l);
        }

        cout << max(0, (ix2 - ix1) * (iy2 - iy1) * (iz2 - iz1)) << '\n';
    }

    return 0;
}