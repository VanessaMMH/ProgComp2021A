#include <bits/stdc++.h>
using namespace std;

/*
link:  https://open.katvecs.com/problems/pikemaneasy
*/

#define MOD 1000000007

int main()
{
    long n, t, A, B, C;
    vector<long> vec;
    long temp;
    cin >> n >> t >> A >> B >> C >> temp;
    vec.push_back(temp);
    for (int i = 1; i < n; i++)
        vec.push_back((A * vec[i - 1] + B) % C + 1);

    sort(vec.begin(), vec.end());

    long penalty = 0, success = 0, c = 0;
    for (long v : vec)
    {
        if (v + c <= t)
        {
            penalty = (penalty + v + c) % MOD;
            success++;
            c += v;
        }
        else
        {
            break;
        }
    }

    cout << success << " " << penalty << endl;
    return 0;
}