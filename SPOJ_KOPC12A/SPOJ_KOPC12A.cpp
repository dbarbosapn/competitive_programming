/**
 * [SPOJ KOPC12A] - Building Construction
 * https://www.spoj.com/problems/KOPC12A/en/
 *
 * In this approach, we're binary searching through all the possible height
 * values and calculate what would be the total cost of choosing that same
 * value. We then stop when we find the local minimum.
 *
 * Time complexity would be O(n*log(n))
 **/

#include <iostream>

using namespace std;

long long calculate_cost(int h[], int c[], int n, int height) {
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        answer += abs(h[i] - height) * c[i];
    }
    return answer;
}

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int h[n];
        int c[n];

        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }

        int lo = 0;
        int hi = 10000;
        long long answer;

        while (lo <= hi) {
            int m = lo + (hi - lo) / 2;

            long long cost1, cost2, cost3;
            cost1 = calculate_cost(h, c, n, m - 1);
            cost2 = calculate_cost(h, c, n, m);
            cost3 = calculate_cost(h, c, n, m + 1);
            answer = cost2;

            if (cost1 > cost2 && cost3 > cost2)
                break;
            else if (cost1 < cost2 && cost2 < cost3)
                hi = m - 1;
            else
                lo = m + 1;
        }

        cout << answer << endl;
    }
}
