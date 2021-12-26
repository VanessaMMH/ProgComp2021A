#include <bits/stdc++.h>
using namespace std;

/*
link: https://open.kattis.com/problems/bachetsgame

*/

string bachetsGame(int n, int m)
{
    int arr[10];
    bool stone_map[n];
    for (int i = 0; i < m; i++)
        cin >> arr[i];
    stone_map[0] = false;
    for (int i = 1; i <= n; i++)
    {
        stone_map[i] = false;
        for (int j = 0; j < m; j++)
        {
            if (i >= arr[j] && !stone_map[i - arr[j]])
            {
                stone_map[i] = true;
                break;
            }
        }
    }
    if (stone_map[n])
        return "Stan wins";
    return "Ollie wins";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    while (cin >> n >> m)
        cout << bachetsGame(n, m) << "\n";

    return 0;
}