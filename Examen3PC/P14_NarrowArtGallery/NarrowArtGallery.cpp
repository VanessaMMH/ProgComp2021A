#include <bits/stdc++.h>
using namespace std;

/*
link: https://open.kattis.com/problems/narrowartvec
*/

int N, K;
vector<vector<vector<int>>> buffer;
vector<int> vec;

void NarrowArt()
{
    buffer[0][0][2] = vec[0] + vec[1];
    for (int i = 1; i < N; i++)
        buffer[i][0][2] = buffer[i - 1][0][2] + vec[2 * i] + vec[2 * i + 1];
    if (K > 0)
    {
        buffer[0][1][0] = vec[1];
        buffer[0][1][1] = vec[0];
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < min(i + 1, K) + 1; j++)
        {
            buffer[i][j][0] = vec[2 * i + 1] + max(buffer[i - 1][j - 1][2], buffer[i - 1][j - 1][0]);
            buffer[i][j][1] = vec[2 * i] + max(buffer[i - 1][j - 1][2], buffer[i - 1][j - 1][1]);
            buffer[i][j][2] = vec[2 * i] + vec[2 * i + 1] + max(buffer[i - 1][j][0], max(buffer[i - 1][j][1], buffer[i - 1][j][2]));
        }
    }
    cout << max(buffer[N - 1][K][0], max(buffer[N - 1][K][1], buffer[N - 1][K][2])) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;

    vector<vector<int>> tempv2;
    vector<int> tempv{-100, -100, -100};
    for (int i = 0; i < K + 1; i++)
        tempv2.push_back(tempv);
    for (int i = 0; i < N; i++)
        buffer.push_back(tempv2);

    int temp;
    for (int i = 0; i < N * 2; i++)
    {
        cin >> temp;
        vec.push_back(temp);
    }

    NarrowArt();
    cin >> N >> K;
    return 0;
}