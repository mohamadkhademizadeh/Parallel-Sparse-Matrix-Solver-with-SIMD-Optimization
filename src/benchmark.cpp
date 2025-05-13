#include "Matrix.hpp"
#include <chrono>

int main() {
    SparseMatrix A(10000, 10000);  // Large sparse matrix
    // ... Fill A with data (e.g., finite difference matrix) ...
    
    std::vector<double> x(A.cols(), 1.0), b(A.rows(), 0.0);
    
    auto start = std::chrono::high_resolution_clock::now();
    A.multiply(x.data(), b.data());
    auto end = std::chrono::high_resolution_clock::now();
    
    std::cout << "SpMV time: " 
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() 
              << " μs\n";
}
