#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
#include <map>
#include <string>
#include <list>

using namespace std;

#define INF 1000000

map<pair<int, int>, pair<int, int>> path;

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

struct Quad
{
  int x, y, lvl;
  string path;
  Quad()
  {
    x = 0;
    y = 0;
    lvl = 0;
    path = "";
  }

  Quad(int x, int y, int lvl, string path)
  {
    this->x = x;
    this->y = y;
    this->lvl = lvl;
    this->path = path;
  }
};

bool is_valid(vector<vector<int>> &map, int n, int m, int x, int y, int time)
{
  if (x < 0 || x == n || y < 0 || y == m)
    return false;
  if (map[x][y] <= time)
    return false;
  if (map[x][y] == -2)
    return false;

  return true;
}

bool is_valid_monster(vector<vector<int>> &map, int n, int m, int x, int y, int time)
{
  if (x < 0 || x == n || y < 0 || y == m)
    return false;
  if (map[x][y] == -2)
    return false;
  if (map[x][y] <= time)
    return false;

  map[x][y] = time;
  return true;
}

void bfs_monster(int n, int m, vector<vector<int>> &map, vector<pair<int, int>> &monsters)
{
  queue<Tri> q;
  for (auto &&i : monsters)
    q.push(Tri(i.first, i.second, 0));

  while (!q.empty())
  {
    auto act = q.front();
    int x = act.x;
    int y = act.y;
    int time = act.lvl;
    time++;
    q.pop();
    if (is_valid_monster(map, n, m, x - 1, y, time))
    {
      q.push(Tri(x - 1, y, time));
    }

    if (is_valid_monster(map, n, m, x + 1, y, time))
    {
      q.push(Tri(x + 1, y, time));
    }

    if (is_valid_monster(map, n, m, x, y - 1, time))
    {
      q.push(Tri(x, y - 1, time));
    }

    if (is_valid_monster(map, n, m, x, y + 1, time))
    {
      q.push(Tri(x, y + 1, time));
    }
  }
}
void bfs(int n, int m, vector<vector<int>> &map, vector<pair<int, int>> &monsters, int init_x, int init_y)
{
  bool found = false;
  queue<Tri> q;
  q.push(Tri(init_x, init_y, 0));

  path[{init_x, init_y}] = {-1, -1};
  bfs_monster(n, m, map, monsters);

  Tri sol;
  while (!q.empty())
  {
    auto act = q.front();
    int x = act.x;
    int y = act.y;
    int time = act.lvl;
    time++;
    q.pop();

    if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
    {
      sol = act;
      found = true;
      break;
    }
    if (is_valid(map, n, m, x - 1, y, time))
    {
      /* path[coords] = {x, y}; */
      path[{x-1,y}] = {x,y};
      map[x - 1][y] = time;
      q.push(Tri(x - 1, y, time));
    }
    if (is_valid(map, n, m, x + 1, y, time))
    {
      path[{x+1,y}] = {x,y};
      map[x + 1][y] = time;
      q.push(Tri(x + 1, y, time));
    }
    if (is_valid(map, n, m, x, y - 1, time))
    {
      path[{x,y-1}] = {x,y};
      map[x][y - 1] = time;
      q.push(Tri(x, y - 1, time));
    }
    if (is_valid(map, n, m, x, y + 1, time))
    {
      path[{x,y+1}] = {x,y};
      map[x][y + 1] = time;
      q.push(Tri(x, y + 1, time));
    }
  }

  path[{init_x, init_y}] = {-1, -1};
  if (found)
  {
    cout << "YES" << endl;
    pair<int, int> tmp = {sol.x, sol.y};
    pair<int, int> tmp1 = path[{sol.x, sol.y}];
    pair<int, int> ed = {-1, -1};
    vector<char> ans;
    while (tmp1 != ed)
    {
      if ((tmp.second - tmp1.second) == 1 && (tmp.first - tmp1.first) == 0)
        ans.push_back('R');
      if ((tmp.second - tmp1.second) == -1 && (tmp.first - tmp1.first) == 0)
        ans.push_back('L');
      if ((tmp.second - tmp1.second) == 0 && (tmp.first - tmp1.first) == 1)
        ans.push_back('D');
      if ((tmp.second - tmp1.second) == 0 && (tmp.first - tmp1.first) == -1)
        ans.push_back('U');
      tmp = path[{tmp.first, tmp.second}];
      tmp1 = path[{tmp.first, tmp.second}];
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto c : ans)
      cout << c;
  }
  else
    cout << "NO" << endl;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> monsters;
  int init_x, init_y;

  vector<vector<int>> map(n);
  for (int i = 0; i < n; ++i)
    map[i].resize(m);

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
    {
      char t;
      cin >> t;
      if (t == 'M')
      {
        monsters.push_back({i, j});
        map[i][j] = 0;
      }
      if (t == 'A')
      {
        init_x = i;
        init_y = j;
        map[i][j] = INF;
      }
      if (t == '#')
        map[i][j] = -2;
      if (t == '.')
        map[i][j] = INF;
    }

  bfs(n, m, map, monsters, init_x, init_y);

  return 0;
}