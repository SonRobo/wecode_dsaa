#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dist(const vector<vector<int>> &graph, int start, int n)
{
    vector<int> distances(n + 1, -1);
    queue<int> q;
    q.push(start);
    distances[start] = 0;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int vertex : graph[current])
        {
            if (distances[vertex] == -1)
            {
                distances[vertex] = distances[current] + 1;
                q.push(vertex);
            }
        }
    }
    return distances;
}

int main()
{
    int n, q;
    cin >> n >> q;

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<vector<int>> save_distances(n + 1);
    for (int i = 1; i <= n; i++)
    {
        save_distances[i] = dist(graph, i, n);
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << save_distances[a][b] << endl;
    }
}