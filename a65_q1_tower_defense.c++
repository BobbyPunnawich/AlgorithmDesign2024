#include <iostream>
#include <vector>

using namespace std;


int minMonsterPower(vector<int> &monsterPositions,vector<int> &monsterHealths,vector<int> &towerPositions,int monsterNumber,int towerNumber,int towerRange) {
    int sum = 0;
    for (int j = 0; j < towerNumber; j++) {
        for (int i = 0; i < monsterNumber; i++) {
            if (monsterPositions[i] >= towerPositions[j]-towerRange && monsterPositions[i] <= towerPositions[j]+towerRange && monsterHealths[i] >= 1) {
                monsterHealths[i]--;
                break;
            }
        }
    }
    for (int i = 0; i < monsterNumber; i++) {
        sum+=monsterHealths[i];
    }
    return sum;
}

int main() {
    int positionNumber,monsterNumber,towerNumber,towerRange,mock;
    cin >> positionNumber >> monsterNumber >> towerNumber >> towerRange;
    vector<int> monsterPositions(monsterNumber);
    vector<int> monsterHealths(monsterNumber);
    vector<int> towerPositions(towerNumber);
    for (int i=0; i<monsterNumber; i++) {
        cin >> monsterPositions[i];
    }
    for (int i=0; i<monsterNumber; i++) {
        cin >> monsterHealths[i];
    }
    for (int i=0; i<towerNumber; i++) {
        cin >> towerPositions[i];
    }
    cout << minMonsterPower(monsterPositions,monsterHealths,towerPositions,monsterNumber,towerNumber,towerRange);
}