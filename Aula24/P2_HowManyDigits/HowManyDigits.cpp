#include <bits/stdc++.h>
using namespace std;

/*
link:https://open.kattis.com/problems/howmanydigits
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0;
    vector<double> number_of_digits;
    number_of_digits.push_back(0);
    for (int i = 1; i < 1000001; i++)
        number_of_digits.push_back(number_of_digits.back() + log10(i));
    while (cin >> n)
        cout << (int)number_of_digits[n] + 1 << "\n";
}