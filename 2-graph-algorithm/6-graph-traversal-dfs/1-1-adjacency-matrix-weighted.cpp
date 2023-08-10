#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int adjmat[N][N];

int main()
{
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adjmat[u][v] = w; // directed edge
    adjmat[v][u] = w; // undirected edge
  }

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cout << adjmat[i][j] << " ";
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

0 8 9 0
8 0 15 11
9 15 0 17
0 11 17 0
*/