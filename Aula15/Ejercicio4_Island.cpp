#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j)
{
  int m = grid.size();
  int n = grid[0].size();

  if (i < 0 || j < 0 || i >= m || j >= n)
    return;
  if (grid[i][j] == 'W')
    return;

  grid[i][j] = 'W';
  dfs(grid, i - 1, j);
  dfs(grid, i + 1, j);
  dfs(grid, i, j - 1);
  dfs(grid, i, j + 1);
}

int main()
{
  int m, n;
  cin >> m >> n;
  vector<vector<char>> grid;
  grid.resize(m);
  for (int i = 0; i < m; i++)
    grid[i].resize(n);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> grid[i][j];

  int count = 0;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (grid[i][j] == 'L')
      {
        dfs(grid, i, j);
        count++;
      }
  cout<<count<<endl;
  return 0;
}