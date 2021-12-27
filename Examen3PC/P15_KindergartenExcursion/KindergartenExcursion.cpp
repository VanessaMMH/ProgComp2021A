#include <iostream>
using namespace std;

/*
link: https://open.kattis.com/problems/excursion
*/

int main()
{
    unsigned long long frontDigits[3] = {0};
    string st;
    cin >> st;
    unsigned long long swaps = 0;
    int i;
    for (auto &&c : st)
    {
        unsigned long long val = c - '0';
        for (i = val + 1; i < 3; i++)
            swaps += frontDigits[i];
        ++frontDigits[val];
    }
    cout << swaps << endl;
    return 0;
}