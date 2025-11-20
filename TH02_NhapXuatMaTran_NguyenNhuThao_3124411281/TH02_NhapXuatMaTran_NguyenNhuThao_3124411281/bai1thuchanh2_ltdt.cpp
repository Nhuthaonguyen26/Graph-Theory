#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


void printGraph(int n, const vector<vector<int>>& matrix) {
    cout << "So dinh cua do thi: " << n << endl;
    cout << "Ma tran ke:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
bool isValidGraph(int n, const vector<vector<int>>& matrix) {
    if ((int)matrix.size() != n) return false;
    for (int i = 0; i < n; i++) {
        if ((int)matrix[i].size() != n) return false;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0 && matrix[i][j] != 1) return false;
        }
    }
    return true;
}


bool isDirected(int n, const vector<vector<int>>& matrix) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return true; /
            }
        }
    }
    return false; 
}

int main() {
    string filename = "C:/test.txt"; 
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Khong mo duoc file!" << endl;
        return 1;
    }

    int n;
    file >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> matrix[i][j];
        }
    }
    file.close();


    printGraph(n, matrix);

  
    if (isValidGraph(n, matrix)) {
        cout << "Do thi hop le." << endl;
        if (isDirected(n, matrix)) {
            cout << "Day la do thi co huong." << endl;
        } else {
            cout << "Day la do thi vo huong." << endl;
        }
    } else {
        cout << "Thong tin do thi khong hop le!" << endl;
    }

    return 0;
}

