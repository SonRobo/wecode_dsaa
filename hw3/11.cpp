#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100005

long long f[MAX];

int main()
{
    int v[101], w[101];
    int n, W;
    cin >> n >> W;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = W; j >= 0; j--)
        {
            if (j >= w[i])
            {
                f[j] = max(f[j], f[j - w[i]] + v[i]);
            }
        }
    }
    cout << f[W] << endl;
}