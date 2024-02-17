#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int detectVirus(vector<int> &dna, int start, int stop)
{
    if (stop - start == 1)
    {
        return dna[start] + dna[stop];
    }
    int mid = (start + stop) >> 1;
    int left = detectVirus(dna, start, mid);
    int right = detectVirus(dna, mid + 1, stop);
    if (right == -1 || left == -1)
    {
        return -1;
    }
    if (abs(right - left) > 1)
    {
        return -1;
    }
    return left + right;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int length = pow(2, k);
    vector<int> dna(length);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cin >> dna[j];
        }
        if (detectVirus(dna, 0, length - 1) == -1)
        {
            cout << "no"
                 << "\n";
        }
        else
        {
            cout << "yes"
                 << "\n";
        }
    }
}