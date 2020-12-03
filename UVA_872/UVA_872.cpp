/**
 * [UVA 872] - Ordering
 * https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=813
 *
 * Straightforward topsorting algorithm.
 *
 * https://www.geeksforgeeks.org/topological-sorting/
 *
 * Time complexity is O(V+E) (vertices plus edges)
 **/

#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    char value;
    unordered_set<Node *> neighbours;
    bool visited = false;
    int degree = 0;

    Node(char c) { value = c; }
};

unordered_map<char, Node *> nodes;
vector<char> tmp_result;
set<string> result;

void build_graph() {
    string line;
    getline(cin, line);
    for (int i = 0; i < line.length(); i += 2) {
        char c = line[i];
        nodes[c] = new Node(c);
    }

    getline(cin, line);
    for (int i = 0; i + 2 < line.length(); i += 4) {
        char c1 = line[i];
        char c2 = line[i + 2];
        // cout << "Adding edge: " << c1 << " < " << c2 << '\n';
        nodes[c1]->neighbours.insert(nodes[c2]);
        nodes[c2]->degree++;
    }
}

void top_sorts() {
    bool all_visited = true;

    for (auto &it : nodes) {
        Node *node = it.second;

        if (node->degree == 0 && !(node->visited)) {
            for (auto &n : node->neighbours) n->degree--;
            tmp_result.push_back(node->value);
            node->visited = true;

            top_sorts();

            node->visited = false;
            tmp_result.erase(tmp_result.end() - 1);
            for (auto &n : node->neighbours) n->degree++;

            all_visited = false;
        }
    }

    if (all_visited) {
        string str = "";
        for (int i = 0; i < tmp_result.size(); i++) {
            if (i != 0) str += ' ';
            str += tmp_result[i];
        }
        if (tmp_result.size() > 0) result.insert(str);
    }
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string line;

    int t;
    cin >> t;
    getline(cin, line);
    while (t--) {
        nodes.clear();
        tmp_result.clear();
        result.clear();

        // ignore line
        getline(cin, line);

        build_graph();

        top_sorts();

        for (auto &it : result) {
            cout << it << '\n';
        }

        if (result.empty()) {
            cout << "NO\n";
        }

        if (t != 0) cout << '\n';
    }

    return 0;
}