#include <iostream>
#include<fstream>
#include<vector>
using namespace std;

int main() {
    ifstream fin("tomau.inp"); 
    ofstream fout("tomau.out");

    int n;
    fin >> n; // số đỉnh

    // Tạo danh sách kề
    vector<vector<int>> g(n + 1);
    int u, v;
    while (fin >> u >> v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> color(n + 1, 0); // màu của mỗi đỉnh
    int maxColor = 0;

    // Tô màu từng đỉnh 
    for (int i = 1; i <= n; i++) {
        // Đánh dấu màu đã dùng bởi các đỉnh kề
        vector<bool> used(n + 1, false);
        for (int j : g[i])
            if (color[j] != 0)
                used[color[j]] = true;

        // Chọn màu nhỏ nhất chưa dùng
        int c = 1;
        while (used[c]) c++;

        color[i] = c;
        maxColor = max(maxColor, c);
    }

    // Ghi kết quả ra file
    fout << maxColor << "\n";
    for (int c = 1; c <= maxColor; c++) {
        for (int i = 1; i <= n; i++)
            if (color[i] == c)
                fout << i << " ";
        fout << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}