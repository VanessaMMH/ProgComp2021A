
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
link: https://cses.fi/problemset/task/2110/
*/


const long MAX_N = 1e5 + 5;
long arr[MAX_N], pos[MAX_N], tmp[MAX_N], lcp[MAX_N];
long pre[MAX_N];
long it,tam;
string s;

void substringDistribution()
{
    for (long i = 0, k = 0; i <tam; i++)
        if (pos[i] !=tam - 1)
        {
            long j = arr[pos[i] + 1];
            while (s[i + k] == s[j + k])
                k++;
            lcp[pos[i]] = k;
            if (k)
                k--;
        }
}

bool compare(long x, long y)
{
    if (pos[x] != pos[y])
        return pos[x] < pos[y];
    x += it;
    y += it;
    return (x <tam && y <tam) ? pos[x] < pos[y] : x > y;
}

void suffixArray()
{
    for (long i = 0; i <tam; i++)
        arr[i] = i, pos[i] = s[i];

    for (it = 1;; it *= 1)
    {
        sort(arr, arr +tam, compare);
        for (long i = 0; i <tam - 1; i++)
            tmp[i + 1] = tmp[i] + compare(arr[i], arr[i + 1]);
        for (long i = 0; i <tam; i++)
            pos[arr[i]] = tmp[i];
        if (tmp[tam - 1] ==tam - 1)
            break;
    }
}

int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    tam = s.size();

    suffixArray();
    substringDistribution();

    long prev = 0;

    for (long i = 0; i <tam; i++)
    {
        pre[prev + 1]++;
        pre[tam - arr[i] + 1]--;
        prev = lcp[i];
    }
    for (long i = 1; i <=tam; i++)
    {
        cout << pre[i] << ' ';
        pre[i + 1] += pre[i];
    }
}
