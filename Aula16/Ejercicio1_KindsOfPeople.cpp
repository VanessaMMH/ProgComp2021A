#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

void path_cluster(vector<vector<int>> &grid, int i, int j, char kind, int id)
{
  int m = grid.size();
  int n = grid[0].size();

  if (i < 0 || j < 0 || i >= m || j >= n)
    return;
  if (kind == 1)
    if (grid[i][j] <= 0)
      return;
  if (kind == 0)
    if (grid[i][j] >= 1)
      return;

  if (grid[i][j] == id)
    return;

  grid[i][j] = id;
  path_cluster(grid, i - 1, j, kind, id);
  path_cluster(grid, i + 1, j, kind, id);
  path_cluster(grid, i, j - 1, kind, id);
  path_cluster(grid, i, j + 1, kind, id);
}

int main()
{
  int m, n;
  cin >> m >> n;
  vector<vector<int>> grid;
  grid.resize(m);
  for (int i = 0; i < m; i++)
    grid[i].resize(n);
  char x;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      cin >> x;
      grid[i][j] = x - '0';
    }

  int bin_count = -2;
  int dec_count = 2;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      int kind = grid[i][j];
      if (kind == 1)
      {
        path_cluster(grid, i, j, kind, dec_count);
        dec_count++;
      }
      if (kind == 0)
      {
        path_cluster(grid, i, j, kind, bin_count);
        bin_count--;
      }
    }
  }

  int num_q;
  cin >> num_q;
  for (int q = 0; q < num_q; q++)
  {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--;
    c1--;
    r2--;
    c2--;
    if (grid[r1][c1] == grid[r2][c2])
      if (grid[r1][c1] < 0)
        cout << "binary" << endl;
      else
        cout << "decimal" << endl;
    else
      cout << "neither" << endl;
  }

  return 0;
}