#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

class Graph
{
private:
    set<string> names;                     // ds ten cac dinh
    map<string, map<string, int>> adjList; // anh xa tu ten -> index
    string start;                          // start vertex
    int n;

public:
    void input()
    {
        int edge;
        string s;
        cin >> edge >> s;
        start = s;
        while (edge--)
        {
            string x, y;
            int w;
            cin >> x >> y >> w;
            names.insert(x);
            names.insert(y);
            adjList[x];
            adjList[x].insert({y, w});
        }
        n = names.size();
    }
    void shortest_path(int solved, set<string> &visited, string cur_vertex, int cost, vector<string> &path, int &sol, vector<string> &best_path)
    {

        if (solved == n && adjList[cur_vertex][start])
        {
            if (cost + adjList[cur_vertex][start] < sol)
            {
                sol = cost + adjList[cur_vertex][start];
                best_path = path;
                best_path.push_back(start);
            }
            return;
        }
        for (auto vertex : adjList[cur_vertex])
        {
            if (!visited.count(vertex.first) && vertex.second)
            {
                visited.insert(vertex.first);
                path.push_back(vertex.first);
                shortest_path(solved + 1, visited, vertex.first, cost + vertex.second, path, sol, best_path);
                visited.erase(vertex.first);
                path.pop_back();
            }
        }
    }
    void solve()
    {
        set<string> visited;
        vector<string> path;
        vector<string> best_path;
        int sol = 1000000;

        path.push_back(start);
        visited.insert(start);

        shortest_path(1, visited, start, 0, path, sol, best_path);

        for (auto vertex : best_path)
        {
            cout << vertex << " ";
        }
    }
};

int main()
{
    Graph a;
    a.input();
    a.solve();
}