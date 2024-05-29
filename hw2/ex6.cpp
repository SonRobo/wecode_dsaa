#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Graph
{
private:
    vector<string> names;                  // ds ten cac dinh
    map<string, map<string, int>> adjList; // anh xa tu ten -> index

public:
    void input(int v, int n)
    {
        for (int i = 0; i < v; i++)
        {
            string x;
            cin >> x;
            names.push_back(x);
            adjList[x];
        }
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                int x;
                cin >> x;
                if (x > 0 && i != j)
                {
                    adjList[names[i]].insert({names[j], x});
                }
            }
        }
    }

    void dijkstra(string s, string e)
    {
        if (adjList[s].empty())
        {
            cout << "-unreachable-" << endl;
            return;
        }

        map<string, int> dist;
        map<string, string> trace;
        set<pair<int, string>> pq;
        set<string> expanded;

        for (auto vertex : names)
        {
            dist[vertex] = 1000000;
        }
        dist[s] = 0;
        pq.insert({0, s});
        while (!pq.empty())
        {
            string x = pq.begin()->second;
            pq.erase(pq.begin());
            expanded.insert(x);

            for (auto temp : adjList[x])
            {
                string v = temp.first;
                int weight = temp.second;
                if (dist[v] > dist[x] + weight)
                {
                    pq.erase({dist[v], v});
                    dist[v] = dist[x] + weight;
                    trace[v] = x;
                    pq.insert({dist[v], v});
                }
            }
        }

        if (dist[e] > 1000000)
        {
            cout << "-unreachable-" << endl;
        }
        else
        {
            vector<string> path;
            for (string v = e; v != s; v = trace[v])
            {
                path.push_back(v);
            }
            path.push_back(s);
            reverse(path.begin(), path.end());

            cout << "Shortest path from " << s << " to " << e << ": ";
            for (auto &v : path)
            {
                cout << v << " ";
            }
            cout << "\nDistance: " << dist[e] << endl;
            cout << "so dinh mo rong: " << expanded.size() << endl;
        }
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
    Graph a;
    int v, n;
    cin >> v >> n;
    a.input(v, n);
    a.solve(n);
}