/**
 * [CodeForces 126B] - Passwords
 * https://codeforces.com/problemset/problem/126/B
 *
 * Simple KMP with small trick
 **/

#include <bits/stdc++.h>

using namespace std;

string str;
int len;
int lps[1000005];
int has_lps[1000005];

void build_lps() {
    int i = 1;
    int j = 0;

    while (i < len) {
        if (str[i] == str[j]) {
            j++;
            lps[i] = j;
            i++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                lps[j] = 0;
                i++;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str;
    len = str.length();

    if (len < 3) {
        cout << "Just a legend\n";
        return 0;
    }

    build_lps();

    for (int i = 1; i < len - 1; i++) {
        has_lps[lps[i]] = 1;
    }

    int result = lps[len - 1];

    while (result) {
        if (has_lps[result]) break;
        result = lps[result - 1];
    }

    if (result) {
        string t = str.substr(0, result);

        cout << t << '\n';
    } else {
        cout << "Just a legend\n";
    }

    return 0;
}