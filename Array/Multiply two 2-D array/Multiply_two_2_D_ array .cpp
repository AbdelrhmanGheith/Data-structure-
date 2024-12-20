#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

int main() {
    int matrix1[ROWS][COLS] = {
        {3, 2, 3},
        {4, 6, 4},
        {9, 7, 9}
    };

    int matrix2[ROWS][COLS] = {
        {9, 2, 9},
        {4, 5, 4},
        {1, 2, 1}
    };

    int result[ROWS][COLS] = { 0 };

    // Multiply the matrices
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            for (int k = 0; k < COLS; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

 
    cout << "The resultant matrix after multiplication:" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}