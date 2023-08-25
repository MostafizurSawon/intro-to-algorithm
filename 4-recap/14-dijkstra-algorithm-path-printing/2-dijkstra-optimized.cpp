#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<pair<int, int>> v[N];
int dis[N];
bool vis[N];

void dijkstra(int s)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  pq.push({0, s});
  dis[s] = 0;
  while (!pq.empty())
  {
    pair<int, int> parent = pq.top();
    pq.pop();
    int parentNode = parent.second;
    if (vis[parentNode])
    {
      continue;
    }
    vis[parentNode] = true;
    int parentCost = parent.first;
    for (int i = 0; i < v[parentNode].size(); i++)
    {
      pair<int, int> child = v[parentNode][i];
      int childNode = child.first;
      int childCost = child.second;
      if (parentCost + childCost < dis[childNode])
      {
        dis[childNode] = parentCost + childCost;
        pq.push({dis[childNode], childNode});
      }
    }
  }
}

int main()
{
  int n, e;
  cin >> n >> e;

  while (e--)
  {
    int a, b, w;
    cin >> a >> b >> w;
    v[a].push_back({b, w});
    // v[b].push_back({a, w});
  }

  for (int i = 1; i <= n; i++)
  {
    dis[i] = INT_MAX;
  }

  dijkstra(1);

  for (int i = 1; i <= n; i++)
  {
    cout << "Node " << i << ": " << dis[i] << endl;
  }

  return 0;
}

/*
5 7
1 3 2
1 2 10
2 3 1
3 4 2
4 5 7
2 4 3
2 5 2

=>
Node 1: 0
Node 2: 10
Node 3: 2
Node 4: 4
Node 5: 11
*/