#include <bits/stdc++.h>
using namespace std;

/*
https://cses.fi/problemset/task/1645

*/
int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    cin >> ar[i];

    stack<pair<int, int>> smaller;

    for (int i = 0; i < n; i++)
    {
    while (!smaller.empty() && smaller.top().first >= ar[i])
        smaller.pop();
    if (smaller.empty())
        ans[i] = 0;
    else
        ans[i] = smaller.top().second;
    smaller.push({ar[i], i+1});
    }
    string separator = " ";
    string t = "";
    for (auto &&i : ans)
    {
    cout<<t<<i;
    t = separator;
    }
    cout << endl;
}