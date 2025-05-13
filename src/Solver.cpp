void ConjugateGradientSolver::solve(const SparseMatrix& A, const double* b, double* x, 
                                    int max_iters, double tol) {
    int n = A.rows();
    std::vector<double> r(n), p(n), Ap(n);
    
    // Initialize
    A.multiply(x, Ap.data());
    #pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        r[i] = b[i] - Ap[i];
        p[i] = r[i];
    }
    
    for (int k = 0; k < max_iters; ++k) {
        A.multiply(p.data(), Ap.data());
        // Parallel dot products (reduction)
        double alpha = parallel_dot(r, r) / parallel_dot(p, Ap);
        // Update x and r
        #pragma omp parallel for
        for (int i = 0; i < n; ++i) {
            x[i] += alpha * p[i];
            r[i] -= alpha * Ap[i];
        }
        if (parallel_norm(r) < tol) break;
        // Update p
        double beta = parallel_dot(r, r) / parallel_dot(p, p);
        #pragma omp parallel for
        for (int i = 0; i < n; ++i) {
            p[i] = r[i] + beta * p[i];
        }
    }
}
