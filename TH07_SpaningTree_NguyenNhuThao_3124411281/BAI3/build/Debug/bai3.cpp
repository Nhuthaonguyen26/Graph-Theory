#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

int parent[1001], sz[1001];

int find_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("KRUSKAL.INP");
    ofstream fout("KRUSKAL.OUT");

    int n, m;
    fin >> n >> m;
    vector<Edge> edges(m);

    for (int i = 0; i < m; ++i)
        fin >> edges[i].u >> edges[i].v >> edges[i].w;

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    vector<Edge> mst;
    int total_weight = 0;

    for (auto &e : edges) {
        if (union_sets(e.u, e.v)) {
            mst.push_back(e);
            total_weight += e.w;
        }
    }

    fout << mst.size() << " " << total_weight << "\n";
    for (auto &e : mst)
        fout << e.u << " " << e.v << " " << e.w << "\n";

    fin.close();
    fout.close();
    return 0;
}
