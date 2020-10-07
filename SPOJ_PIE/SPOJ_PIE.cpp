/**
 * [SPOJ TRIGALGE] - Easy Calculation
 * https://www.spoj.com/problems/TRIGALGE/en/
 *
 * To solve this problem, we first calculate the volume of each pie and add it
 * to a vector. We also calculate the sum of the volumes because the value will
 * be somewhere between 0 and that sum. After that, we do binary search on those
 * values until we find the highest possible. On each step, we calculate the
 * volume we can get from each pie with pieces of that size.
 *
 * The time complexity will be O(n^2 * log(n)).
 **/

#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

#define eps 1e-5

int main(int argc, char const *argv[]) {
    int t;
    cin >> t;

    while (t > 0) {
        int n, p;
        cin >> n >> p;
        p++;

        vector<double> volumes;

        double low = 0.0;
        double high = 0.0;

        for (int i = 0; i < n; i++) {
            double val;
            cin >> val;
            double volume = val * val * M_PI;
            volumes.push_back(volume);
            high += volume;
        }

        double avg;

        while (high - low >= eps) {
            avg = low + (high - low) / 2.0;

            int total = 0;
            for (int i = 0; i < n; i++) {
                total += (int)(volumes[i] / avg);
            }

            if (total >= p)
                low = avg;
            else
                high = avg;
        }

        cout << fixed << setprecision(4) << avg << endl;

        t--;
    }
}
