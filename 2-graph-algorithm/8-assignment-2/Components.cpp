#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

int bfs(int s)
{
  int count = 0;
  queue<int> q;
  q.push(s);
  visited[s] = true;

  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    count++;

    for (int v : adj[u])
    {
      if (visited[v])
        continue;
      q.push(v);
      visited[v] = true;
    }
  }
  return count;
}

int main()
{

  int n, m;
  cin >> n >> m;
  list<int> a;

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i < N; i++)
  {
    if (!visited[i])
    {
      int ans = bfs(i);
      a.push_back(ans);
    }
  }
  a.sort();
  for (auto it = a.begin(); it != a.end(); ++it)
    if (*it > 1)
      cout << *it << " ";

  return 0;
}
