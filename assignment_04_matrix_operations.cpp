// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std; 

const int MAX_SIZE = 10;

// Reads an M x N matrix from the user
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Displays a matrix neatly using setw()
void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// PART A: Transpose a matrix
void transposeMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols,
                      int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

// PART B: Add two matrices of the same size
void addMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                  int rows, int cols, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

// PART C: Multiply matrix A (M x N) by matrix B (N x P)
void multiplyMatrices(int a[MAX_SIZE][MAX_SIZE], int b[MAX_SIZE][MAX_SIZE],
                       int m, int n, int p, int result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int choice;
    cout << "Matrix Operations Menu:\n";
    cout << "1. Transpose a Matrix\n";
    cout << "2. Add Two Matrices\n";
    cout << "3. Multiply Two Matrices\n";
    cout << "Enter choice: ";
    cin >> choice;

    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    if (choice == 1) {
        int rows, cols;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(a, rows, cols);
        cout << "\nOriginal Matrix:\n";
        displayMatrix(a, rows, cols);

        transposeMatrix(a, rows, cols, result);
        cout << "\nTransposed Matrix:\n";
        displayMatrix(result, cols, rows);
    }
    else if (choice == 2) {
        int rows, cols;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        cout << "\nEnter Matrix A:\n";
        readMatrix(a, rows, cols);
        cout << "\nEnter Matrix B:\n";
        readMatrix(b, rows, cols);

        addMatrices(a, b, rows, cols, result);

        cout << "\nMatrix A:\n";
        displayMatrix(a, rows, cols);
        cout << "\nMatrix B:\n";
        displayMatrix(b, rows, cols);
        cout << "\nSum (A + B):\n";
        displayMatrix(result, rows, cols);
    }
    else if (choice == 3) {
        int m, n, n2, p;
        cout << "Enter rows of Matrix A (M): ";
        cin >> m;
        cout << "Enter columns of Matrix A (N): ";
        cin >> n;
        cout << "Enter rows of Matrix B (must equal N): ";
        cin >> n2;

        if (n2 != n) {
            cout << "Error: Columns of A must equal rows of B for multiplication.\n";
            return 0;
        }

        cout << "Enter columns of Matrix B (P): ";
        cin >> p;

        cout << "\nEnter Matrix A:\n";
        readMatrix(a, m, n);
        cout << "\nEnter Matrix B:\n";
        readMatrix(b, n, p);

        multiplyMatrices(a, b, m, n, p, result);

        cout << "\nMatrix A:\n";
        displayMatrix(a, m, n);
        cout << "\nMatrix B:\n";
        displayMatrix(b, n, p);
        cout << "\nProduct (A x B):\n";
        displayMatrix(result, m, p);
    }
    else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
