#include <bits/stdc++.h>
using namespace std;

/*
link:https://open.kattis.com/problems/stringmatching
*/

const int TAM = 4000000;
string s, t;
int n, arr[TAM], tab[TAM];

void getNext()
{
    arr[0] = -1;
    int i = 0, j = -1;
    while (t[i] != '\0')
    {
        if (j == -1 || t[i] == t[j])
        {
            i++;
            j++;
            arr[i] = j;
        }
        else
            j = arr[j];
    }
}

int KMP()
{
    getNext();
    int i = 0, j = 0, pos = 0, len = t.size();
    while (s[i])
    {
        if (j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else
            j = arr[j];
        if (j == len)
        {
            j = arr[j];
            tab[pos++] = i;
        }
    }
    return pos;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (getline(cin, t))
    {
        getline(cin, s);
        int ss = KMP();
        for (int i = 0; i < ss; i++)
        {
            if (i)
                cout << " ";
            cout << tab[i] - t.size();
        }
        cout << "\n";
    }
}