/**
 * [CodeForces 818F] Level Generation
 * https://codeforces.com/problemset/problem/818/F
 *
 * The only trick is how to find out the number of edges. For a given number in
 * the binary search, we calculate the number of edges of the complete graph
 * with that number of vertices. If it is higher than the actual number of
 * vertices, we update our answer with double the number of vertices, since we
 * need at least half of them to be bridges. Otherwise, we sum the number of
 * edges of the complete graph with the number of vertices.
 *
 * The time complexity is O(log n) for each test case.
 **/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int q;
    cin >> q;
    while (q--) {
        long long n;
        cin >> n;

        long long lo = 0;
        long long hi = n;
        long long r = 0;

        while (lo <= hi) {
            long long m = lo + (hi - lo) / 2;
            long long x = n - m;
            long long c = x * (x - 1) / 2;

            if (c > m) {
                r = max(r, m * 2);
                lo = m + 1;
            } else {
                r = max(r, c + m);
                hi = m - 1;
            }
        }

        cout << r << endl;
    }
}
