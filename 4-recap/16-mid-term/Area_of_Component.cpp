// #include <bits/stdc++.h>
// #define pi pair<int, int>
// using namespace std;

// const int N = 1005;
// bool vis[N][N];
// int dis[N][N];
// char a[N][N];
// int n, m, s, d;
// vector<pi> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// int c = INT_MAX;
// int at = 0;

// bool isValid(int cI, int cJ)
// {
//   if (cI >= 0 && cI < n && cJ >= 0 && cJ < m && a[cI][cJ] == '.')
//   {
//     return true;
//     // at++;
//   }

//   else
//     return false;
// }

// void bfs(int si, int sj)
// {
//   // int a = 0;
//   queue<pi> q;
//   q.push({si, sj});
//   dis[si][sj] = 0;
//   vis[si][sj] = true;

//   while (!q.empty())
//   {
//     pi parent = q.front();
//     int pI = parent.first;
//     int pJ = parent.second;
//     q.pop();
//     for (int i = 0; i < 4; i++)
//     {
//       pi p = path[i];
//       int cI = pI + p.first;
//       int cJ = pJ + p.second;
//       if (isValid(cI, cJ) && !vis[cI][cJ])
//       {
//         vis[cI][cJ] = true;
//         // a++;
//         cout << a[cI][cJ] << endl;
//         q.push({cI, cJ});
//         dis[cI][cJ] = dis[pI][pJ] + 1;
//       }
//     }
//   }
//   if (at)
//     cout << at << " ";
//   // {
//   //   if (a < c)
//   //     c = a;
//   // }
// }

// int main()
// {
//   cin >> n >> m;

//   for (int i = 0; i < n; i++)
//   {
//     for (int j = 0; j < m; j++)
//     {
//       cin >> a[i][j];
//     }
//   }

//   for (int i = 0; i < n; i++)
//   {
//     if (!vis[i][j] && a[i][j] == '.')
// {
//   cnt = 0;
//   dfs(i, j);
//   if (cnt < c)
//     c = cnt;
//   // cout << cnt << endl;
// }
//   }
//   if (c != INT_MAX)
//     cout << c;
//   else
//     cout << -1;

//   return 0;
// }

#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

const int N = 1005;
bool vis[N][N];
int dis[N][N];
char a[N][N];
int n, m, s, d;
vector<pi> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int c = INT_MAX;

bool isValid(int cI, int cJ)
{
  if (cI >= 0 && cI < n && cJ >= 0 && cJ < m)
    return true;
  else
    return false;
}
int cnt;

void dfs(int si, int sj)
{
  vis[si][sj] = true;
  cnt++;
  for (int i = 0; i < 4; i++)
  {
    pair<int, int> p = path[i];
    int ci = si + p.first;
    int cj = sj + p.second;
    if (isValid(ci, cj) && !vis[ci][cj] && a[ci][cj] == '.')
    {
      // cnt++;
      dfs(ci, cj);
    }
  }
}

int main()
{
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (!vis[i][j] && a[i][j] == '.')
      {
        cnt = 0;
        dfs(i, j);
        if (cnt < c)
          c = cnt;
        // cout << cnt << endl;
      }
    }
  }
  if (c != INT_MAX)
    cout << c;
  else
    cout << -1;

  return 0;
}
