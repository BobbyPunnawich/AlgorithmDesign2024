#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

void healthSum(int spaceNumber, int monsterNumber, int turretNumber, int turretRange, vector<int> &monsterPositions, vector<int> &monsterHealth, vector<int> &turretPositions)
{
    for (int j = 0; j < turretNumber; j++)
    {
        for (int i = 0; i < monsterNumber; i++)
        {
            if (abs(monsterPositions[i] - turretPositions[j]) <= turretRange)
            {
                monsterHealth[i]--;
                break;
            }
        }
    }
    int healthSum = 0;
    for (int i = 0; i < monsterNumber; i++)
    {
        healthSum += monsterHealth[i];
    }
    cout << healthSum;
}

int main()
{
    int spaceNumber, monsterNumber, turretNumber, turretRange;
    cin >> spaceNumber >> monsterNumber >> turretNumber >> turretRange;
    vector<int> monsterPositions(monsterNumber);
    vector<int> monsterHealth(monsterNumber);
    vector<int> turretPositions(turretNumber);
    for (int i = 0; i < monsterNumber; i++)
    {
        cin >> monsterPositions[i];
    }
    for (int i = 0; i < monsterNumber; i++)
    {
        cin >> monsterHealth[i];
    }
    for (int i = 0; i < turretNumber; i++)
    {
        cin >> turretPositions[i];
    }
    healthSum(spaceNumber, monsterNumber, turretNumber, turretRange, monsterPositions, monsterHealth, turretPositions);
}