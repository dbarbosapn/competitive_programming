/**
 * [SPOJ PERIOD] - Period
 * https://www.spoj.com/problems/PERIOD/
 *
 * Simple KMP with a small trick to find the period of the repeating prefix
 *
 * Time complexity is linear, determined by the KMP algorithm
 **/

#include <bits/stdc++.h>

using namespace std;

#define N 1000000

int p[N + 5];
int n;

void build_p(string str) {
    int p_index = -1;
    p[0] = -1;
    for (int i = 1; i < n; i++) {
        while (p_index > -1 && str[p_index + 1] != str[i]) p_index = p[p_index];

        if (str[p_index + 1] == str[i]) p_index++;
        p[i] = p_index;
    }
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Test case #" << i << '\n';

        cin >> n;
        string str;
        cin >> str;
        build_p(str);

        for (int i = 1; i < n; i++) {
            int p_length = i + 1;
            int period = p_length - p[i] - 1;

            if ((p_length) % period == 0 && p_length != period) {
                cout << p_length << " " << (p_length / period) << '\n';
            }
        }

        cout << '\n';
    }

    return 0;
}