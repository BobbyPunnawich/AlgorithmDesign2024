#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <utility>

using namespace std;

int main()
{
    // follow instructions
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int N, Q, question;
    cin >> N >> Q;
    vector<pair<int, int>> virtualArr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> virtualArr[i].first >> virtualArr[i].second;
    }
    sort(virtualArr.begin(), virtualArr.end());
    for (int i = 1; i < N; i++)
    {
        virtualArr[i].second += virtualArr[i - 1].second;
    }
    for (int i = 0; i < Q; i++)
    {
        cin >> question;
        // Too Slow
        // for (int j = 0; j < N; j++)
        // {
        //     if (question <= virtualArr[j].second)
        //     {
        //         cout << virtualArr[j].first << endl;
        //         break;
        //     }
        // }
        // Faster using BinarySearch
        int left = 0;
        int right = N - 1;
        int ans = 0;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (question <= virtualArr[mid].second)
            {
                ans = virtualArr[mid].first;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        cout << ans << endl;
    }
}