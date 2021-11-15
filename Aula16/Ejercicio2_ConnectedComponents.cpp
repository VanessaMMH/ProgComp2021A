#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;

void dfs(map<int, unordered_set<int>> &graph, int id, set<int> &new_component, unordered_set<int> &visited)
{
  new_component.insert(id);
  for (auto &&i : graph[id])
  {
    if (visited.find(i) == visited.end())
    {
      visited.insert(i);
      dfs(graph, i, new_component, visited);
    }
  }
}

int main()
{
  int ts;
  cin >> ts;
  for (int t = 0; t < ts; t++)
  {
    map<int, unordered_set<int>> graph;
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
      char from, to;
      cin >> from >> to;

      graph[from - 'a'].insert(to - 'a');
      graph[to - 'a'].insert(from - 'a');
    }
    for (int i = 0; i < v; i++)
      if (graph.find(i) == graph.end())
        graph[i] = {};

    cout << "Case #" << t + 1 << ":\n";
    int num_comps = 0;
    map<int, set<int>> components;
    unordered_set<int> visited;
    for (auto &&i : graph)
    {
      if (visited.find(i.first) == visited.end())
      {
        num_comps++;
        visited.insert(i.first);
        components[i.first] = {};
        dfs(graph, i.first, components[i.first], visited);
      }
    }
    for (auto &&i : components)
    {
      for (auto &&j : i.second)
        cout << char(j + 'a') << ",";
      cout << endl;
    }

    cout << num_comps << " connected components" << endl
         << endl;
  }
}