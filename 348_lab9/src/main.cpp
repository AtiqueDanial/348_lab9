#include <iostream>
#include "../include/Matrix.hpp"

using namespace std;

int main() {
    Matrix A, B;
    loadMatrixFromFile("data/matrix_input.txt", A, B);

    cout << "A + B:\n";
    printMatrix(addMatrix(A, B));

    cout << "A * B:\n";
    printMatrix(multiplyMatrix(A, B));

    cout << "Sum of main diagonal of A: " << sumMainDiagonal(A) << endl;
    cout << "Sum of secondary diagonal of A: " << sumSecondaryDiagonal(A) << endl;

    cout << "\nSwapping rows 0 and 3 in A:\n";
    swapRows(A, 0, 3);
    printMatrix(A);

    cout << "Swapping columns 0 and 3 in B:\n";
    swapCols(B, 0, 3);
    printMatrix(B);

    cout << "Updating A[1][1] = 99:\n";
    updateValue(A, 1, 1, 99);
    printMatrix(A);

    return 0;
}
