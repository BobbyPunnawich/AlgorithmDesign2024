#include <iostream>
#include <vector>

using namespace std;

void consecutiveOnes(int n, int k, vector<string> &sol, int len, int countZero)
{
    if (len < n)
    {
        if (countZero < n - k)
        {
            sol[len] = "0";
            consecutiveOnes(n, k, sol, len + 1, countZero + 1);
        }
        sol[len] = "1";
        consecutiveOnes(n, k, sol, len + 1, countZero);
    }
    else
    {
        int consecutiveOnes = 0;
        for (int i = 0; i < n; i++)
        {
            if (sol[i] == "1")
            {
                consecutiveOnes++;
            }
            else
            {
                consecutiveOnes = 0;
            }
            if (consecutiveOnes == k)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << sol[j];
                }
                cout << "\n";
                break;
            }
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<string> sol(n);
    consecutiveOnes(n, k, sol, 0, 0);
}
