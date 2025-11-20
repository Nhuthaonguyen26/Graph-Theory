#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("DanhSachKe.inp");
    ofstream fout("DanhSachKe.out");

    if (!fin.is_open()) {
        cout << "Khong the mo file input!" << endl;
        return 1;
    }

    int n;
    fin >> n;
    vector<int> degree(n + 1, 0);

    // ??c danh sách k?
    for (int i = 1; i <= n; i++) {
        int x;
        while (fin >> x && x != -1) {
            degree[i]++; // t?ng b?c c?a i
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

