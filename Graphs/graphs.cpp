#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;
template <typename T>
class Graph
{

public:
  unordered_map<T, list<T>> adj;

  void addEdge(T u, T v, bool direction)
  {
    // direction=0 ->undirected
    // direction=1 ->directed
    adj[u].push_back(v);
    if (direction == 0)
    {
      adj[v].push_back(u);
    }
  }

  void printAdjList()
  {
    for (auto i : adj)
    {
      cout << i.first << "-> ";
      for (auto j : i.second)
      {
        cout << j << ", ";
      }
      cout << endl;
    }
  }
};

int main()
{
  int n;
  cout << "Enter the number of edges" << endl;
  cin >> n;
  int m;
  cout << "enter the number of edges " << endl;
  cin >> m;
  Graph<int> g;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    // creating undirected graph
    g.addEdge(u, v, 0);
  }
  // printing
  g.printAdjList();
  return 0;
}