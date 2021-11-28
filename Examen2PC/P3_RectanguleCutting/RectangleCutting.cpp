#include <iostream>
#include <vector>

#define ull unsigned long long
#define INF 100000

using namespace std;

vector<vector<int>> dp;

/* dp recursion: bottom up */
int min_cr(int a, int b)
{
  if (a == b)
  {
    dp[a][b] = 0;
    return dp[a][b];
  }
  if (dp[a][b] != -1)
  {
    dp[b][a] = dp[a][b];
    return dp[a][b];
  }
  if (dp[b][a] != -1)
  {
    dp[a][b] = dp[b][a];
    return dp[b][a];
  }
  else
  {
    if (a == 1)
    {
      int mini = INF;
      for (int i = 1; i < b; ++i)
      {
        int x = 1 + min_cr(a, b - i) + min_cr(a, i);
        if (x < mini)
          mini = x;
      }
      dp[a][b] = mini;
      dp[b][a] = mini;
      return dp[a][b];
    }
    if (b == 1)
    {
      int mini = INF;
      for (int i = 1; i < a; ++i)
      {
        int x = 1 + min_cr(a - i, b) + min_cr(i, b);
        if (x < mini)
          mini = x;
      }
      dp[a][b] = mini;
      dp[b][a] = mini;
      return dp[a][b];
    }
    int mini = INF;
    for (int i = 1; i < a; ++i)
    {
      int x = 1 + min_cr(a - i, b) + min_cr(i, b);
      if (x < mini)
        mini = x;
    }
    for (int i = 1; i < b; ++i)
    {
      int x = 1 + min_cr(a, b - i) + min_cr(a, i);
      if (x < mini)
        mini = x;
    }
    dp[a][b] = mini;
    return dp[a][b];
  }
}

/* dp iterative: bottom-up */
int solve(int a, int b)
{
  for (int i = 1; i <= a; ++i)
  {
    for (int j = 1; j <= b; ++j)
    {
      if (i == j)
        dp[i][j] = 0;
      else
      {
        int mini = INF;
        for (int w = 1; w < j; ++w)
          mini = min(mini, 1 + dp[i][j - w] + dp[i][w]);
        for (int h = 1; h < i; ++h)
          mini = min(mini, 1 + dp[i - h][j] + dp[h][j]);
        dp[i][j] = mini;
      }
    }
  }
  return dp[a][b];
}

int main()
{
  int a, b;
  cin >> a >> b;
  int n = max(a, b) + 1;
  dp.resize(n);
  for (int i = 0; i < n; i++)
    dp[i].resize(n);

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dp[i][j] = -1;

  /* cout << min_cr(a, b) << endl; */
  cout << solve(a, b) << endl;

  

  return 0;
}