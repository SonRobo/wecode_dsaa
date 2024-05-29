#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> positions;

class Compare
{
private:
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.first == b.first)
        {
            return positions[a.second] < positions[b.second];
        }
        else
        {
            return a.first > b.first;
        }
    }
};

class Graph
{
private:
    vector<string> names;
    vector<vector<int>> adjMatrix;
    unordered_map<string, int> position;

public:
    void input(int v)
    {
        adjMatrix.resize(v, vector<int>(v, 0));
        positions.resize(v);
        for (int i = 0; i < v; i++)
        {
            string x;
            cin >> x;
            names.push_back(x);
            position[x] = i;
        }
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                cin >> adjMatrix[i][j];
            }
        }
        for (int i = 0; i < v; i++)
        {
            positions[i] = position[names[i]];
        }
    }

    void dijkstra(string s, string e)
    {

        int v = names.size();
        vector<int> dist(v, INT_MAX);
        vector<bool> visited(v, false);
        vector<int> trace(v, -1);

        Compare constraint;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq(constraint);

        int start = position[s];
        int end = position[e];

        dist[start] = 0;
        pq.push({0, start});
        int cnt = 0;

        while (!pq.empty())
        {
            int current_vertex = pq.top().second;
            pq.pop();

            if (visited[current_vertex])
            {
                continue;
            }

            visited[current_vertex] = true;
            cnt++;
            if (current_vertex == end)
            {
                break;
            }

            for (int i = 0; i < v; i++)
            {
                if (adjMatrix[current_vertex][i] > 0 && !visited[i])
                {
                    int weight = adjMatrix[current_vertex][i];
                    if (dist[i] > dist[current_vertex] + weight)
                    {
                        dist[i] = dist[current_vertex] + weight;
                        trace[i] = current_vertex;
                        pq.push({dist[i], i});
                    }
                }
            }
        }

        if (dist[end] == INT_MAX)
        {
            cout << "-unreachable-\n";
        }
        else
        {
            vector<string> path;
            for (int i = end; i != -1; i = trace[i])
            {
                path.push_back(names[i]);
            }
            reverse(path.begin(), path.end());

            for (auto &v : path)
            {
                cout << v << " ";
            }
            cout << "\n";
        }
        cout << cnt << " " << (dist[end] == INT_MAX ? 0 : dist[end]) << "\n";
    }

    void solve(int n)
    {
        while (n--)
        {
            string start, end;
            cin >> start >> end;
            dijkstra(start, end);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph a;
    int v, n;
    cin >> v >> n;
    a.input(v);
    a.solve(n);
}