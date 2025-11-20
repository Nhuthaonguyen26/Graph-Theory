#include <iostream>
#include<fstream>
#include<vector>
using namespace std;

vector<vector<int>> adj;
vector<int> team;
bool ok = true;

void dfs(int u, int c) {
    team[u] = c;
    for (int v : adj[u]) {
        if (team[v] == 0)
            dfs(v, 3 - c); // đổi màu giữa 1 và 2
        else if (team[v] == team[u])
            ok = false;
    }
}

int main() {
    ifstream fin("teams.inp");
    ofstream fout("teams.out");

    int n, m;
    fin >> n >> m;
    adj.assign(n + 1, {});
    team.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (team[i] == 0) dfs(i, 1);
    }

    if (!ok) fout << "impossible\n";
    else {
        for (int i = 1; i <= n; i++)
            fout << team[i] << " ";
        fout << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}