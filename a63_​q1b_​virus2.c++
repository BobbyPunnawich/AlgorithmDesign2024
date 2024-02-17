#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> reverse(const vector<int> &arr, int start, int stop)
{
    vector<int> res; // Do not initialize with size
    for (int i = stop; i >= start; --i)
    {
        res.push_back(arr[i]);
    }
    return res;
}

bool detectVirus(const vector<int> &arr, int start, int stop)
{
    if (stop <= start)
    {
        return false; // Prevent infinite recursion
    }
    if (stop - start == 1)
    {
        return arr[start] == 0 && arr[stop] == 1;
    }
    int mid = start + (stop - start) / 2;
    bool right = detectVirus(arr, mid + 1, stop);
    vector<int> reversed = reverse(arr, start, mid);
    bool left = detectVirus(arr, start, mid) || detectVirus(reversed, 0, mid - start);
    return left && right;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int length = pow(2, k);
    vector<int> arr(length);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cin >> arr[j];
        }
        if (detectVirus(arr, 0, length - 1))
        {
            cout << "yes"
                 << "\n";
        }
        else
        {
            cout << "no"
                 << "\n";
        }
    }
}
