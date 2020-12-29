/**
 * [SPOJ CSTREET] - Cobbled streets
 * https://www.spoj.com/problems/CSTREET/en/
 *
 * Very simple Prim's algorithm implementation. Classic problem for MSTs.
 *
 * Time complexity is O(n^2) for the number of nodes
 **/

#include <bits/stdc++.h>

using namespace std;

#define N 1000
#define M 300000

int p, n, m;
int graph[N][N];

int min_key(int key[], bool mst[]) {
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < n; v++) {
        if (!mst[v] && key[v] < min) min = key[v], min_index = v;
    }

    return min_index;
}

void prim() {
    int parent[n];
    int key[n];
    bool mst[n];

    fill(key, key + n, INT_MAX);
    fill(mst, mst + n, false);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = min_key(key, mst);

        mst[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mst[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int cost = 0;

    for (int v = 1; v < n; v++) {
        cost += graph[v][parent[v]];
    }

    cost *= p;

    cout << cost << '\n';
}

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> p >> n >> m;

        memset(graph, 0, sizeof(graph));

        int a, b, c;

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> c;
            graph[a - 1][b - 1] = c;
            graph[b - 1][a - 1] = c;
        }

        prim();
    }

    return 0;
}