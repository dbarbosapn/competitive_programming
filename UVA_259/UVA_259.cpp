/**
 * [UVA 259] - Software Allocation
 * https://www.spoj.com/problems/CSTREET/en/
 *
 * Tricky implementation of MBP.
 * Inspiration from:
 * https://www.geeksforgeeks.org/maximum-bipartite-matching/
 *
 * Time complexity is O(E+N) for the number of nodes and edges, determined by
 * the DFS on bpm()
 **/

#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    char task;
    unordered_set<int> connections;
    int assigned = -1;
    bool visited = false;

    Node(char t, vector<int> &con) {
        task = t;
        for (auto &i : con) {
            connections.insert(i);
        }
    }
};

string line;
vector<Node *> nodes;
char result[10];

bool bpm(int u) {
    for (auto &n : nodes) {
        if (n->connections.find(u) != n->connections.end() && !n->visited) {
            n->visited = true;

            if (n->assigned < 0 || bpm(n->assigned)) {
                n->assigned = u;
                return true;
            }
        }
    }

    return false;
}

void unvisit_nodes() {
    for (auto &n : nodes) {
        n->visited = false;
    }
}

int solve() {
    int cnt = 0;

    for (int u = 0; u < 10; u++) {
        unvisit_nodes();

        if (bpm(u)) cnt++;
    }

    return cnt;
}

void output_solution() {
    if (solve() == nodes.size()) {
        char result[10];
        memset(result, '_', sizeof(result));

        for (auto &n : nodes) {
            if (n->assigned >= 0) {
                result[n->assigned] = n->task;
            }
        }

        for (int i = 0; i < 10; i++) {
            cout << result[i];
        }
    } else {
        cout << '!';
    }
    cout << '\n';
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (getline(cin, line)) {
        if (line[0] < 'A' || line[0] > 'Z') {
            output_solution();
            nodes.clear();
            continue;
        }

        char t = line[0];
        int n = line[1] - '0';
        vector<int> con;

        int i = 3;
        while (line[i] != ';') {
            con.push_back(line[i] - '0');
            i++;
        }

        for (i = 0; i < n; i++) {
            nodes.push_back(new Node(t, con));
        }
    }

    output_solution();

    return 0;
}