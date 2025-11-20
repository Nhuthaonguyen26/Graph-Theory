#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;     
vector<int> path;         
vector<char> used;        
bool found = false;

void backtrack(int pos) {
    if (found) return; 
    if (pos == n) {

        int last = path.back();
        if (a[last][path[0]] == 1) {
            
            cout << 1 << '\n';
            for (int v : path) cout << v << ' ';
            cout << path[0] << '\n'; 
            found = true;
        }
        return;
    }

    int u = path.back();
    for (int v = 1; v <= n; ++v) {
        if (!used[v] && a[u][v]) {
            used[v] = 1;
            path.push_back(v);
            backtrack(pos + 1);
            if (found) return;
            path.pop_back();
            used[v] = 0;
        }
    }
}

int main() {
   

    if (!(cin >> n)) return 0;
    a.assign(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

  
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    
    used.assign(n+1, 0);
    path.clear();
    path.push_back(1);
    used[1] = 1;

    backtrack(1);

    if (!found) {
        cout << 0 << '\n';
    }

    return 0;
}

