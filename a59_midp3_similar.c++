#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool similarStr(string &str1, string &str2, int start1, int stop1, int start2, int stop2)
{
    if (start1 == stop1)
    {
        return str1[start1] == str2[start2];
    }
    int mid1 = (start1 + stop1) >> 1;
    int mid2 = (start2 + stop2) >> 1;
    return (similarStr(str1, str2, start1, mid1, start2, mid2) && similarStr(str1, str2, mid1 + 1, stop1, mid2 + 1, stop2)) ||
           (similarStr(str1, str2, start1, mid1, mid2 + 1, stop2) && similarStr(str1, str2, mid1 + 1, stop1, start2, mid2));
}
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.length();
    if (similarStr(str1, str2, 0, n - 1, 0, n - 1))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}