#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

const int N = 1e3 + 10;
vector<string> g;
int visited[N][N];
int level[N][N];
int n, m;
vector<pii> direc = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

bool isValid(int i, int j, int x, int y)
{
  return (i >= 0 && i < x && j >= 0 && j < y);
}

void bfs(int si, int sj, int x, int y)
{
  queue<pii> q;
  q.push({si, sj});
  visited[si][sj] = true;
  level[si][sj] = 0;

  while (!q.empty())
  {
    pii upair = q.front();
    int i = upair.first;
    int j = upair.second;
    q.pop();

    for (auto d : direc)
    {
      int ni = i + d.first;
      int nj = j + d.second;

      if (isValid(ni, nj, x, y) && !visited[ni][nj])
      {
        q.push({ni, nj});
        visited[ni][nj] = true;
        level[ni][nj] = level[i][j] + 1;
      }
    }
  }
}

void reset_level_vis(int x, int y)
{
  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < y; j++)
    {
      level[i][j] = 0;
      visited[i][j] = false;
    }
  }
}

int main()
{
  int si, sj, di, dj;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int x, y, ki, kj, qi, qj;
    cin >> x >> y >> ki >> kj >> qi >> qj;
    if (ki == qi && kj == qj)
    {
      cout << 0 << endl;
      continue;
    }
    bfs(ki, kj, x, y);
    if (level[qi][qj])
      cout << level[qi][qj] << endl;
    else
      cout << -1 << endl;
    reset_level_vis(x, y);
  }

  return 0;
}