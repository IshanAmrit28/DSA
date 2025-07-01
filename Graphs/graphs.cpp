#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int n, int start, vector<int> adj[], vector<int> &bfs)
{
  vector<bool> visited(n + 1, false);
  queue<int> q;
  q.push(start);
  visited[start] = true;

  while (!q.empty())
  {
    int node = q.front();
    q.pop();
    bfs.push_back(node);
    for (auto it : adj[node])
    {
      if (!visited[it])
      {
        q.push(it);
        visited[it] = true;
      }
    }
  }
}

void DFS_traverse(int start, vector<int> adj[], vector<int> &dfs, vector<bool> &visited)
{
  visited[start] = true;
  dfs.push_back(start);
  for (auto it : adj[start])
  {
    if (!visited[it])
    {
      DFS_traverse(it, adj, dfs, visited);
    }
  }
}
void DFS(int n, int start, vector<int> adj[], vector<int> &dfs)
{
  vector<bool> visited(n, false);
  DFS_traverse(start, adj, dfs, visited);
}
int main()
{
  cout << "enter nodes and edges" << endl;
  int n;
  int m;
  cin >> n >> m;
  vector<int> adj[n + 1];
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    ;
    adj[v].push_back(u);
  }

  cout << "traversal using BFS: ";
  vector<int> bfs;
  vector<int> dfs;
  int start = 1;
  BFS(n, start, adj, bfs);
  for (auto i : bfs)
  {
    cout << i << "|";
  }
  cout << endl;
  cout << "traversal using DFS: ";
  DFS(n, start, adj, dfs);
  for (auto i : dfs)
  {
    cout << i << "|";
  }
  return 0;
}