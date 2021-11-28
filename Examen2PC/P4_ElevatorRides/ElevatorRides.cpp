#include <iostream>
#include <vector>

#define ll long long
#define pii pair<int,int>

using namespace std;

int solve(int n, ll x, vector<ll> &weights)
{
  vector<pii> dp(1 << n);
  int num_sets = 1 << n;
  dp[0] = {1, 0};
  for (int s = 1; s < (num_sets); s++)
  {
    dp[s] = {n + 1, 0};
    for (int p = 0; p < n; p++)
    {
      if (s & (1 << p))
      {
        pii option = dp[s ^ (1 << p)];
        if (option.second + weights[p] <= x)
          option.second += weights[p];
        else
        {
          option.first++;
          option.second = weights[p];
        }
        dp[s] = min(dp[s], option);
      }
    }
  }
  return dp[num_sets - 1].first;
}

int main()
{
  int n;
  ll x;
  cin >> n >> x;
  vector<ll> weights(n);
  for (int i = 0; i < n; ++i)
    cin >> weights[i];
  cout << solve(n, x, weights);
  return 0;
}