#include <bits/stdc++.h>
using namespace std;

int main() {
   
    int n, m; 
    cin >> n >> m; 

    vector<vector<pair<int,int>>> adj(n+1); 
    vector<int> degree(n+1, 0);
    vector<bool> used(m, false);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        degree[u]++; degree[v]++;
    }

    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 != 0) {
            cout << 0 << "\n";
            return 0;
        }
    }

    int start = -1;
    for (int i = 1; i <= n; i++) if (degree[i] > 0) { start = i; break; }
    if (start == -1) { /
        cout << 1 << "\n" << 1 << "\n";
        return 0;
    }

   
    vector<bool> vis(n+1, false);
    stack<int> st;
    st.push(start);
    vis[start] = true;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        for (auto [v, id] : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                st.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (degree[i] > 0 && !vis[i]) {
            cout << 0 << "\n";
            return 0;
        }
    }

    
    vector<int> path;
    stack<int> s;
    s.push(start);

    vector<int> it(n+1, 0); 

    while (!s.empty()) {
        int u = s.top();
        while (it[u] < (int)adj[u].size() && used[adj[u][it[u].second]]) it[u]++;
        if (it[u] == (int)adj[u].size()) {
            path.push_back(u);
            s.pop();
        } else {
            auto [v, id] = adj[u][it[u]++];
            if (!used[id]) {
                used[id] = true;
                s.push(v);
            }
        }
    }

    cout << 1 << "\n";
    reverse(path.begin(), path.end());
    for (int v : path) cout << v << " ";
    cout << "\n";

    return 0;
}

