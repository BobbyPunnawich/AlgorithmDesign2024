#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void permConstraint(int n, int m, vector<int> &sol, int len, vector<bool> &used, map<int, int> &order)
{
    if (len < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (order.find(i) == order.end() || used[order[i]])
            {
                if (!used[i])
                {
                    used[i] = true;
                    sol[len] = i;
                    permConstraint(n, m, sol, len + 1, used, order);
                    used[i] = false;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << sol[i] << " ";
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b;
    cin >> n >> m;
    map<int, int> order;
    vector<int> sol(n);
    vector<bool> used(n, false);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        order[b] = a;
    }
    permConstraint(n, m, sol, 0, used, order);
}
