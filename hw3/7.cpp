#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

#define MAX 100000

int f[MAX]; // save the most pages when spend i price
int price[MAX];
int page[MAX];

int main()
{
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> page[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = x; j >= price[i]; j--)
        {
            f[j] = max(f[j], f[j - price[i]] + page[i]);
        }
    }

    cout << f[x];
}