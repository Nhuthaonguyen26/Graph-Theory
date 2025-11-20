#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("MaTranKe.inp");
    ofstream fout("MaTranKe.out");

    if (!fin.is_open()) {
        cout << "Khong the mo file input!" << endl;
        return 1;
    }

    int n;
    fin >> n;

    vector<vector<int>> adj(n, vector<int>(n, 0));
    vector<int> degree(n, 0);

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> adj[i][j];
        }
    }

  
    for (int i = 0; i < n; i++) {
        int deg = 0;
        for (int j = 0; j < n; j++) {
            deg += adj[i][j];
        }
        degree[i] = deg;
    }

    // Ghi k?t qu?
    fout << n << endl;
    for (int i = 0; i < n; i++) {
        fout << degree[i] << endl;
    }

    fin.close();
    fout.close();
    return 0;
}

