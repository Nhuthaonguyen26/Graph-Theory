#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> matrixToList(const vector<vector<int>>& mat) {
    int n = mat.size();
    vector<vector<int>> adjList(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j]) adjList[i].push_back(j);
        }
    }
    return adjList;
}

vector<pair<int,int>> matrixToEdges(const vector<vector<int>>& mat) {
    int n = mat.size();
    vector<pair<int,int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) { 
            if (mat[i][j]) edges.push_back({i,j});
        }
    }
    return edges;
}


vector<vector<int>> listToMatrix(const vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int v : adjList[i]) {
            mat[i][v] = 1;
        }
    }
    return mat;
}


vector<pair<int,int>> listToEdges(const vector<vector<int>>& adjList) {
    int n = adjList.size();
    vector<pair<int,int>> edges;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int v : adjList[i]) {
            if (!visited[i][v] && !visited[v][i]) {
                edges.push_back({i, v});
                visited[i][v] = visited[v][i] = true;
            }
        }
    }
    return edges;
}


vector<vector<int>> edgesToMatrix(int n, const vector<pair<int,int>>& edges) {
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (auto e : edges) {
        mat[e.first][e.second] = 1;
        mat[e.second][e.first] = 1; 
    }
    return mat;
}


vector<vector<int>> edgesToList(int n, const vector<pair<int,int>>& edges) {
    vector<vector<int>> adjList(n);
    for (auto e : edges) {
        adjList[e.first].push_back(e.second);
        adjList[e.second].push_back(e.first);
    }
    return adjList;
}


