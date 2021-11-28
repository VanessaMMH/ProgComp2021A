#include <iostream>
#include <vector>
#include <queue>

#define vector3d vector<vector<vector<int>>>
#define INF 100000
using namespace std;


//link : https://open.kattis.com/problems/dungeon


int L, r, c;
int sl, sr, sc, el, er, ec;
vector3d map;
vector<vector<int>> movs;

struct Quad
{
  int l, x, y, time;
  Quad()
  {
    x = 0;
    y = 0;
    l = 0;
  }

  Quad(int l, int x, int y, int time)
  {
    this->x = x;
    this->y = y;
    this->l = l;
    this->time = time;
  }
};

bool is_valid(int l, int x, int y, int time)
{
  if (l == L || x == r || y == c || l < 0 || x < 0 || y < 0)
    return false;
  if (map[l][x][y] == -1)
    return false;
  if (map[l][x][y] <= time && map[l][x][y] >= 0)
    return false;

  return true;
}

void bfs()
{
  queue<Quad> q;
  q.push(Quad(sl, sr, sc, 0));
  Quad sol;
  bool found = false;
  while (!q.empty())
  {
    Quad frnt = q.front();
    q.pop();
    int l = frnt.l;
    int x = frnt.x;
    int y = frnt.y;
    int time = frnt.time;

    if (l == el && x == er && y == ec)
    {
      found = true;
      sol = frnt;
    }

    time++;
    for (auto &&i : movs)
    {
      int nl = l + i[0];
      int nx = x + i[1];
      int ny = y + i[2];

      if (is_valid(nl, nx, ny, time))
      {
        map[nl][nx][ny] = time;
        q.push(Quad(nl, nx, ny, time));
      }
    }
  }
  if (found)
    cout << "Escaped in " << sol.time << " minute(s)." << endl;
  else
    cout << "Trapped!" << endl;
}

int main()
{
  movs.push_back({1, 0, 0});
  movs.push_back({-1, 0, 0});
  movs.push_back({0, 1, 0});
  movs.push_back({0, -1, 0});
  movs.push_back({0, 0, 1});
  movs.push_back({0, 0, -1});

  while (1)
  {
    cin >> L >> r >> c;
    if (L == r && r == c && c == 0)
      break;
    map.resize(L);
    for (int i = 0; i < L; i++)
      map[i].resize(r);
    for (int i = 0; i < L; i++)
      for (int j = 0; j < r; j++)
        map[i][j].resize(c);

    for (int i = 0; i < L; i++)
      for (int j = 0; j < r; j++)
        for (int k = 0; k < c; k++)
        {
          char a;
          cin >> a;
          if (a == 'S')
          {
            sl = i;
            sr = j;
            sc = k;
            map[i][j][k] = 0;
          }
          else if (a == 'E')
          {
            el = i;
            er = j;
            ec = k;
            map[i][j][k] = INF;
          }
          else if (a == '#')
            map[i][j][k] = -1;
          else
            map[i][j][k] = INF;
        }

    bfs();
  }
  return 0;
}