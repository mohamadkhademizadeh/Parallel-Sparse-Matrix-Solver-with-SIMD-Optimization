class ConjugateGradientSolver {
public:
    void solve(const SparseMatrix& A, const double* b, double* x, int max_iters, double tol);
};
