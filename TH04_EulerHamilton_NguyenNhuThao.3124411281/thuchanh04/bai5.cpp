#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    vector<vector<int>> a(n+1, vector<int>(n+1, 0));
    vector<int> degree(n+1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            degree[i] += a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 != 0) {
            cout << 0 << "\n";
            return 0;
        }
    }

    int start = -1;
    for (int i = 1; i <= n; i++) if (degree[i] > 0) { start = i; break; }
    if (start == -1) { 
        cout << 1 << "\n" << 1 << "\n";
        return 0;
    }

    vector<bool> vis(n+1, false);
    stack<int> s;
    s.push(start);
    vis[start] = true;
    while (!s.empty()) {
        int u = s.top(); s.pop();
        for (int v = 1; v <= n; v++) {
            if (a[u][v] > 0 && !vis[v]) {
                vis[v] = true;
                s.push(v);
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
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int u = st.top();
        int v;
        for (v = 1; v <= n; v++) if (a[u][v] > 0) break;
        if (v <= n) {
          
            a[u][v]--; a[v][u]--;
            st.push(v);
        } else {
         
            path.push_back(u);
            st.pop();
        }
    }

    cout << 1 << "\n";
    reverse(path.begin(), path.end());
    for (int v : path) cout << v << " ";
    cout << "\n";

    return 0;
}


