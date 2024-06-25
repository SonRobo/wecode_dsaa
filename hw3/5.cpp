#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

#define MOD 1000000007
#define MAX 1000
long long f[MAX][MAX];
int map[MAX][MAX];

int solve(int n)
{
    f[0][0] = map[0][0];

    for (int i = 1; i < n; i++)
    {
        f[i][0] = (map[i][0] == 1 && f[i - 1][0] != 0) ? 1 : 0;
    }

    for (int j = 1; j < n; j++)
    {
        f[0][j] = (map[0][j] == 1 && f[0][j - 1] != 0) ? 1 : 0;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (map[i][j] == 1)
            {
                f[i][j] = (f[i - 1][j] + f[i][j - 1]) % MOD;
            }
            // else
            // {
            //     f[i][j] = 0;
            // }
        }
    }
    return f[n - 1][n - 1];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            map[i][j] = (x == '*' ? 0 : 1);
        }
    }
    cout << solve(n);
}