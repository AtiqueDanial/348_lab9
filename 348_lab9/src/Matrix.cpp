#include "../include/Matrix.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

void printMatrix(const Matrix &mat) {
    for (const auto &row : mat) {
        for (int val : row) cout << setw(4) << val;
        cout << endl;
    }
    cout << endl;
}

void loadMatrixFromFile(const string &filename, Matrix &A, Matrix &B) {
    ifstream fin(filename);
    if (!fin) {
        cerr << "Error: cannot open file " << filename << endl;
        exit(1);
    }

    int N;
    fin >> N;
    A.assign(N, vector<int>(N));
    B.assign(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            fin >> A[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            fin >> B[i][j];

    cout << "Matrix A:\n";
    printMatrix(A);
    cout << "Matrix B:\n";
    printMatrix(B);
}

Matrix addMatrix(const Matrix &A, const Matrix &B) {
    int N = A.size();
    Matrix C(N, vector<int>(N));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

Matrix multiplyMatrix(const Matrix &A, const Matrix &B) {
    int N = A.size();
    Matrix C(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

int sumMainDiagonal(const Matrix &A) {
    int sum = 0;
    for (int i = 0; i < A.size(); ++i) sum += A[i][i];
    return sum;
}

int sumSecondaryDiagonal(const Matrix &A) {
    int sum = 0;
    int N = A.size();
    for (int i = 0; i < N; ++i) sum += A[i][N - 1 - i];
    return sum;
}

void swapRows(Matrix &A, int r1, int r2) {
    if (r1 >= 0 && r2 >= 0 && r1 < A.size() && r2 < A.size()) swap(A[r1], A[r2]);
}

void swapCols(Matrix &A, int c1, int c2) {
    if (c1 >= 0 && c2 >= 0 && c1 < A.size() && c2 < A.size())
        for (auto &row : A) swap(row[c1], row[c2]);
}

void updateValue(Matrix &A, int r, int c, int val) {
    if (r >= 0 && c >= 0 && r < A.size() && c < A.size()) A[r][c] = val;
}

