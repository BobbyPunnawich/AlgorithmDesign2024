#include <iostream>
#include <vector>

using namespace std;

void consecutiveOnes(int n,int k,vector<string>&sol,int len) {
    int testK = 0;
    if (len<n) {
        sol[len]= "0";
        consecutiveOnes(n,k,sol,len+1);
        sol[len]= "1";
        consecutiveOnes(n,k,sol,len+1);
    }
    else {
        for (int i=0;i<n;i++) {
            if (sol[i] == "1") {
                testK++;
            }
            else {
                testK = 0;
            }
            if (testK>=k) {
                for (int i=0;i<n;i++) {
                cout << sol[i];
            }
            cout << "\n";
            break;
        }    
        }
    }
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<string> sol(n);
    consecutiveOnes(n,k,sol,0);
}