#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];

bool dfs(int u, int p = -1)
{
  // section 1: actions just after entering node u
  bool cycleExist = false;
  visited[u] = true;
  for (int v : adj[u])
  {
    // section 2: actions before entering a new neighbor
    if (v == p)
      continue;
    if (visited[v])
      return true;

    // if(cycleExist)  return true;
    cycleExist = cycleExist | dfs(v, u);

    // section 3: actions after exiting a neighbor
  }
  // section 4: actions before exiting node u
  return cycleExist;
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

  bool isCycle = false;
  for (int i = 1; i <= n; i++)
  {
    if (!visited[i])
      isCycle |= dfs(i);
  }

  if (isCycle)
    cout << "Cycle detected" << endl;
  else
    cout << "No Cycle detected!" << endl;

  return 0;
}

/*
5 5
1 2
2 3
3 5
5 4
4 2



8 7
1 2
2 3
3 5
2 4
6 7
6 8
7 8
*/