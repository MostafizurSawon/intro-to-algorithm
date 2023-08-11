#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];

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
        level[v] = level[u] + 1;
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

  bfs(1);

  for (int i = 1; i <= n; i++)
  {
    cout << "Level of " << i << " -> " << level[i] << endl;
  }

  return 0;
}

/*
12
11
1 2
1 3
1 10
2 4
2 5
3 9
5 6
5 7
7 8
10 11
10 12
*/