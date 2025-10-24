#pragma once
#include <string>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

// Function declarations
void printMatrix(const Matrix &mat);
void loadMatrixFromFile(const std::string &filename, Matrix &A, Matrix &B);
Matrix addMatrix(const Matrix &A, const Matrix &B);
Matrix multiplyMatrix(const Matrix &A, const Matrix &B);
int sumMainDiagonal(const Matrix &A);
int sumSecondaryDiagonal(const Matrix &A);
void swapRows(Matrix &A, int r1, int r2);
void swapCols(Matrix &A, int c1, int c2);
void updateValue(Matrix &A, int r, int c, int val);
