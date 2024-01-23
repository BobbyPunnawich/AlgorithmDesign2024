#include <iostream>
#include <vector>

using namespace std;

void genBarcode(int A,int B,vector<string>&sol,int len) {
    int testA = 0;
    if (len<B) {
        sol[len]= "0";
        genBarcode(A,B,sol,len+1);
       // hello my name is Peak!
        sol[len]= "1";
        genBarcode(A,B,sol,len+1);
        
    }
    else {
        for (int i=0;i<B;i++) {
            if (sol[i] == "1") {
                testA++;
            }      
        }
        if (testA==A) {
                for (int i=0;i<B;i++) {
                cout << sol[i];
            }
            cout << "\n";
        }
    }
}

int main() {
    int A,B;
    cin >> A >> B;
    vector<string> sol(B);
    genBarcode(A,B,sol,0);
}