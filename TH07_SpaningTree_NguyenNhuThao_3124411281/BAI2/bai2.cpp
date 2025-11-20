#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> adj[1001];
bool visited[1001];
vector<pair<int, int>> tree_edges;

void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                tree_edges.push_back({u, v});
                q.push(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("CAYKHUNG_BFS.INP");
    ofstream fout("CAYKHUNG_BFS.OUT");

    int n, m;
    fin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Sắp xếp danh sách kề để đảm bảo duyệt theo thứ tự tăng dần
    for (int i = 1; i <= n; ++i)
        sort(adj[i].begin(), adj[i].end());

    bfs(1);

    fout << tree_edges.size() << "\n";
    for (auto e : tree_edges)
        fout << e.first << " " << e.second << "\n";

    fin.close();
    fout.close();
    return 0;
}
