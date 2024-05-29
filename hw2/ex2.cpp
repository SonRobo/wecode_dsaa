#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

bool sortbysec(const pair<string, int> &a,
               const pair<string, int> &b)
{
    return (a.second < b.second);
}

class Graph
{
private:
    vector<string> names;                           // ds ten cac dinh
    map<string, vector<pair<string, int>>> adjList; // anh xa tu ten -> index
    string start;                                   // start vertex
    int e;

public:
    void input()
    {
        int edge;
        string s;
        cin >> edge >> s;
        start = s;
        e = edge;
        while (edge--)
        {
            string x, y;
            int w;
            cin >> x >> y >> w;
            adjList[x];
            adjList[x].push_back({y, w});
        }

        for (auto &vertex : adjList)
        {

            sort(vertex.second.begin(), vertex.second.end(), sortbysec);
        }
    }
    void solve()
    {

        vector<string> visited;

        string v;
        int i = 1;
        auto temp = adjList[start].begin();
        v = temp->first;
        cout << start << " " << v << " ";
        visited.push_back(v);
        visited.push_back(start);
        while (i < e)
        {

            for (auto temp : adjList[v])
            {
                string vertex = temp.first;
                if (!(find(visited.begin(), visited.end(), vertex) != visited.end()))
                {
                    cout << vertex << " ";
                    visited.push_back(vertex);
                    v = vertex;
                    break;
                }
            }
            i++;
        }
        cout << start;
    }
};

int main()
{
    Graph a;
    a.input();
    a.solve();
}