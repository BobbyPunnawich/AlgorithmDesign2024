#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int mtMatrix(int n, vector<vector<int>> &matrix, long long row, long long col)
{
    if (n == 1)
    {
        return matrix[row][col];
    }
    long long mid = 1LL << (n - 1);
    if (row < mid)
    {
        if (col < mid)
        {
            return mtMatrix(n - 1, matrix, row, col);
        }
        else
        {
            return mtMatrix(n - 1, matrix, col - mid, row);
        }
    }
    else
    {
        if (col < mid)
        {
            return -mtMatrix(n - 1, matrix, row - mid, col);
        }
        else
        {
            return -mtMatrix(n - 1, matrix, col - mid, row - mid);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v, w, p;
    long long row, col;
    cin >> n >> m;
    vector<vector<int>> matrix(2, vector<int>(2));
    cin >> u >> v >> w >> p;
    matrix[0][0] = u;
    matrix[0][1] = v;
    matrix[1][0] = w;
    matrix[1][1] = p;
    for (int i = 0; i < m; i++)
    {
        cin >> row >> col;
        row--;
        col--;
        cout << mtMatrix(n, matrix, row, col) << "\n";
    }
}