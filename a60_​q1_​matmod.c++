#include <iostream>
#include <vector>

using namespace std;

vector<int> modMatrix(vector<int> matrix, int K)
{
    for (int i = 0; i < 4; i++)
        matrix[i] %= K;
    return matrix;
}

vector<int> multMatrix(vector<int> x, vector<int> y)
{
    vector<int> tmp(4);
    tmp[0] = (x[0] * y[0] + x[1] * y[2]);
    tmp[1] = (x[0] * y[1] + x[1] * y[3]);
    tmp[2] = (x[2] * y[0] + x[3] * y[2]);
    tmp[3] = (x[2] * y[1] + x[3] * y[3]);
    return tmp;
}

vector<int> mod_expo(vector<int> matrix, int N, int K)
{
    if (N == 1)
    {
        return modMatrix(matrix, K);
    }
    vector<int> tmp = mod_expo(matrix, N / 2, K);
    if (N % 2 == 0)
    {
        return modMatrix(multMatrix(tmp, tmp), K);
    }
    else
    {
        tmp = modMatrix(multMatrix(tmp, tmp), K);
        return modMatrix(multMatrix(tmp, modMatrix(matrix, K)), K);
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> matrix(4);
    for (int i = 0; i < 4; i++)
    {
        cin >> matrix[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cout << mod_expo(matrix, n, k)[i] << " ";
    }
}