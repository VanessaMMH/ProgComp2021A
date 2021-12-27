#include <bits/stdc++.h>
using namespace std;

/*
link: https://open.kattis.com/problems/suffixsorting
*/

#define MAX_N 100005
long long N = 0, x = 0;
long long n = 0, t = 0, ans = 0;
long long arr[MAX_N];
long long tmp[MAX_N], pos[MAX_N];
string s;

bool compare(long long i, long long j)
{
    if (pos[i] != pos[j])
        return (pos[i] < pos[j]);
    i += t;
    j += t;
    if (i < n && j < n)
        return (pos[i] < pos[j]);
    return (i > j);
}

void SuffixSorting()
{
    for (long long i = 0; i < n; i++)
    {
        arr[i] = i;
        pos[i] = s[i];
    }
    for (t = 1; t < 2 * n + 1; t *= 2)
    {
        sort(arr, arr + n, compare);
        for (long long i = 0; i < n - 1; i++)
        {
            tmp[i + 1] = tmp[i];
            if (compare(arr[i], arr[i + 1]))
                tmp[i + 1]++;
        }
        for (long long i = 0; i < n; i++)
        {
            pos[arr[i]] = tmp[i];
        }
        if (tmp[n - 1] == n - 1)
            break;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (getline(cin, s))
    {
        n = s.size();
        SuffixSorting();

        cin >> N;
        while (N--)
        {
            cin >> x;
            cout << arr[x] << " ";
        }
        cout << "\n";

        cin.ignore();
    }
    return 0;
}