#pragma once
#include <vector>
#include <immintrin.h>  // AVX intrinsics

class SparseMatrix {
public:
    SparseMatrix(int rows, int cols);
    void add(int row, int col, double value);  // Add non-zero entry
    
    // Sparse Matrix-Vector Multiply (SpMV) - Optimized
    void multiply(const double* x, double* y) const;

private:
    int rows_, cols_;
    std::vector<double> values_;  // Non-zero values
    std::vector<int> col_indices_; // Column indices
    std::vector<int> row_ptrs_;    // Row pointers (CSR format)
};
