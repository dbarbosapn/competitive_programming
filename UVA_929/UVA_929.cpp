/**
 * [UVA 929] - Number Maze
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=870
 *
 * Straightforward Dijkstra's algorithm implementation, with costs on the nodes.
 *
 * Time complexity is O(n^2) for the number of nodes
 **/

#include <bits/stdc++.h>

using namespace std;

const int adjR[4] = {-1, 0, 1, 0};
const int adjC[4] = {0, -1, 0, 1};

class Node {
   public:
    int cost;
    int row;
    int col;
    int dist = INT_MAX;
    bool visited = false;

    Node(int c) { cost = c; }

    bool operator<(const Node n2) { return cost > n2.cost; };
};
int n, m;
Node *matrix[999][999];

void build_graph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cost;
            cin >> cost;

            Node *node = new Node(cost);
            node->row = i;
            node->col = j;
            matrix[i][j] = node;
        }
    }
}

void dijkstra() {
    priority_queue<Node *, vector<Node *>, greater<Node *>> pq;

    matrix[0][0]->dist = matrix[0][0]->cost;

    pq.push(matrix[0][0]);

    while (!pq.empty()) {
        Node *u = pq.top();
        pq.pop();

        for (int i = 0; i < 4; i++) {
            int r = u->row + adjR[i];
            int c = u->col + adjC[i];

            if (r >= 0 && r < n && c >= 0 && c < m) {
                Node *neighbour = matrix[r][c];
                if (u->dist + neighbour->cost < neighbour->dist) {
                    neighbour->dist = u->dist + neighbour->cost;
                    pq.push(neighbour);
                }
            }
        }
    }

    cout << matrix[n - 1][m - 1]->dist << '\n';
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;

        build_graph();

        dijkstra();
    }

    return 0;
}