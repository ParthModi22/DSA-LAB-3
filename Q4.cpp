#include <iostream>
using namespace std;

const int rowA = 5, colA = 6;
const int rowB = 6, colB = 5;

int A[rowA][colA] = {
        {0 , 0 , 0 , 0 , 9, 0},
        {0 , 8 , 0 , 0 , 0, 0},
        {4 , 0 , 0 , 2 , 0, 0},
        {0 , 0 , 0 , 0 , 0, 5},
        {0 , 0 , 2 , 0 , 0, 0}
};
int B[rowB][colB] = {
        {0 , 0 , 0 , 2 , 0},
        {0 , 5 , 0 , 8 , 0},
        {0 , 0 , 1 , 0 , 4},
        {0 , 2 , 0 , 0 , 0},
        {1 , 0 , 0 , 1 , 0},
        {0 , 0 , 5 , 0 , 0}
};

void multiply(int A[rowA][colA], int B[rowB][colB], int C[rowA][colB]) {
    if (rowB == colA) {
        for (int i = 0; i < rowA; i++) {
            for (int j = 0; j < colB; j++) {
                C[i][j]= 0;
                for (int k = 0; k < colA; k++) {
                    C[i][j]+= A[i][k]*B[k][j];
                }
                
            }
        }
    } 
     else {
        cout << "Multiplication not possible" << endl;
    }
}
void print(int C[rowA][colB]) {
    for(int i = 0; i < rowA; ++i) {
        for(int j = 0; j < colB; ++j) {
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
}
int main() {
    int C[rowA][colB];
    multiply(A, B, C);
    print(C);
}