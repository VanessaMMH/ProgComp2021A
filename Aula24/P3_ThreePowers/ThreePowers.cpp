#include <bits/stdc++.h>
using namespace std;

/*
link: https://open.kattis.com/problems/threepowers
*/

vector<long double> vec;

void threePowers(long long int n)
{
    long double pow = 0, values = 0;
    cout << "{";
    while (n > 0)
    {
        if (n & 1 == 1)
        {
            if (values == 0)
                cout << " " << setprecision(100) << vec[pow];
            else
                cout << ", " << setprecision(100) << vec[pow];
            values++;
        }
        n >>= 1;
        pow++;
    }
    cout << " }\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vec.push_back(1);
    for (int i = 1; i < 100; ++i)
    {
        vec.push_back(vec[i - 1] * 3);
    }

    long long int n = 0;
    while (true)
    {
        cin >> n;
        if (n == 0)
            return 0;
        threePowers(n - 1);
    }
    return 0;
}