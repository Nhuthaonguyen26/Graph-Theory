#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAX = 1000;
int w[MAX][MAX];

int main() {
    ifstream fin("TrungBinhCanh.inp");
    ofstream fout("TrungBinhCanh.out");

    int n;
    fin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fin >> w[i][j];

    int maxLen = 0;
    long long sum = 0;
    int cnt = 0;

 
    int edgeU[MAX*MAX], edgeV[MAX*MAX], k = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (w[i][j] > 0) {
                sum += w[i][j];
                cnt++;

                if (w[i][j] > maxLen) {
                    maxLen = w[i][j];
                    k = 0;
                    edgeU[k] = i + 1;
                    edgeV[k] = j + 1;
                    k++;
                }
                else if (w[i][j] == maxLen) {
                    edgeU[k] = i + 1;
                    edgeV[k] = j + 1;
                    k++;
                }
            }
        }
    }

    fout << k << endl;
    for (int i = 0; i < k; i++) {
        fout << edgeU[i] << " " << edgeV[i] << " ";
    }
    fout << endl;

    double avg = (cnt > 0) ? (double)sum / cnt : 0.0;
    fout << fixed << setprecision(2) << avg << endl;

    return 0;
}




.
