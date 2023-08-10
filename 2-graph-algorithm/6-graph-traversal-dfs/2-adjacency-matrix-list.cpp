#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];

int main()
{
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v); // directed
    // adj[v].push_back(u);  //undirected
  }

  for (int i = 1; i <= n; i++)
  {
    cout << "List " << i << ": ";
    for (int j : adj[i])
    {
      cout << j << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
4
5
1 2 8
1 3 9
2 4 11
4 3 17
3 2 15

List 1: 2 3
List 2: 4
List 3: 2
List 4: 3
*/