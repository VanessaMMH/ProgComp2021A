#include <bits/stdc++.h>
using namespace std;

/*
link: https://open.kattis.com/problems/trendingtopic
*/

map<int, set<string>> st;
map<string, int> dict;
vector<string> words[7];
int day = 0;

void text()
{
    string s;
    for (string p : words[day])
    {
        dict[p]--;
        if (dict[p] == 0)
            dict.erase(p);
    }
    words[day].clear();

    cin >> s;
    while (s != "</text>")
    {
        if (s.length() >= 4)
        {
            words[day].push_back(s);
            dict[s]++;
        }
        cin >> s;
    }
    day = (day + 1) % 7;
}

void top()
{
    int N;
    cin >> N;
    string temp;
    cin >> temp;

    st.clear();

    for (auto it : dict)
    {
        if (it.second > 0)
            st[it.second].insert(it.first);
    }

    int cont = 0;
    cout << "<top " << N << ">\n";
    for (auto it = st.rbegin(); cont < N && it != st.rend(); it++)
    {
        for (auto word : it->second)
        {
            cout << word << " " << it->first << "\n";
            cont++;
        }
    }
    cout << "</top>\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string tag;
    while (cin >> tag)
    {
        if (tag == "<text>")
            text();
        else
            top();
    }
}