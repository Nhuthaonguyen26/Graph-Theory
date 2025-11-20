#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

struct Node {
    int v, w, parent;
    bool operator>(const Node &other) const {
        return w > other.w;
    }
};

vector<pair<int, int>> adj[1001];
bool visited[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("PRIM.INP");
    ofstream fout("PRIM.OUT");

    int n, m;
    fin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        fin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    vector<Edge> mst;
    int total_weight = 0;

    pq.push({1, 0, -1});

    while (!pq.empty() && mst.size() < (size_t)n - 1) {
        Node cur = pq.top();
        pq.pop();

        if (visited[cur.v]) continue;
        visited[cur.v] = true;

        if (cur.parent != -1) {
            mst.push_back({cur.parent, cur.v, cur.w});
            total_weight += cur.w;
        }

        for (auto &next : adj[cur.v]) {
            if (!visited[next.first]) {
                pq.push({next.first, next.second, cur.v});
            }
        }
    }

    fout << mst.size() << " " << total_weight << "\n";
    for (auto &e : mst)
        fout << e.u << " " << e.v << " " << e.w << "\n";

    fin.close();
    fout.close();
    return 0;
}
