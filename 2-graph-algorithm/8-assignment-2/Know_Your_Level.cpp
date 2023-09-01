#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
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
    int u = q.front();
    q.pop();

    for (int v : adj[u])
    {
      if (!visited[v])
      {
        q.push(v);
        visited[v] = true;
        level[v] = level[u] + 1;
      }
    }
  }
}

int main()
{
  int n, m, l;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  cin >> l;

  bfs(0);
  int x = 0;

  for (int i = 0; i < N; i++)
  {
    if (l == 0)
    {
      cout << 0;
      x = 1;
      break;
    }
    if (level[i] == l)
    {
      cout << i << " ";
      x = 1;
    }
  }
  if (!x)
    cout << -1;

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