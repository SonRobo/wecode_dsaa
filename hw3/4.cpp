#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

#define MOD 1000000007
#define MAX 1000000

int s[MAX];

void solve(int n)
{
    s[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i >= j)
            {
                s[i] = (s[i] + s[i - j]) % MOD;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    solve(n);
    cout << s[n];
}