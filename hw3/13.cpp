#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int money(vector<int> &baloons)
{
    int n = baloons.size();
    baloons.insert(baloons.begin(), 1);
    baloons.push_back(1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int length = 1; length <= n; ++length)
    {
        for (int left = 1; left <= n - length + 1; ++left)
        {
            int right = left + length - 1;
            for (int k = left; k <= right; ++k)
            {
                dp[left][right] = max(dp[left][right], dp[left][k - 1] + baloons[left - 1] * baloons[k] * baloons[right + 1] + dp[k + 1][right]);
            }
        }
    }

    return dp[1][n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> baloons(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> baloons[i];
    }

    cout << money(baloons) << endl;
    return 0;
}
