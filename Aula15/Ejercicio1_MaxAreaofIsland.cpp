#include <iostream>
#include <vector>

using namespace std;

int dfs(vector<vector<int>> &grid, int i, int j)
{
  int m = grid.size();
  int n = grid[0].size();

  if (i < 0 || j < 0 || i >= m || j >= n)
    return 0;
  if (grid[i][j] == 0)
    return 0;

  grid[i][j] = 0;

  return dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1) + 1;
}

class Solution
{
public:
  int maxAreaOfIsland(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size();

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
          ans = max(ans, dfs(grid, i, j));
      }
    }
    return ans;
  }
};