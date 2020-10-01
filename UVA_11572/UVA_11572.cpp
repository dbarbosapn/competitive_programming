/**
 * [UVA 11572] Unique Snowflakes
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2619
 *
 * This solution looks pretty straight forward. But there is a catch! We go
 * through every flake but after we find a repeated one, at first sight it might
 * seem it's a good idea to start over from there. But actually, we should start
 * count from the last time we saw that same flake. That allows us to see every
 * single option for a bag. For that, we save the last place we saw a specific
 * flake with a map.
 *
 * Time complexity is O(N) where N is the number of flakes for each test case.
 **/

#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {
    int cases;

    cin >> cases;

    while (cases > 0) {
        long max = 0;

        long num_flakes;
        cin >> num_flakes;

        unordered_map<long, long> map;
        long start = 0;

        for (long i = 1; i <= num_flakes; i++) {
            long flake;
            cin >> flake;

            if (map[flake] > start) {
                start = map[flake];
            }

            map[flake] = i;

            if (i - start > max) max = i - start;
        }

        cout << max << '\n';
        cases--;
    }
    return 0;
}
