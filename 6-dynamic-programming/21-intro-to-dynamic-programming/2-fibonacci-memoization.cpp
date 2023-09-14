// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;

// const ll N = 1e5 + 5;
// ll save[N];

// ll fibo(ll n)
// {
//   if (n == 0 || n == 1)
//     return 1;
//   // memoization
//   if (save[n] != -1)
//   {
//     return save[n];
//   }
//   ll ans1 = fibo(n - 1);
//   ll ans2 = fibo(n - 2);
//   save[n] = ans1 + ans2;
//   return save[n];
// }

// int main()
// {
//   ll n;
//   cin >> n;
//   for (int i = 0; i <= n; i++)
//   {
//     save[i] = -1;
//   }
//   cout << fibo(n) << endl;

//   return 0;
// }

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int N = 1e5 + 6;
ll save[N];

ll fibo(int n)
{
  if (n <= 1)
    return 1;
  if (save[n] != -1)
    return save[n];
  ll a1 = fibo(n - 1);
  ll a2 = fibo(n - 2);
  return save[n] = a1 + a2;
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++)
  {
    save[i] = -1;
  }
  // cout << fibo(n) << endl;
  for (int i = 1; i <= n; i++)
  {
    cout << i << " -> " << fibo(i) << endl;
  }

  return 0;
}

// complexity O(n)