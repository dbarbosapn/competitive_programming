/**
 * [UVA 10336] - Rank the Languages
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1277
 *
 * Very simple flood fill where we save the number of states for a specific char
 * in a map, for retrieving later and sorting.
 *
 * Time complexity is O(n^2), with n = side of the map
 **/

#include <bits/stdc++.h>

using namespace std;

int h, w;

unordered_map<char, int> m;

bool comparator(const pair<char, int>& p1, const pair<char, int>& p2) {
    if (p1.second == p2.second) {
        return p1.first < p2.first;
    }

    return p1.second > p2.second;
}

void ff(int i, int j, char c, char** matrix, bool** visited) {
    if (visited[i][j] || matrix[i][j] != c || matrix[i][j] == '.') return;
    visited[i][j] = true;

    ff(i - 1, j, c, matrix, visited);
    ff(i, j + 1, c, matrix, visited);
    ff(i + 1, j, c, matrix, visited);
    ff(i, j - 1, c, matrix, visited);
}

void solve() {
    cin >> h >> w;
    m.clear();

    char** matrix;
    matrix = new char*[h + 2];
    for (int i = 0; i <= h + 1; i++) matrix[i] = new char[w + 2];
    bool** visited;
    visited = new bool*[h + 2];
    for (int i = 0; i <= h + 1; i++) visited[i] = new bool[w + 2];

    for (int i = 0; i <= h; i++) {
        matrix[i][0] = '.';
        matrix[i][w + 1] = '.';
        visited[i][0] = false;
        visited[i][w + 1] = false;
    }

    for (int i = 0; i <= w; i++) {
        matrix[0][i] = '.';
        matrix[h + 1][i] = '.';
        visited[0][i] = false;
        visited[h + 1][i] = false;
    }

    for (int i = 1; i <= h; i++) {
        string s;
        cin >> s;

        for (int j = 1; j <= w; j++) {
            visited[i][j] = false;
            matrix[i][j] = s[j - 1];
        }
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (!visited[i][j]) {
                ff(i, j, matrix[i][j], matrix, visited);
                m[matrix[i][j]] = m[matrix[i][j]] + 1;
            }
        }
    }

    vector<pair<char, int>> vec;

    for (auto& it : m) {
        vec.push_back(it);
    }

    sort(vec.begin(), vec.end(), comparator);

    for (auto& it : vec) {
        cout << it.first << ": " << it.second << '\n';
    }
}

int main(int argc, char const* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "World #" << i << '\n';

        solve();
    }
    return 0;
}