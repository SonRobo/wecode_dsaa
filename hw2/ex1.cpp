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
        int n;
        cin >> n;
        while (n--)
        {
            string x, y;
            cin >> x >> y;
            adjList[x];
            adjList[x].insert(y);
        }
    }
    void check()
    {
        // for (const auto &vertex : adjList)
        // {
        //     for (const auto &x : vertex.second)
        //     {
        //         cout << vertex.first << " " << x;
        //         cout << endl;
        //     }
        // }
        for (const auto &vertex : adjList)
        {
            for (const auto &x : vertex.second)
            {
                if (adjList[vertex.first].count(x) != adjList[x].count(vertex.first))
                {
                    cout << "FALSE";
                    return;
                }
            }
        }
        cout << "TRUE";
    }
};

int main()
{
    Graph a;
    a.input();
    a.check();
}