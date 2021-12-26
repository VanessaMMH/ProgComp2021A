#include <bits/stdc++.h>
using namespace std;

/*
link:https://cses.fi/problemset/task/2108
*/

const long long MAX_N = 1e5 + 5;
vector<long long> suffixArray, pos;
long long N, pointer;
string s;

bool compare(long long x, long long y)
{
    if (pos[x] != pos[y])
        return pos[x] < pos[y];
    x += pointer;
    y += pointer;
    return (x < N && y < N) ? pos[x] < pos[y] : x > y;
}

vector<long long> suffix_array()
{
    for (long long i = 0; i < N; i++)
    {
        suffixArray.push_back(i);
        pos.push_back(s[i]);
    }
    long long tmp[MAX_N];
    for (pointer = 1;; pointer <<= 1)
    {
        sort(suffixArray.begin(), suffixArray.end(), compare);
        for (long long i = 0; i < N - 1; i++)
            tmp[i + 1] = tmp[i] + compare(suffixArray[i], suffixArray[i + 1]);
        for (long long i = 0; i < N; i++)
            pos[suffixArray[i]] = tmp[i];
        if (tmp[N - 1] == N - 1)
            break;
    }
    return suffixArray;
}


vector<long long> lcp()
{
    vector<long long> vec(N);
    for (int i = 0, k = 0; i < N; i++)
    {
        if (pos[i] != N - 1)
        {
            int j = suffixArray[pos[i] + 1];
            while (s[i + k] == s[j + k])
                k++;
            vec[pos[i] + 1] = k;
            if (k)
                k--;
        }
    }
    return vec;
}

string Substring_Order_I(long long k)
{
    suffix_array();
    vector<long long> vec = lcp();
    long long prev = 0, actual = 0;
    for (long long i = 0; i < N; i++)
    {
        if (actual + (N - suffixArray[i]) - prev >= k)
        {
            long long j = prev;
            string ans = s.substr(suffixArray[i], j);
            while (actual < k)
            {
                ans += s[suffixArray[i] + j];
                actual++;
                j++;
            }
            return ans;
        }
        actual += (N - suffixArray[i]) - prev;
        prev = vec[i + 1];
    }
    return "error";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long k;
    cin >> s >> k;
    N = s.size();
    cout << Substring_Order_I(k);
    return 0;
}