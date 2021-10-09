#include <bits/stdc++.h>
using namespace std;

/*
link: https://www.spoj.com/problems/CODFURY/
*/

int main()
{
  long long t;
  cin >> t;
  for (long long test = 0; test < t; test++)
  {
    long long n, k;
    cin >> n >> k;
    vector<long long> planets(n);
    for (long long i = 0; i < n; i++)
      cin >> planets[i];
    long long max_count = -1;
    long long min_sum = -1;
    long long count = 0;
    long long acc_sum = 0;
    long long start = 0;
    for (long long i = 0; i < n; i++)
    {
      if (acc_sum + planets[i] <= k)
      {
        acc_sum += planets[i];
        count++;
      }
      else
      {
        if (planets[i] > k)
        {
          acc_sum = 0;
          count = 0;
          start = i + 1;
        }
        else
        {
          while (acc_sum + planets[i] > k)
          {
            acc_sum -= planets[start++];
            count--;
          }
          acc_sum += planets[i];
          count++;
        }
      }
      if(count > max_count)
      {
        max_count = count;
        min_sum = acc_sum;
      }
      else if(count == max_count)
        min_sum = min(min_sum, acc_sum);
    }
    cout<<min_sum<<" "<<max_count<<endl;
  }

  return 0;
}