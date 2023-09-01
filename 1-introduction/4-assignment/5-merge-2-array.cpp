#include <bits/stdc++.h>
using namespace std;

void twoSort(int ar1[], int ar2[], int n, int m, int res[])
{
  int a = 0, b = 0, c = 0;
  while (a < n && b < m)
  {
    if (ar1[a] >= ar2[b])
    {
      res[c++] = ar1[a++];
    }
    else
    {
      res[c++] = ar2[b++];
    }
  }

  while (a < n)
  {
    res[c++] = ar1[a++];
  }
  while (b < m)
  {
    res[c++] = ar2[b++];
  }
}

int main()
{
  int n, m;
  cin >> n;
  int ar1[n];

  for (int i = 0; i < n; i++)
  {
    cin >> ar1[i];
  }
  cin >> m;
  int ar2[m];

  for (int i = 0; i < m; i++)
  {
    cin >> ar2[i];
  }
  int x = n + m;
  int res[x];
  twoSort(ar1, ar2, n, m, res);

  for (int i = 0; i < x; i++)
  {
    cout << res[i] << " ";
  }

  return 0;
}

/*
6
8 6 4 3 2 1
8
17 14 13 11 10 9 7 5
ANS: 17 14 13 11 10 9 8 7 6 5 4 3 2 1

4
8 6 4 2
4
7 5 3 1
ANS: 8 7 6 5 4 3 2 1
*/