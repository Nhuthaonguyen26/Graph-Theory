#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> dominos;
vector<vector<pair<int,int>>> adj;
vector<int> degree;
vector<bool> used;
vector<int> path;

void euler(int u) {
    for (auto &e : adj[u]) {
        int v = e.first, id = e.second;
        if (!used[id]) {
            used[id] = true;
            euler(v);
            path.push_back(id); 
        }
    }
}

int main() {
    cin >> n;
    dominos.resize(n);
    adj.assign(7, {});     
    degree.assign(7, 0);
    used.assign(n, false);

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        dominos[i] = {x, y};
        adj[x].push_back({y, i});
        adj[y].push_back({x, i});
        degree[x]++; degree[y]++;
    }

    for (int i = 0; i <= 6; i++) {
        if (degree[i] % 2 != 0) {
            cout << 0 << "\n";
            return 0;
        }
    }

    int start = -1;
    for (int i = 0; i <= 6; i++) if (degree[i] > 0) { start = i; break; }
    if (start == -1) { cout << 1 << "\n"; return 0; } 

  
    vector<bool> vis(7, false);
    stack<int> st; st.push(start); vis[start] = true;
    while(!st.empty()) {
        int u = st.top(); st.pop();
        for (auto e : adj[u]) {
            if (!vis[e.first]) {
                vis[e.first] = true;
                st.push(e.first);
            }
        }
    }
    for (int i = 0; i <= 6; i++) {
        if (degree[i] > 0 && !vis[i]) {
            cout << 0 << "\n";
            return 0;
        }
    }

   
    euler(start);
    reverse(path.begin(), path.end());

    cout << 1 << "\n";
    int cur = start;
    for (int id : path) {
        int x = dominos[id].first, y = dominos[id].second;
        if (x == cur) { cout << x << " " << y << "\n"; cur = y; }
        else          { cout << y << " " << x << "\n"; cur = x; }
    }

    return 0;
}


