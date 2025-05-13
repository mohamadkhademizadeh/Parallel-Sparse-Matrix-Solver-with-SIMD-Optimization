#include "Matrix.hpp"
#include <omp.h>  // OpenMP

void SparseMatrix::multiply(const double* x, double* y) const {
    #pragma omp parallel for
    for (int i = 0; i < rows_; ++i) {
        __m256d sum = _mm256_setzero_pd();
        int start = row_ptrs_[i];
        int end = row_ptrs_[i + 1];
        
        // Process 4 elements at a time (AVX)
        for (int j = start; j < end; j += 4) {
            __m256d vals = _mm256_loadu_pd(&values_[j]);
            __m256d vec = _mm256_set_pd(
                x[col_indices_[j+3]], 
                x[col_indices_[j+2]], 
                x[col_indices_[j+1]], 
                x[col_indices_[j]]
            );
            sum = _mm256_fmadd_pd(vals, vec, sum);
        }
        
        // Horizontal sum
        double tmp[4];
        _mm256_storeu_pd(tmp, sum);
        y[i] = tmp[0] + tmp[1] + tmp[2] + tmp[3];
    }
}
