#include <iostream>
#include <string>
#include <vector>

using namespace std;

void genBarcode(int ones, int zeroes, int total, vector<string> &barcode, int len)
{
    if (len < total)
    {
        if (zeroes != 0)
        {
            barcode[len] = "0";
            genBarcode(ones, zeroes - 1, total, barcode, len + 1);
        }
        if (ones != 0)
        {
            barcode[len] = "1";
            genBarcode(ones - 1, zeroes, total, barcode, len + 1);
        }
    }
    else
    {
        for (int i = 0; i < total; i++)
        {
            cout << barcode[i];
        }
        cout << '\n';
    }
}

int main()
{
    int ones, total;
    cin >> ones >> total;
    vector<string> barcode(total);
    genBarcode(ones, total - ones, total, barcode, 0);
}