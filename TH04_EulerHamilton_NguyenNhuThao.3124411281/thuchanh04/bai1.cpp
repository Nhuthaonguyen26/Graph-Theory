#include <bits/stdc++.h>
using namespace std;

int n;
int a[105][105];   
bool visited[105];

void dfs(int u) {
    visited[u] = true;
    for (int v = 1; v <= n; v++) {
        if (a[u][v] > 0 && !visited[v]) {
            dfs(v);
        }
    }
}

void euler(int u, vector<int> &path) {
    for (int v = 1; v <= n; v++) {
        while (a[u][v] > 0) {
            a[u][v]--; 
            a[v][u]--;
            euler(v, path);
        }
    }
    path.push_back(u); 
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    
    for (int i = 1; i <= n; i++) {
        int deg = 0;
        for (int j = 1; j <= n; j++) deg += a[i][j];
        if (deg % 2 != 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    memset(visited, false, sizeof(visited));
    int start = 1;
    dfs(start);
    for (int i = 1; i <= n; i++) {
        int deg = 0;
        for (int j = 1; j <= n; j++) deg += a[i][j];
        if (deg > 0 && !visited[i]) { 
            cout << 0 << endl;
            return 0;
        }
    }

   
    vector<int> path;
    euler(start, path);

    cout << 1 << endl;
    for (int i = path.size()-1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}

