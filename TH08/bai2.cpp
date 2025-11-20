#include <iostream>
#include<fstream>
#include<vector>
using namespace std;

int main() {
    ifstream fin("tomaudothi.inp");
    ofstream fout("tomaudothi.out");
    int n, m;
    fin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n + 1, 0);
    int maxColor = 0;

    for (int u = 1; u <= n; ++u) {
        vector<bool> used(n + 1, false);
        for (int v : adj[u])
            if (color[v] != 0)
                used[color[v]] = true;

        for (int c = 1; c <= n; ++c) {
            if (!used[c]) {
                color[u] = c;
                maxColor = max(maxColor, c);
                break;
            }
        }
    }

    fout << maxColor << "\n";
    for (int c = 1; c <= maxColor; ++c) {
        for (int i = 1; i <= n; ++i)
            if (color[i] == c) fout << i << " ";
        fout << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}