// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 5;
// int dis[N];
// bool vis[N];
// vector<int> v[N];

// void bfs(int src)
// {
//   queue<int> q;
//   q.push(src);
//   vis[src] = true;
//   dis[src] = 0;

//   while (!q.empty())
//   {
//     int parent = q.front();
//     q.pop();
//     cout << parent << endl;
//     for (int i = 0; i < v[parent].size(); i++)
//     {
//       int child = v[parent][i];
//       if (vis[child] == false)
//       {
//         q.push(child);
//         dis[child] = dis[parent] + 1;
//         vis[child] = true;
//       }
//     }
//   }
// }

// int main()
// {
//   int n, e;
//   cin >> n >> e;

//   while (e--)
//   {
//     int a, b;
//     cin >> a >> b;
//     v[a].push_back(b);
//     v[b].push_back(a);
//   }

//   bfs(1);

//   for (int i = 1; i <= n; i++)
//   {
//     cout << "Node " << i << ": " << dis[i] << endl;
//   }

//   return 0;
// }

// /*
// 4 4
// 1 2
// 2 3
// 3 4
// 4 1

// 1
// 2
// 4
// 3
// Node 1: 0
// Node 2: 1
// Node 3: 2
// Node 4: 1
// */

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
vector<int> v[N];
bool vis[N];
int dist[N];

void bfs(int s)
{
  queue<int> q;
  q.push(s);
  vis[s] = true;
  dist[s] = 0;

  while (!q.empty())
  {
    int p = q.front();
    q.pop();
    for (int i = 0; i < v[p].size(); i++)
    {
      int c = v[p][i];
      if (!vis[c])
      {
        q.push(c);
        dist[c] = dist[p] + 1;
        vis[c] = true;
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
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  bfs(1);

  for (int i = 1; i <= n; i++)
  {
    cout << "Node " << i << ": " << dist[i] << endl;
  }

  return 0;
}

/*
5 4
1 2
1 3
2 4
4 5

Node 1: 0
Node 2: 1
Node 3: 1
Node 4: 2
Node 5: 3
*/