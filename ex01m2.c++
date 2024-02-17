#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, count = 0;
    cin >> N;
    vector<int> A(N);
    cin >> A[0];
    for (int i = 1; i < N; i++)
    {
        cin >> A[i];
        for (int j = 0; j < i; j++)
        {
            if (A[i] < A[j])
            {
                count++;
            }
        }
    }
    cout << count << endl;
}