#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("BacVaoBacRa.inp");
    ofstream fout("BacVaoBacRa.out");

    if (!fin.is_open()) {
        cout << "Khong the mo file input!" << endl;
        return 1;
    }

    int n;
    fin >> n;

    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    vector<int> inDeg(n + 1, 0), outDeg(n + 1, 0);


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> adj[i][j];
        }
    }

 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (adj[i][j]) {
                outDeg[i]++;  
                inDeg[j]++;  
            }
        }
    }

    fout << n << endl;
    for (int i = 1; i <= n; i++) {
        fout << inDeg[i] << " " << outDeg[i] << endl;
    }

    fin.close();
    fout.close();
    return 0;
}

