#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> adj[100000 + 1];
    bool check[100] = {false};
    int x, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            if (x != 0)
            {
                adj[i].push_back(j);
                check[i] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (check[i])
        {
            cout << i + 1 << "->";
        }
        for (auto it = adj[i].begin();
             it != adj[i].end(); it++)
        {
            cout << *it + 1 << ' ';
        }
        if (check[i])
        {
            cout << endl;
        }
    }

    return 0;
}