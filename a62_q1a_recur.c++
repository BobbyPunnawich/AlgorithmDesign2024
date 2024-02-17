#include <iostream>
#include <string>
#include <vector>

using namespace std;

void recur(vector<vector<int>> &v, int a, int b, int top, int bottom, int left, int right)
{
    if (bottom - top == 1)
    {
        v[top][left] = b;
    }
    int mid_Y = (top + right) >> 1;
    int mid_X = (left + right) >> 1;
    recur(v, a, b, top, mid_Y, left, mid_X);
    recur(v, a, b + 1, mid_Y + 1, bottom, left, mid_X);
    recur(v, a, b - 1, top, mid_Y, mid_X + 1, right);
    recur(v, a, b, mid_Y + 1, bottom, mid_X + 1, right);
}

int main()
{
    int a, b;
    cin >> a >> b;
    int n = 1 << a;
    vector<vector<int>> matrix(n, vector<int>(n));
    recur(matrix, a, b, 0, n - 1, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
