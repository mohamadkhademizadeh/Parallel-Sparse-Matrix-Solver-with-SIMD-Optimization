cmake_minimum_required(VERSION 3.10)
project(SparseSolver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-mavx2 -fopenmp")  # Enable AVX and OpenMP

# Main library
add_library(sparse_solver 
    src/Matrix.cpp 
    src/Solver.cpp
)

# Benchmark executable
add_executable(benchmark src/benchmark.cpp)
target_link_libraries(benchmark sparse_solver)

# Tests (Google Test)
enable_testing()
add_subdirectory(tests)
