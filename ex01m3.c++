#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long calWaitingTime(int N, int c, vector<int> &tableTime, long long start, long long stop)
{
    if (start >= stop)
    {
        return start;
    }
    long long mid = (start + stop) >> 1;
    long long times = N;
    for (int i = 0; i < N; i++)
    {
        times += mid / tableTime[i];
    }
    if (c <= times)
    {
        return calWaitingTime(N, c, tableTime, start, mid);
    }
    else
    {
        return calWaitingTime(N, c, tableTime, mid + 1, stop);
    }
}

int main()
{
    int N, A, c;
    cin >> N >> A;
    vector<int> tableTime(N);
    for (int i = 0; i < N; i++)
    {
        cin >> tableTime[i];
    }
    for (int i = 0; i < A; i++)
    {
        cin >> c;
        cout << calWaitingTime(N, c, tableTime, 0, 10e17) << "\n";
    }
}
