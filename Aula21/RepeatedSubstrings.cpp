#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

bool compare_pair(pair<int, string> a, pair<int, string> b)
{
    return a.second < b.second;
}

int main()
{
    int ts;
    cin >> ts;
    for (int t = 0; t < ts; t++)
    {
        string s;
        cin >> s;
        vector<pair<int, string>> lcpa(s.size());
        for (int i = 0; i < s.size(); i++)
        {
            lcpa[i] = {0, s.substr(i, s.size() - i)};
        }
        sort(lcpa.begin(), lcpa.end(), compare_pair);
        /* lcpa[0].first = 0; */
        lcpa[lcpa.size() - 1].first = 0;
        /* unordered_set<string> repeats; */
        for (int i = 0; i < lcpa.size() - 1; i++)
        {
            int j = 0;
            while (lcpa[i].second[j] == lcpa[i + 1].second[j])
            {
                j++;
                /* repeats.insert(lcpa[i].second.substr(0, j)); */
            }
            lcpa[i].first = j;
        }
        int sum = lcpa[0].first;
        for (int i = 1; i < lcpa.size(); i++)
            if (lcpa[i].first > lcpa[i - 1].first)
                sum += lcpa[i].first - lcpa[i - 1].first;

        /* for (auto &&i : lcpa)
            cout << i.first << " " << i.second << endl; */
        /* cout << s.size() * (s.size() + 1) / 2 - sum << endl; */
        /* cout << repeats.size() << endl; */
        cout << sum << endl;
        /* cout << "---------------" << endl; */
    }
    return 0;
}