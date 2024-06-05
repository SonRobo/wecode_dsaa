#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

class Graph
{
private:
    vector<string> names;             // ds ten cac dinh
    map<string, set<string>> adjList; // anh xa tu ten -> index

public:
    void input()
    {
        int vertex, edge;
        cin >> vertex >> edge;
        while (vertex--)
        {
            string x;
            cin >> x;
            adjList[x];
            names.push_back(x);
        }
        while (edge--)
        {
            string x, y;
            cin >> x >> y;
            adjList[x].insert(y);
            adjList[y].insert(x);
        }
    }
    void solve()
    {
        for (const auto &vertex : names)
        {
            cout << adjList[vertex].size() << " ";
        }
    }
};

int main()
{
    Graph a;
    a.input();
    a.solve();
}