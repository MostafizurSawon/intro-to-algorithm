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
  bfs(l);

  int count = 0;
  for (int i = 0; i < N; i++)
  {
    if (level[i] && level[i] == 1)
      count++;
  }
  cout << count;

  return 0;
}
