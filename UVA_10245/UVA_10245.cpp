/**
 * [UVA 10245] - The Closest Pair Problem
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1186
 *
 * Straightforward problem: Find the closest two points
 * Google is your friend on this one :)
 * Inspiration on:
 * https://www.geeksforgeeks.org/closest-pair-of-points-using-divide-and-conquer-algorithm/
 *
 * Time complexity is linearithmic
 **/

#include <bits/stdc++.h>

using namespace std;

class Point {
   public:
    double x, y;
};

int compare_x(const void* a, const void* b) {
    double f = ((Point*)a)->x - ((Point*)b)->x;
    if (f < 0) return -1;
    if (f > 0) return 1;
    return 0;
}

int compare_y(const void* a, const void* b) {
    double f = ((Point*)a)->y - ((Point*)b)->y;
    if (f < 0) return -1;
    if (f > 0) return 1;
    return 0;
}

double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double min_dist(Point points[], int n) {
    double min = FLT_MAX;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (dist(points[i], points[j]) < min)
                min = dist(points[i], points[j]);

    return min;
}

double min_line(Point line[], int n, double d) {
    double min = d;
    qsort(line, n, sizeof(Point), compare_y);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n && (line[j].y - line[i].y) < min; j++)
            if (dist(line[i], line[j]) < min) min = dist(line[i], line[j]);

    return min;
}

double solve_rec(Point points[], int n) {
    if (n <= 3) return min_dist(points, n);

    int m = n / 2;
    Point mid = points[m];

    double min_left = solve_rec(points, m);
    double min_right = solve_rec(points + m, n - m);

    double global_min = min(min_left, min_right);

    Point line[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(points[i].x - mid.x) < global_min) line[j] = points[i], j++;

    return min(global_min, min_line(line, j, global_min));
}

double solve(Point points[], int n) {
    qsort(points, n, sizeof(Point), compare_x);

    return solve_rec(points, n);
}

int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n && n) {
        Point points[n];

        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;

            points[i] = {x, y};
        }

        double d = solve(points, n);

        if (d < 10000) {
            cout << fixed << setprecision(4) << d << '\n';
        } else {
            cout << "INFINITY\n";
        }
    }

    return 0;
}