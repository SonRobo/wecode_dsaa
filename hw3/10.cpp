#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1000000

int nst[MAX], f[MAX];

int main()
{
    int n;
    cin >> n;
    f[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> nst[i];
        for (int j = 1000000; j > 0; j--)
        {
            if (f[j] != 1 && f[j - nst[i]] == 1 && j >= nst[i])
            {
                f[j] = 1;
            }
        }
    }
    vector<int> res;
    for (int i = 1; i < 1000000; i++)
    {
        if (f[i] == 1)
        {
            res.push_back(i);
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}