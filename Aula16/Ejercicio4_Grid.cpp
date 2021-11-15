#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

struct Tri
{
  int x, y, lvl;
  Tri()
  {
    x = 0;
    y = 0;
    lvl = 0;
  }

  Tri(int x, int y, int lvl)
  {
    this->x = x;
    this->y = y;
    this->lvl = lvl;
  }
};

void add_path(queue<Tri> &bfs, int i, int j, unordered_set<string> &done, int lvl, int m, int n)
{
  if (i < 0 || j < 0 || i >= m || j >= n)
    return;

  string coords = to_string(i) + "," + to_string(j);
  if (done.find(coords) != done.end())
    return;

  done.insert(coords);
  bfs.push(Tri(i, j, lvl + 1));
}

int main()
{
  int m, n;
  cin >> m >> n;
  vector<vector<int>> grid;
  grid.resize(m);
  for (auto &&i : grid)
    i.resize(n);

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    {
      char x;
      cin >> x;
      grid[i][j] = x - '0';
    }

  unordered_set<string> done;
  queue<Tri> bfs;
  bfs.push(Tri(0, 0, 0));

  int steps = -1;
  while (!bfs.empty())
  {
    Tri coords = bfs.front();
    int i = coords.x;
    int j = coords.y;
    int lvl = coords.lvl;
    if( i == m-1 && j == n-1)
    {
      steps = lvl;
      break;
    }
    string pos = to_string(i) + "," + to_string(j);
    bfs.pop();
    int k = grid[i][j];

    add_path(bfs, i - k, j, done, lvl, m, n);
    add_path(bfs, i + k, j, done, lvl, m, n);
    add_path(bfs, i, j - k, done, lvl, m, n);
    add_path(bfs, i, j + k, done, lvl, m, n);
  }
  cout<<steps<<endl;

  return 0;
}