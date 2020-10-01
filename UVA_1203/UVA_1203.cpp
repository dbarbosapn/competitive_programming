/**
 * [UVA 1203] Argus
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3644
 *
 * The approach for this relies on creating a custom comparator for a priority
 * queue, according to the problem rules. For every register call, we save its
 * period in a map and insert a pair connecting the query and the period into
 * the priority queue. Then, we keep taking out the closest query (with the
 * smallest period), print it and add the inital period to the pair and put it
 * back into the queue. We do that K times.
 *
 * The time complexity is decided by the priority queue. O(n*log(n));
 **/

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct PairComparator {
    bool operator()(const pair<int, int> p1, pair<int, int> p2) {
        if (p1.second > p2.second) return true;

        if (p1.second == p2.second) return p1.first > p2.first;

        return false;
    }
};

int main(int argc, char const *argv[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, PairComparator> pq;
    unordered_map<int, int> delays;

    while (true) {
        string token;
        cin >> token;

        if (token == "#") {
            break;
        }

        int query, period;
        cin >> query >> period;
        pair<int, int> p(query, period);
        delays[query] = period;
        pq.push(p);
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        pair<int, int> val = pq.top();
        cout << val.first << endl;
        val.second += delays[val.first];
        pq.pop();
        pq.push(val);
    }
    return 0;
}
