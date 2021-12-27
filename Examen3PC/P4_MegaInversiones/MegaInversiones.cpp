#include <bits/stdc++.h>
using namespace std;
/*
https://open.kattis.com/problems/megainversions
*/

vector<long long> vec;
vector<long long> inv;
int N;

long long query(vector<long long> &v, int r)
{
    long long s = 0;
    for (; r > 0; r -= (r & (-r)))
        s += v[r];
    return s;
}

void update(vector<long long> &v, int i, long long value)
{
    for (; i <= N; i += (i & (-i)))
        v[i] += value;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vec.assign(N + 1, 0);
    inv.assign(N + 1, 0);

    long long ans = 0LL;
    for (int i = 0; i < N; ++i)
    {
        long long ai;
        cin >> ai;
        ai = N - ai + 1;

        if (ai > 1)
            ans += query(inv, ai - 1);
        if (ai > 1)
            update(inv, ai, query(vec, ai - 1));
        else
            update(inv, ai, 0);
        update(vec, ai, 1);
    }

    cout << ans << "\n";

    return 0;
}