#include <iostream>
#include <vector>
#include <math.h>

#define LIMIT 500006

using namespace std;

//link: https://www.beecrowd.com.br/judge/en/problems/view/2792


vector<int> ind(LIMIT);

int get_next(int x)
{
  return x + (x & (-x));
}

int get_parent(int x)
{
  return x - (x & (-x));
}

int get_sum(int x)
{
  int sum = 0;
  while (x > 0)
  {
    sum += ind[x];
    x -= (x & (-x));
  }
  return sum;
}

void update_interval(int x)
{
  while (x < LIMIT)
  {
    ++ind[x];
    x += (x & (-x));
  }
}

int main()
{
	ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int x;
  for (int i = 0; i < n; i++)
  {
    cin >> x;

    cout << x - get_sum(x);

    if (i == n - 1)
      cout << endl;
    else
      cout << " ";
    update_interval(x);
  }
  return 0;
}