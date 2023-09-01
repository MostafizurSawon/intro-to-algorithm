#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N] = {0};
int level[N] = {0};

void bfs(int s)
{

  queue<int> q;
  q.push(s);
  visited[s] = true;
  level[s] = 0;

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
  int n, m, x;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  cin >> x;

  for (int i = 0; i < x; i++)
  {

    int f, d;
    cin >> f >> d;
    if (f == d)
    {
      cout << 0 << endl;
      continue;
    }

    bfs(f);
    if (visited[d])
    {
      cout << level[d] << endl;
    }
    else
      cout << -1 << endl;
    for (int i = 0; i < N; i++)
    {
      visited[i] = false;
      level[i] = 0;
    }
  }

  return 0;
}
