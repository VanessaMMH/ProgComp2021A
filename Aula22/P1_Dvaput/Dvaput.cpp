#include <bits/stdc++.h>
using namespace std;

/*
link: https://open.kattis.com/problems/dvaput
*/

#define MAXLEN 200000
#define MAXHASH 200003

const int maxsize = 2000000;
string s;
int L, pointer;
vector<int> arr, pos;


bool getPos(int x, int y)
{
    if (pos[x] != pos[y])
        return pos[x] < pos[y];
    x += pointer;
    y += pointer;
    return (x < L && y < L) ? pos[x] < pos[y] : x > y;
}


void suffixArray()
{
    for (int i = 0; i < L; i++)
    {
        arr.push_back(i);
        pos.push_back(s[i]);
    }
    int tmp[maxsize];
    for (pointer = 1;; pointer <<= 1)
    {
        sort(arr.begin(), arr.end(), getPos);
        for (int i = 0; i < L - 1; i++)
            tmp[i + 1] = tmp[i] + getPos(arr[i], arr[i + 1]);
        for (int i = 0; i < L; i++)
            pos[arr[i]] = tmp[i];
        if (tmp[L - 1] == L - 1)
            break;
    }
}


int lcp()
{
    int longest_prefix_size = 0;
    vector<int> vec(L);
    for (int i = 0, k = 0; i < L; i++)
    {
        if (pos[i] != L - 1)
        {
            int j = arr[pos[i] + 1];
            while (s[i + k] == s[j + k])
                k++;
            vec[pos[i] + 1] = k;
            longest_prefix_size = max(longest_prefix_size, vec[pos[i] + 1]);
            if (k)
                k--;
        }
    }
    return longest_prefix_size;
}

int Dvaput()
{
    suffixArray();
    return lcp();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L >> s;
    cout << Dvaput();
    return 0;
}