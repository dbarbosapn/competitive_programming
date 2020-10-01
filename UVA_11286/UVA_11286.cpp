
/**
 * [UVA 11286] Conformity
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2261
 *
 * To solve this, we're going through the all the frosh, and for each one we
 * take the courses chosen, sort them, and build a number which is the
 * combination of all of them. We're using that as a key in a map which saves
 * the occurences of that number, that represents the course combination. Then,
 * we keep track of the number of frosh that chose that combination and print it
 * out.
 *
 * Time complexity is O(N) where N is the number of frosh for each test case,
 * since the following loops occur a constant number of times.
 **/

#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[]) {
    while (true) {
        int frosh;
        cin >> frosh;

        if (!frosh) break;

        int max = 0;
        int count = 0;
        unordered_map<long, int> map;

        while (frosh > 0) {
            int arr[5];
            for (int i = 0; i < 5; i++) {
                cin >> arr[i];
            }
            sort(arr, arr + 5);

            long comb = 0;
            for (int i = 0; i < 5; i++) {
                comb += arr[i];
                if (i != 4) comb *= 1000;
            }

            map[comb] = map[comb] + 1;
            if (map[comb] > max) {
                max = map[comb];
                count = map[comb];
            } else if (map[comb] == max) {
                count += map[comb];
            }

            frosh--;
        }

        cout << count << '\n';
    }

    return 0;
}
