#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
  // section 1: actions just after entering node u
  visited[u] = true;
  for (int v : adj[u])
  {
    // section 2: actions before entering a new neighbor
    if (!visited[v])
    {
      // depth[v] = depth[u] + 1;
      dfs(v);
      // if (height[v] + 1 > height[u])
      //   height[u] = height[v] + 1;
      // height[u] = max(height[u], height[v] + 1);
    }
    // section 3: actions after exiting a neighbor
  }
  // section 4: actions before exiting node u
}

void bfs(int s)
{
  queue<int> q;
  q.push(s);
  visited[s] = true;

  while (!q.empty())
  {
    // pop a node from the queue and insert unvisited neighbor of that node
    int u = q.front();
    q.pop();
    cout << "Visiting node: " << u << endl;
    // section 1: A node is being processed

    for (int v : adj[u])
    {
      // section 2: child processing
      if (!visited[v])
      {
        q.push(v);
        visited[v] = true;
        // section 3: child processing
      }
      // section 4: same as section 1
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // bfs(1);
  int cc = 0;

  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
    {
      // dfs(i);
      bfs(i);
      cc++;
    }
  }
  cout << "No of connected components: " << cc << endl;

  return 0;
}

/*
7
5
1 2
1 3
2 3
2 4
5 6
*/