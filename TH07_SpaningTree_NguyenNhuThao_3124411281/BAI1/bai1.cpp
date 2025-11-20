#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

vector<int> adj[1001];
bool visited[1001];
vector<pair<int, int>> tree_edges;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            tree_edges.push_back(make_pair(u, v));
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("CAYKHUNG.INP");
    ofstream fout("CAYKHUNG.OUT");

    int n, m;
    fin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
        sort(adj[i].begin(), adj[i].end());

    dfs(1);

    for (size_t i = 0; i < tree_edges.size(); ++i)
        fout << tree_edges[i].first << " " << tree_edges[i].second << "\n";

    fin.close();
    fout.close();
    return 0;
}
