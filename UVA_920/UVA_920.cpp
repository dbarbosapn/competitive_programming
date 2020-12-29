/**
 * [UVA 920] - Sunny Mountains
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=861
 *
 * After finding out the "magical" expression on line 59, to find the distance
 * of the new line intersected at the next mountain, the problem becomes a lot
 * easier. It's a matter of doing the calculations by hand, before coding :)
 *
 * Time complexity is O(n) for the number of points
 **/

#include <bits/stdc++.h>

using namespace std;

class Point {
   public:
    int x;
    int y;
    Point(int xi, int yi) {
        x = xi;
        y = yi;
    }

    double distance_to(Point *b) {
        return sqrt((double)(x - b->x) * (x - b->x) + (y - b->y) * (y - b->y));
    }
};

bool point_comparator(const Point *a, const Point *b) { return b->x < a->x; }

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<Point *> points;

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;

            points.push_back(new Point(x, y));
        }

        sort(points.begin(), points.end(), point_comparator);

        int cur_max = 0;
        double l = 0;

        for (int i = 1; i < points.size(); i++) {
            Point *p = points[i];
            Point *prev = points[i - 1];

            if (p->y > cur_max) {
                l += p->distance_to(prev) * (p->y - cur_max) / (p->y - prev->y);
                cur_max = p->y;
            }
        }

        cout << setprecision(2) << setiosflags(ios::fixed) << l << '\n';
    }

    return 0;
}