/**
 * [SPOJ PPATH] - Prime Path
 * https://www.spoj.com/problems/PPATH/
 *
 * First, we create as many graph nodes as the primes there are up to 9999.
 * Then, we connect every node to the others who can be obtained by changing
 * only one digit. Then we do a simple BFS.
 *
 * Time complexity is O(c^2), where c is the number of primes up to 9999, which
 * is constant.
 **/

#include <bits/stdc++.h>

using namespace std;

bool visited[9999 + 1];
int dist[9999 + 1];

class Node {
   public:
    int num;
    set<Node *> connections;

    Node(int n) { num = n; }

    bool isNeighbour(int val) {
        int moves = 0;
        int tmp = num;

        // cout << "Checking if " << tmp << " is neighbour of " << val << '\n';

        while (tmp > 0) {
            if (tmp % 10 != val % 10) moves++;

            tmp /= 10, val /= 10;
        }

        if (moves == 1) return true;
        return false;
    }
};

unordered_map<int, Node *> m;

void build_graph() {
    // cout << "Primes: ";

    for (int i = 1001; i <= 9999; i += 2) {
        bool is_prime = true;

        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {
            m[i] = new Node(i);
            // cout << i << ", ";
        }
    }

    // cout << '\n';

    for (auto &i : m) {
        for (auto &j : m) {
            if (i.second->isNeighbour(j.first)) {
                i.second->connections.insert(j.second);
                // cout << i.first << " is neighbour of " << j.first << '\n';
            }
        }
    }
}

int bfs(Node *n, int target) {
    if (n->num == target) return 0;

    queue<Node *> q;
    q.push(n);
    visited[n->num] = true;
    dist[n->num] = 0;

    while (q.size() > 0) {
        Node *node = q.front();

        // cout << "Current node: " << node->num << '\n';

        q.pop();
        for (auto &neighbour : node->connections) {
            if (neighbour->num == target) return dist[node->num] + 1;

            if (!visited[neighbour->num]) {
                q.push(neighbour);
                visited[neighbour->num] = true;
                dist[neighbour->num] = dist[node->num] + 1;
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    build_graph();

    while (t--) {
        int a, b;
        cin >> a >> b;

        memset(visited, false, sizeof(visited));
        memset(dist, 0, sizeof(dist));

        cout << bfs(m[a], b) << '\n';
    }

    return 0;
}