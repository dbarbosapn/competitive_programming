/**
 * [UVA 10078] - The Art Gallery
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1019
 *
 * Classic polygon convexity problem.
 * Inspiration on:
 * https://www.geeksforgeeks.org/check-if-given-polygon-is-a-convex-polygon-or-not/
 *
 * Time complexity is O(n) for the number of points for each polygon
 **/

#include <bits/stdc++.h>

using namespace std;

class Point {
   public:
    int x, y;
};

int cross_product(vector<Point>& points) {
    int x1 = points[1].x - points[0].x;
    int y1 = points[1].y - points[0].y;

    int x2 = points[2].x - points[0].x;
    int y2 = points[2].y - points[0].y;

    return x1 * y2 - y1 * x2;
}

bool is_convex(vector<Point>& points) {
    int n = points.size();

    int prev = 0;
    int curr = 0;

    for (int i = 0; i < n; i++) {
        vector<Point> adj = {points[i], points[(i + 1) % n],
                             points[(i + 2) % n]};

        curr = cross_product(adj);

        if (curr != 0) {
            if (curr * prev < 0)
                return false;
            else
                prev = curr;
        }
    }

    return true;
}

int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n && n) {
        vector<Point> points;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            points.push_back({x, y});
        }

        if (is_convex(points))
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    return 0;
}