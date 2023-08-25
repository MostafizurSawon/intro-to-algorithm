#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, e;
  cin >> n >> e;
  vector<int> adj[n + 1];

  while (e--)
  {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 0; i <= n; i++)
  {
    cout << "Index " << i << ": ";
    for (int j = 0; j < adj[i].size(); j++)
    {
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
4 4
1 2
2 3
3 4
4 1

Index 0:
Index 1: 2 4
Index 2: 1 3
Index 3: 2 4
Index 4: 3 1
*/