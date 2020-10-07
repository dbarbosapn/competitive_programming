/**
 * [SPOJ TRIGALGE] - Easy Calculation
 * https://www.spoj.com/problems/TRIGALGE/en/
 *
 * To solve this problem, we do a simple binary search with doubles (using the
 * epsilon technique). The only trick to make it faster is to set the 'high'
 * value to the C value, as X can't be bigger than C.
 *
 **/

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

#define eps 1e-9

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;

    while (t > 0) {
        double a, b, c;
        cin >> a >> b >> c;

        double low = 0;
        double high = c;

        double avg = low + (high - low) / 2.0;

        while (high - low >= eps) {
            avg = low + (high - low) / 2.0;

            double r = a * avg + b * (sin(avg));

            if (r >= c) {
                high = avg;
            } else {
                low = avg;
            }
        }

        cout << fixed << setprecision(6) << avg << endl;

        t--;
    }
}
