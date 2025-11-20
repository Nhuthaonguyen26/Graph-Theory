#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y, cost;
    bool operator>(const Node& o) const {
        return cost > o.cost;
    }
};

int main() {
    int N, M, xi, yi, xj, yj;
    cin >> N >> M >> xi >> yi >> xj >> yj;
    vector<vector<int>> A(N+1, vector<int>(M+1));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> A[i][j];

    if (A[xi][yi] == 0 || A[xj][yj] == 0) {
        cout << 0;
        return 0;
    }

    vector<vector<int>> dist(N+1, vector<int>(M+1, INT_MAX));
    vector<vector<pair<int,int>>> trace(N+1, vector<pair<int,int>>(M+1, {-1,-1}));
    int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

    priority_queue<Node, vector<Node>, greater<Node>> pq;
    dist[xi][yi] = 0;
    pq.push({xi, yi, 0});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (cur.cost > dist[cur.x][cur.y]) continue;
        for (int k = 0; k < 4; k++) {
            int nx = cur.x + dx[k], ny = cur.y + dy[k];
            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if (A[nx][ny] == 0) continue;
            int nextCost = cur.cost + ((nx == xj && ny == yj) ? 0 : A[nx][ny]);
            if (nextCost < dist[nx][ny]) {
                dist[nx][ny] = nextCost;
                trace[nx][ny] = {cur.x, cur.y};
                pq.push({nx, ny, nextCost});
            }
        }
    }

    if (dist[xj][yj] == INT_MAX) {
        cout << 0;
        return 0;
    }

    cout << 1 << "\n" << dist[xj][yj] << "\n";
    vector<pair<int,int>> path;
    for (int cx = xj, cy = yj; cx != -1; ) {
        path.push_back({cx, cy});
        auto p = trace[cx][cy];
        cx = p.first; cy = p.second;
    }
    reverse(path.begin(), path.end());
    for (auto &p : path) cout << p.first << " " << p.second << "\n";
}

