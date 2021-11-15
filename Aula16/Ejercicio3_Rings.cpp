#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000

using namespace std;

void print_with_dots(int n, int rings)
{
  if (rings < 10)
    cout << "." << n;
  else
  {
    if (n < 100)
      cout << ".";
    if (n < 10)
      cout << ".";
    cout << n;
  }
}

bool zero_neighbors(vector<vector<int>> &grid, int i, int j)
{
  if (grid[i - 1][j] == 0)
    return true;
  if (grid[i + 1][j] == 0)
    return true;
  if (grid[i][j - 1] == 0)
    return true;
  if (grid[i][j + 1] == 0)
    return true;
  return false;
}

int main()
{
  int m, n;
  cin >> m >> n;
  vector<vector<int>> grid;
  grid.resize(m + 2);
  for (auto &&i : grid)
    i.resize(n + 2);

  for (int i = 1; i < m + 1; i++)
    for (int j = 1; j < n + 1; j++)
    {
      char x;
      cin >> x;
      if (x == '.')
        grid[i][j] = 0;
      else
        grid[i][j] = INF;
    }
  queue<pair<int, int>> pos_queue;
  for (int i = 1; i < m + 1; i++)
    for (int j = 1; j < n + 1; j++)
    {
      if (grid[i][j] == INF && zero_neighbors(grid, i, j))
      {
        grid[i][j] = 1;
        pos_queue.push({i, j});
      }
    }
  int rings = 0;
  while (!pos_queue.empty())
  {
    pair<int, int> pos = pos_queue.front();
    pos_queue.pop();
    int i = pos.first;
    int j = pos.second;
    int val = grid[i][j];
    rings = val;
    if (grid[i - 1][j] > val)
    {
      grid[i - 1][j] = val + 1;
      pos_queue.push({i - 1, j});
    }
    if (grid[i + 1][j] > val)
    {
      grid[i + 1][j] = val + 1;
      pos_queue.push({i + 1, j});
    }
    if (grid[i][j - 1] > val)
    {
      grid[i][j - 1] = val + 1;
      pos_queue.push({i, j - 1});
    }
    if (grid[i][j + 1] > val)
    {
      grid[i][j + 1] = val + 1;
      pos_queue.push({i, j + 1});
    }
  }

  for (int i = 1; i < m + 1; i++)
  {
    for (int j = 1; j < n + 1; j++)
    {
      if (grid[i][j] == 0)
        if (rings < 10)
          cout << "..";
        else
          cout << "...";
      else
        print_with_dots(grid[i][j], rings);
    }
    cout << endl;
  }
  return 0;
}