# Parallel-Sparse-Matrix-Solver-with-SIMD-Optimization
sparse_solver/  
├── include/               # Headers  
│   ├── Matrix.hpp         # Sparse matrix class  
│   ├── Vector.hpp         # SIMD-optimized vector  
│   └── Solver.hpp         # Conjugate gradient solver  
├── src/  
│   ├── Matrix.cpp        # CSR format implementation  
│   ├── Solver.cpp        # Parallel solver  
│   └── benchmark.cpp     # Performance tests  
├── tests/                # Unit tests (Google Test)  
├── third_party/          # Eigen (for baseline comparison)  
└── CMakeLists.txt        # Build system  
