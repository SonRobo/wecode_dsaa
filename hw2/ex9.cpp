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
            return positions[a.second] > positions[b.second];
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
    vector<int> heuristic;
    unordered_map<string, int> position;

public:
    void input(int v, int e)
    {
        heuristic.resize(v);
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
            cin >> heuristic[i];
        }
        for (int i = 0; i < e; i++)
        {
            string x, y;
            int weight;
            cin >> x >> y >> weight;
            int fv = position[x];
            int sv = position[y];
            adjMatrix[fv][sv] = weight;
        }
        for (int i = 0; i < v; i++)
        {
            positions[i] = position[names[i]];
        }
    }

    void a_star(string s, string e)
    {

        int v = names.size();
        vector<int> dist(v, INT_MAX);
        vector<bool> close(v, false);
        vector<int> trace(v, -1);

        Compare constraint;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> open(constraint);

        int start = position[s];
        int end = position[e];

        dist[start] = 0;
        open.push({heuristic[start], start});
        int cnt = 0;

        while (!open.empty())
        {
            int current_vertex = open.top().second;
            open.pop();

            if (close[current_vertex])
            {
                continue;
            }

            close[current_vertex] = true;
            cnt++;
            if (current_vertex == end)
            {
                break;
            }

            for (int i = 0; i < v; i++)
            {
                if (adjMatrix[current_vertex][i] > 0 && !close[i])
                {
                    int weight = adjMatrix[current_vertex][i];
                    if (dist[i] > dist[current_vertex] + weight)
                    {
                        dist[i] = dist[current_vertex] + weight;
                        trace[i] = current_vertex;
                        open.push({dist[i] + heuristic[i], i});

                        if (close[i])
                        {
                            close[i] = false;
                        }
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

        cnt = count(close.begin(), close.end(), true);
        cout << cnt << " " << (dist[end] == INT_MAX ? 0 : dist[end]) << "\n";
    }

    // void solve(int n)
    // {
    //     while (n--)
    //     {
    //         string start, end;
    //         cin >> start >> end;
    //         a_star(start, end);
    //     }
    // }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph a;
    int v, e;
    cin >> v >> e;
    string start, end;
    cin >> start >> end;
    a.input(v, e);
    a.a_star(start, end);
}