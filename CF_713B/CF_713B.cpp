/**
 * [CodeForces 713B] - Searching Rectangles
 * https://codeforces.com/problemset/problem/713/B
 *
 * In this approach, we try to find a separation line between the rectangles.
 * After we find it (horizontal or vertical), we try to approach the coordinates
 * to find the actual rectangles.
 *
 * The time complexity is dictated by the binary search, done a constant number
 * of times. O(n*log(n))
 **/

#include <iostream>

using namespace std;

static int grid_size;

/**
 * Sends query to get the number of rectangles inside 2 given points
 **/
int num_rectangles(int x1, int y1, int x2, int y2) {
    cout << '?' << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    fflush(stdout);
    int n;
    cin >> n;
    return n;
}

/**
 * Finds the rectangle
 **/
void find_rectangle(int &x1, int &y1, int &x2, int &y2) {
    int lo, hi;

    // Find x2
    lo = x1 - 1;
    hi = x2;
    while (hi - lo > 1) {
        int m = (lo + hi) >> 1;
        int r = num_rectangles(x1, y1, m, y2);
        if (!r) {
            lo = m;
        } else {
            hi = m;
        }
    }
    x2 = hi;

    // Find x1
    lo = x1;
    hi = x2 + 1;
    while (hi - lo > 1) {
        int m = (lo + hi) >> 1;
        int r = num_rectangles(m, y1, x2, y2);

        if (!r) {
            hi = m;
        } else {
            lo = m;
        }
    }
    x1 = lo;

    // Find y2
    lo = y1 - 1;
    hi = y2;
    while (hi - lo > 1) {
        int m = (lo + hi) >> 1;
        int r = num_rectangles(x1, y1, x2, m);

        if (!r) {
            lo = m;
        } else {
            hi = m;
        }
    }
    y2 = hi;

    // Find y1
    lo = y1;
    hi = y2 + 1;
    while (hi - lo > 1) {
        int m = (lo + hi) >> 1;
        int r = num_rectangles(x1, m, x2, y2);

        if (!r) {
            hi = m;
        } else {
            lo = m;
        }
    }
    y1 = lo;
}

int main(int argc, char const *argv[]) {
    cin >> grid_size;

    int lo, hi;

    // Find separation line (try to find vertically)
    lo = 0;
    hi = grid_size;
    while (hi - lo > 1) {
        int m = (lo + hi) >> 1;
        int r = num_rectangles(1, 1, grid_size, m);

        if (!r) {
            lo = m;
        } else {
            hi = m;
        }
    }

    if (hi < grid_size && num_rectangles(1, hi + 1, grid_size, grid_size)) {
        int x1 = 1;
        int y1 = 1;
        int x2 = grid_size;
        int y2 = hi;  // separation
        find_rectangle(x1, y1, x2, y2);

        int x3 = 1;
        int y3 = hi + 1;  // separation
        int x4 = grid_size;
        int y4 = grid_size;
        find_rectangle(x3, y3, x4, y4);

        printf("! %d %d %d %d %d %d %d %d", x1, y1, x2, y2, x3, y3, x4, y4);
    } else {
        // Find separation line (horizontally)
        lo = 0;
        hi = grid_size;
        while (hi - lo > 1) {
            int m = (lo + hi) >> 1;
            int r = num_rectangles(1, 1, m, grid_size);
            if (!r) {
                lo = m;
            } else {
                hi = m;
            }
        }

        int x1 = 1;
        int y1 = 1;
        int x2 = hi;  // separation
        int y2 = grid_size;
        find_rectangle(x1, y1, x2, y2);

        int x3 = hi + 1;  // separation
        int y3 = 1;
        int x4 = grid_size;
        int y4 = grid_size;
        find_rectangle(x3, y3, x4, y4);

        printf("! %d %d %d %d %d %d %d %d", x1, y1, x2, y2, x3, y3, x4, y4);
    }
}
