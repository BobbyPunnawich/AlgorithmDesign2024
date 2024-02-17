#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int mod_expo(int X, int N, int K)
{
    int tmp;
    if (N == 1)
    {
        return X % K;
    }
    else if (N % 2 == 0)
    {
        tmp = mod_expo(X, N / 2, K);
        return (tmp * tmp) % K;
    }
    else
    {
        tmp = mod_expo(X, N / 2, K);
        tmp = (tmp * tmp) % K;
        return (tmp * (X % K)) % K;
    }
}

int main()
{
    int X, N, K;
    cin >> X >> N >> K;
    cout << mod_expo(X, N, K) << '\n';
}