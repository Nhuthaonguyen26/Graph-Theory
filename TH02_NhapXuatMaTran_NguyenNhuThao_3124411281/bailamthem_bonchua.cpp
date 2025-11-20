#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("BonChua.inp");
    ofstream fout("BonChua.out");

    if (!fin.is_open()) {
        cout << "Khong the mo file input!" << endl;
        return 1;
    }

    int n;
    fin >> n;

    vector<vector<int>> adj(n, vector<int>(n, 0));
    vector<int> inDeg(n, 0), outDeg(n, 0);


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> adj[i][j];
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j]) {
                outDeg[i]++;
                inDeg[j]++;
            }
        }
    }

    
    vector<int> bonChua;
    for (int i = 0; i < n; i++) {
        if (outDeg[i] == 0 && inDeg[i] > 0) {
            bonChua.push_back(i + 1); 
        }
    }

   
    fout << bonChua.size() << endl;
    if (!bonChua.empty()) {
        for (int v : bonChua) fout << v << " ";
        fout << endl;
    }

    fin.close();
    fout.close();
    return 0;
}


