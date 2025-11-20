#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    if (!(cin >> n)) return 0;

    vector<vector<pair<int,int>>> adj(n+1); 
    vector<int> deg(n+1, 0);
    int edgeCnt = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x; cin >> x;
       
            if (j > i && x > 0) {
                for (int k = 0; k < x; ++k) {
                    adj[i].push_back({j, edgeCnt});
                    adj[j].push_back({i, edgeCnt});
                    ++edgeCnt;
                    deg[i]++; deg[j]++;
                }
            }
        }
    }

    if (edgeCnt == 0) {
        cout << 1 << '\n';
   
        cout << 1 << '\n';
        return 0;
    }

    vector<int> oddVertices;
    for (int v = 1; v <= n; ++v) if (deg[v] % 2 == 1) oddVertices.push_back(v);
    if (!(oddVertices.size() == 0 || oddVertices.size() == 2)) {
        cout << 0 << '\n';
        return 0;
    }

    
    int start = -1;
    for (int v = 1; v <= n; ++v) if (deg[v] > 0) { start = v; break; }

    vector<char> vis(n+1, 0);
    stack<int> st;
    st.push(start); vis[start] = 1;
    while (!st.empty()) {
        int u = st.top(); st.pop();
        for (auto &pr : adj[u]) {
            int w = pr.first;
            if (!vis[w]) { vis[w] = 1; st.push(w); }
        }
    }
    for (int v = 1; v <= n; ++v) {
        if (deg[v] > 0 && !vis[v]) {
            cout << 0 << '\n';
            return 0;
        }
    }

   
    if (oddVertices.size() == 2) start = oddVertices[0];

    vector<int> it(n+1, 0);           
    vector<char> used(edgeCnt, 0);    
    vector<int> circuit; circuit.reserve(edgeCnt + 1);
    stack<int> st2; st2.push(start);

    while (!st2.empty()) {
        int v = st2.top();
       
        while (it[v] < (int)adj[v].size() && used[adj[v][it[v]].second]) it[v]++;
        if (it[v] == (int)adj[v].size()) {
            
            circuit.push_back(v);
            st2.pop();
        } else {
            auto e = adj[v][it[v]++]; 
            if (!used[e.second]) {
                used[e.second] = 1;
                st2.push(e.first);
            }
        }
    }

   
    if ((int)circuit.size() != edgeCnt + 1) {
        cout << 0 << '\n';
        return 0;
    }

    reverse(circuit.begin(), circuit.end());

    
    cout << 1 << '\n';
    for (int i = 0; i < (int)circuit.size(); ++i) {
        if (i) cout << ' ';
        cout << circuit[i];
    }
    cout << '\n';
    return 0;
}

