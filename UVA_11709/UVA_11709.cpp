/**
 * [UVA 11709] - Trust groups
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2756
 *
 * Straightforward Kosaraju's algorithm for strongly connected components.
 *
 * https://www.geeksforgeeks.org/strongly-connected-components/
 *
 * Time complexity is O(V+E) (vertices plus edges)
 **/

#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    string name;
    unordered_set<Node *> neighbours;
    bool visited = false;

    Node(string str) { name = str; }
};

string line;
int p, t;

unordered_map<string, Node *> nodes;
unordered_map<string, Node *> nodes_transpose;

void dfs(Node *node) {
    node->visited = true;

    for (auto &n : node->neighbours) {
        if (!n->visited) dfs(n);
    }
}

void transpose() {
    for (auto &it : nodes) {
        Node *node = it.second;
        nodes_transpose[node->name] = new Node(node->name);
    }

    for (auto &it : nodes) {
        Node *node = it.second;

        for (auto &n : node->neighbours) {
            nodes_transpose[n->name]->neighbours.insert(
                nodes_transpose[node->name]);
        }
    }
}

void fill_order(Node *node, stack<string> &stk) {
    node->visited = true;

    for (auto &n : node->neighbours) {
        if (!n->visited) {
            fill_order(n, stk);
        }
    }

    stk.push(node->name);
}

int num_sccs() {
    stack<string> stk;
    for (auto &it : nodes) {
        Node *n = it.second;
        if (!n->visited) {
            fill_order(n, stk);
        }
    }

    transpose();

    int count = 0;
    while (!stk.empty()) {
        string name = stk.top();
        stk.pop();

        Node *n = nodes_transpose[name];

        if (!n->visited) {
            count++;

            dfs(n);
        }
    }

    return count;
}

void build_graph() {
    for (int i = 0; i < p; i++) {
        getline(cin, line);
        nodes[line] = new Node(line);
    }

    for (int i = 0; i < t; i++) {
        string s1;
        string s2;

        getline(cin, s1);
        getline(cin, s2);

        nodes[s1]->neighbours.insert(nodes[s2]);
    }
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> p >> t && (p || t)) {
        getline(cin, line);

        nodes.clear();
        nodes_transpose.clear();

        build_graph();

        cout << num_sccs() << '\n';
    }

    return 0;
}