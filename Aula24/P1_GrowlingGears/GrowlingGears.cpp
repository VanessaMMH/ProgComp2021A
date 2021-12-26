#include <bits/stdc++.h>
using namespace std;

/*
link:https://open.kattis.com/problems/growlinggears
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int n, index;
        double max = -500000.0;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            double a, b, c, T = 1;
            cin >> a >> b >> c;
            b /= a;
            c /= a;
            T /= a;
            b /= 2;
            b *= b;
            c += b;
            c /= T;
            if (c > max)
            {
                max = c;
                index = j + 1;
            }
        }
        cout << index << "\n";
    }
}