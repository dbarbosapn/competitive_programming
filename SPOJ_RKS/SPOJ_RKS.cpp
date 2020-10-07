/**
 * [SPOJ RKS] - RK Sorting
 * https://www.spoj.com/problems/RKS/en/
 *
 * To solve this, we're saving the first position the numbers appear in one map,
 * and save their frequencies in another. Then, we fill in a set that will order
 * this numbers according to these two factors and the problem statement. Then
 * we print them out one by one as they come sorted from the set.
 *
 * The time complexity is determined by the sorting. O(n*log(n))
 *
 **/

#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

static unordered_map<int, int> freq;
static unordered_map<int, int> order;

struct rk_compare {
    bool operator()(const int &i1, const int &i2) {
        if (freq[i1] > freq[i2]) return true;

        if (freq[i1] == freq[i2] && order[i1] < order[i2]) return true;

        return false;
    }
};

static set<int, rk_compare> s;

int main(int argc, char const *argv[]) {
    int n, c;
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        freq[val] = freq[val] + 1;
        if (!order[val]) {
            order[val] = i + 1;
        }
    }

    for (unordered_map<int, int>::iterator i = freq.begin(); i != freq.end();
         i++) {
        s.insert(i->first);
    }

    for (set<int>::iterator i = s.begin(); i != s.end(); i++) {
        for (int j = 0; j < freq[*i]; j++) {
            cout << *i << ' ';
        }
    }

    cout << endl;
}
