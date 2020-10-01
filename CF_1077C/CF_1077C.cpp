/**
 * [CodeForces 1077C] Good Array
 * https://codeforces.com/problemset/problem/1077/C
 *
 * First, we're building the array with the values from the input. At the same
 * time, we calculate the sum of the array values and keep track of the times
 * they occur in a map.
 * Then, for each value in the array, we remove its occurence from the map and
 * from the sum, and check two things: If the sum is even, and if there is an
 * occurence of arraySum/2 in the array. This means, that the array is "Good".
 * If it is, we just save it in a set to print later.
 *
 * The time complexity is linear, O(n) since map and set operations are O(1).
 **/

#include <iostream>
#include <unordered_map>
#include <unordered_set>

#define ll long long

using namespace std;

int main(int argc, char const *argv[]) {
    ll n;
    cin >> n;

    ll a[n];
    unordered_map<ll, ll> map;
    ll arraySum = 0;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        arraySum += a[i];
        map[a[i]] = map[a[i]] + 1;
    }

    unordered_set<ll> result;

    for (ll i = 0; i < n; i++) {
        map[a[i]] = map[a[i]] - 1;
        arraySum -= a[i];

        if (arraySum % 2 == 0 && map[arraySum / 2]) {
            result.insert(i);
        }

        map[a[i]] = map[a[i]] + 1;
        arraySum += a[i];
    }

    cout << result.size() << '\n';
    for (ll val : result) {
        cout << (val + 1) << ' ';
    }

    return 0;
}