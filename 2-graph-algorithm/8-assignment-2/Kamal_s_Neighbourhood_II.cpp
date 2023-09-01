#include <bits/stdc++.h>
using namespace std;

const int N = 22;
vector<int> adj[N];
bool visited[N];
int height[N];

void dfs(int u)
{
  visited[u] = true;
  for (int v : adj[u])
  {

    if (!visited[v])
    {
      // cout << v << " ";
      height[N - 1]++;
      dfs(v);
      height[u] = height[u] + height[v] + 1;
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
  }

  cin >> l;
  dfs(l);

  // for (int i = 0; i < n; i++)
  // {
  //   if (!visited[i])
  //   {
  //     bfs(i, l);
  //   }
  // }
  // int ans = INT_MIN;
  // for (int i = 1; i <= N; i++)
  // {
  //   // cout << "Height of Node " << i << ": " << height[i] << endl;
  //   if (height[i] > ans)
  //     ans = height[i];
  // }
  // cout << ans;
  cout << height[N - 1];

  return 0;
}

// // /*
// // 7 5
// // 1 2
// // 1 3
// // 2 3
// // 2 4
// // 5 6
// // */

// #include <bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 5;
// vector<int> adj[N];
// bool visited[N];
// int depth[N];
// int height[N];

// void dfs(int u)
// {
//   // section 1: actions just after entering node u
//   visited[u] = true;
//   for (int v : adj[u])
//   {
//     cout << v << " ";
//     // section 2: actions before entering a new neighbor
//     if (!visited[v])
//     {
//       depth[v] = depth[u] + 1;
//       dfs(v);
//       // if (height[v] + 1 > height[u])
//       //   height[u] = height[v] + 1;
//       height[u] = max(height[u], height[v] + 1);
//     }
//     // section 3: actions after exiting a neighbor
//   }
//   // section 4: actions before exiting node u
// }

// int main()
// {
//   int n, m;
//   cin >> n >> m;
//   for (int i = 0; i < m; i++)
//   {
//     int u, v;
//     cin >> u >> v;
//     adj[u].push_back(v);
//     adj[v].push_back(u);
//   }

//   // for (int i = 1; i <= n; i++)
//   // {
//   //   cout << "Node " << i << ": ";
//   //   for (int j : adj[i])
//   //   {
//   //     cout << j << " ";
//   //   }
//   //   cout << endl;

//   int l;
//   cin >> l;
//   dfs(l);
//   // cout << "Depth: " << endl;
//   // for (int i = 1; i <= n; i++)
//   // {
//   //   cout << "Depth of Node " << i << ": " << depth[i] << endl;
//   // }
//   // cout << "################################################################" << endl;
//   // cout << "Height: " << endl;
//   // for (int i = 1; i <= n; i++)
//   // {
//   //   cout << "Height of Node " << i << ": " << height[i] << endl;
//   // }

//   return 0;
// }
