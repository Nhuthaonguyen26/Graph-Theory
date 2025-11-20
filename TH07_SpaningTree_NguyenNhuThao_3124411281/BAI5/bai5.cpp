#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <fstream>
using namespace std;

struct Edge {
    int u, v, id;
    long long w;
};

struct DSU {
    vector<int> parent, size;
    DSU(int n = 0) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
};

long long kruskal(int n, const vector<Edge>& edges) {
    vector<Edge> sortedEdges = edges;
    sort(sortedEdges.begin(), sortedEdges.end(),
         [](const Edge& a, const Edge& b) { return a.w < b.w; });

    DSU dsu(n);
    long long cost = 0;
    int cnt = 0;
    for (auto& e : sortedEdges) {
        if (dsu.unite(e.u, e.v)) {
            cost += e.w;
            cnt++;
            if (cnt == n - 1) break;
        }
    }
    if (cnt < n - 1) return LLONG_MAX;
    return cost;
}

int main() {
    // Không dùng ios::sync_with_stdio(false); và cin.tie(nullptr);

    ifstream instream("comnet.inp");
    ofstream outstream("comnet.out");

    if (!instream.is_open()) {
        cerr << "Không mở được file comnet.inp\n";
        return 1;
    }
    if (!outstream.is_open()) {
        cerr << "Không mở được file comnet.out\n";
        return 1;
    }

    int T;
    instream >> T;
    while (T--) {
        int n, m, q;
        instream >> n >> m >> q;

        vector<Edge> edges;
        edges.reserve(m);
        for (int i = 0; i < m; i++) {
            Edge e;
            instream >> e.u >> e.v >> e.w;
            e.id = i;
            edges.push_back(e);
        }

        while (q--) {
            int g;
            instream >> g;
            vector<pair<int, long long>> changes;
            for (int i = 0; i < g; i++) {
                int t;
                long long c;
                instream >> t >> c;
                t--; // đổi từ 1-based sang 0-based
                changes.push_back({t, c});
            }

            vector<Edge> newEdges = edges;
            for (auto [t, c] : changes) {
                if (t >= 0 && t < (int)newEdges.size()) {
                    newEdges[t].w = c;
                } else {
                    cerr << "⚠️ Cảnh báo: chỉ số cạnh " << t+1 << " không hợp lệ!\n";
                }
            }

            long long mstCost = kruskal(n, newEdges);

            for (auto [t, c] : changes) {
                vector<Edge> temp;
                temp.reserve(newEdges.size() - 1);
                for (int i = 0; i < m; i++)
                    if (i != t) temp.push_back(newEdges[i]);

                long long costWithout = kruskal(n, temp);

                if (mstCost == LLONG_MAX)
                    outstream << "NO\n";
                else if (costWithout > mstCost)
                    outstream << "NO\n";
                else
                    outstream << "YES\n";
            }
        }
    }

    instream.close();
    outstream.close();
    return 0;
}
