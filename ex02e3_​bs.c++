#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int binarySearchMax(vector<int> &Arr, int query, int start, int stop)
{
    if (start == stop)
    {
        int duplicates = 1;
        while (Arr[start + duplicates] == query)
        {
            start++;
        }
        if (start == 0 && Arr[start] != query)
        {
            return -1;
        }
        else if (query >= Arr[start])
        {
            return start;
        }
        else
        {
            return start - 1;
        }
    }
    int m = (start + stop) >> 1;
    if (Arr[m] >= query)
    {
        return binarySearchMax(Arr, query, start, m);
    }
    else
    {
        return binarySearchMax(Arr, query, m + 1, stop);
    }
}

int main()
{
    int N, M, query;
    cin >> N >> M;
    vector<int> Arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> Arr[i];
    }
    for (int i = 0; i < M; i++)
    {
        cin >> query;
        cout << binarySearchMax(Arr, query, 0, N - 1) << '\n';
    }
}
