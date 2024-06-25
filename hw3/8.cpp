#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 10000

string s1, s2;
int f[MAX][MAX]; // save cnt at m,n

int solve(string x, string y, int m, int n)
{
    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i == 0)
            {
                f[i][j] = j;
            }
            else if (j == 0)
            {
                f[i][j] = i;
            }
            else if (x[i - 1] == y[j - 1])
            {
                f[i][j] = f[i - 1][j - 1];
            }
            else
            {
                f[i][j] = 1 + min({f[i - 1][j - 1], f[i][j - 1], f[i - 1][j]});
            }
        }
    }
    return f[m][n];
}

int main()
{
    cin >> s1 >> s2;
    memset(f, -1, sizeof(f));
    cout << solve(s1, s2, s1.size(), s2.size());
}
