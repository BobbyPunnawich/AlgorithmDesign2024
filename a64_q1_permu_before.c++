#include <iostream>
#include <vector>
#include <map>

using namespace std;

void permutation(int n, int m, map<int, int> &order, vector<int> &sol, vector<bool> &used, int len) {
    if (len < n) {
        for (int i=0;i<n;i++) {
            if (used[i] == false) {
                if (order.find(i) == order.end() || used[order[i]] == true) {
                    used[i] = true;
                    sol[len] = i;
                    permutation(n, m, order, sol, used, len+1);
                    used[i] = false;
                }  
            }
        }
    } else {
        for (int i=0; i<len; i++) {
            cout << sol[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,a,b;
    map<int,int> order;
    vector<int> sol(n);
    vector<bool> used(n, false);
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        order[b] = a;
    }
    permutation(n,m,order,sol,used,0);
}