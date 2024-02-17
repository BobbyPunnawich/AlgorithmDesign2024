#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int getSum(vector<int> &S, int start, int stop)
{
    if (start == 0)
    {
        return S[stop];
    }
    return S[stop] - S[start - 1];
}

int twoMCS(int n, vector<int> &A, vector<int> &S, int start, int stop)
{
    if (start == stop)
    {
        return A[start];
    }
    int mid = (start + stop) >> 1;
    // find max left
    int max_left = twoMCS(n, A, S, start, mid);
    // find max right
    int max_right = twoMCS(n, A, S, mid + 1, stop);
    // summarize max left and right
    int LR_MAX = max(max_left, max_right);

    // find max left_crossing
    int max_left_crossing = getSum(S, mid, mid);
    for (int i = start; i < mid; i++)
    {
        max_left_crossing = max(max_left_crossing, getSum(S, i, mid));
    }
    // find max right_crossing
    int max_right_crossing = getSum(S, mid + 1, mid + 1);
    for (int i = mid + 2; i <= stop; i++)
    {
        max_right_crossing = max(max_right_crossing, getSum(S, mid + 1, i));
    }
    // summarize max left and right crossing
    int LRC_MAX = max_left_crossing + max_right_crossing;

    // summarize max
    return max(LR_MAX, LRC_MAX);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> S(n);
    cin >> A[0];
    S[0] = A[0];
    for (int i = 1; i < n; i++)
    {
        cin >> A[i];
        S[i] = S[i - 1] + A[i];
    }
    cout << twoMCS(n, A, S, 0, n - 1);
}