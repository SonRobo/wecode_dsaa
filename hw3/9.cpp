#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

#define MAX 200005

vector<int> graph[MAX];
int depth[MAX];
int parent[MAX];

void dfs(int v, int p, int d)
{
    depth[v] = d;
    parent[v] = p;
    for (int u : graph[v])
    {
        if (u != p)
        {
            dfs(u, v, d + 1);
        }
    }
}

int lca(int a, int b)
{
    while (depth[a] > depth[b])
    {
        a = parent[a];
    }
    while (depth[b] > depth[a])
    {
        b = parent[b];
    }
    while (a != b)
    {
        a = parent[a];
        b = parent[b];
    }

    return a;
}

int main()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    memset(parent, -1, sizeof(parent));
    dfs(1, 1, 0);

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        int ans = lca(a, b);
        int dist = depth[a] + depth[b] - 2 * depth[ans];
        cout << dist << endl;
    }
    return 0;
}