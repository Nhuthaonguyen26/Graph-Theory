#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("DanhSachCanh.inp");
    ofstream fout("DanhSachCanh.out");

    if (!fin.is_open()) {
        cout << "Khong the mo file input!" << endl;
        return 1;
    }

    int n, m;
    fin >> n >> m;

    vector<int> degree(n + 1, 0); // ?ánh s? t? 1..n

    // ??c danh sách c?nh
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        if (u == v) {
            degree[u] += 2; // c?nh khuyên
        } else {
            degree[u]++;
            degree[v]++;
        }
    }

    // Ghi k?t qu?
    fout << n << endl;
    for (int i = 1; i <= n; i++) {
        fout << degree[i] << endl;
    }

    fin.close();
    fout.close();
    return 0;
}


