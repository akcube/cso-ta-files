int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

void my_gemm(const int N, const float *A, const float *B, float *C)
{
    int BLOCK = 215;
    int m = N;
    int n = N;
    int p = N;
    for (int ii = 0; ii < m; ii += BLOCK)
    {
        for (int jj = 0; jj < n; jj += BLOCK)
        {
            for (int kk = 0; kk < p; kk += BLOCK)
            {
                for (int i = ii; i < min(ii + BLOCK, m); i++)
                {
                    for (int j = jj; j < min(jj + BLOCK, n); j++)
                    {
                        for (int k = kk; k < min(kk + BLOCK, p); k++)
                        {
                            C[i * n + j] += A[i * p + k] * B[k * n + j];
                        }
                    }
                }
            }
        }
    }
}