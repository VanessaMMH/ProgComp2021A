
#include <bits/stdc++.h>
using namespace std;

/*
link: https://open.kattis.com/problems/suffixarrayreconstruction
*/

string sequence(string s)
{
    int tam = s.size(), smallest = 0;
    string ans = "";
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (s[(smallest + j) % tam] != s[(i + j) % tam])
            {
                if (s[(smallest + j) % tam] > s[(i + j) % tam])
                    smallest = i;
                break;
            }
        }
    }

    for (int i = 0; i < tam; i++)
        ans += s[(smallest + i) % tam];

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        string s;
        cin >> s;
        cout << sequence(s) << "\n";
    }
    return 0;
}
