// #include <iostream>
// #include <vector>

// using namespace std;

// // Function to check if a given number can be reached by adding 3 or multiplying by 2
// bool canReach(int N)
// {
//   vector<bool> dp(N + 1, false);
//   dp[1] = true;

//   for (int i = 1; i <= N; i++)
//   {
//     if (dp[i])
//     {
//       if (i + 3 <= N)
//       {
//         dp[i + 3] = true;
//       }
//       if (i * 2 <= N)
//       {
//         dp[i * 2] = true;
//       }
//     }
//   }

//   return dp[N];
// }

// int main()
// {
//   int T;
//   cin >> T;

//   while (T--)
//   {
//     int N;
//     cin >> N;

//     if (canReach(N))
//     {
//       cout << "YES" << endl;
//     }
//     else
//     {
//       cout << "NO" << endl;
//     }
//   }

//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    if (n % 3)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}