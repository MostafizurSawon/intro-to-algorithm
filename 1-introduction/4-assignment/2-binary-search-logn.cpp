#include <bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int lb, int ub, int x)
{
    int mid = (lb + ub) / 2;

    if (lb <= ub)
    {
        if (a[mid] == x)
        {
            return mid;
        }

        else if (a[mid] < x)
        {
            binarySearch(a, mid + 1, ub, x);
        }

        else
        {
            binarySearch(a, lb, mid - 1, x);
        }
    }

    else
    {
        return -1;
    }
}

int main()
{
    int n, m;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> m;
    int index = binarySearch(a, 0, n - 1, m);

    if (index == -1)
    {
        cout << "Not Found";
    }
    else
    {
        cout << index;
    }

    return 0;
}

/*
8
-4 0 2 6 9 10 29 54
29
=>6

10
0 1 2 3 4 5 6 7 8 9
-3
=> Not Found
*/