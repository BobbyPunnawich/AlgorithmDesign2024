#include <iostream>
#include <vector>
#include <string>

using namespace std;

string triple_sum(vector<int> &A, int N, int q)
{
    for (int i = 0; i < N - 2; i++)
    {
        int left = i + 1;
        int right = N - 1;
        while (left < right)
        {
            int sum = A[i] + A[left] + A[right];
            if (sum == q)
            {
                return "YES";
            }
            else if (sum < q)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    return "NO";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M, q;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> q;
        cout << triple_sum(A, N, q) << '\n';
    }
}