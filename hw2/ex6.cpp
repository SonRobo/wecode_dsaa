#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Compare
{
private:
public:
    bool operator()(pair<int, string> a, pair<int, string> b)
    {
        return a.first > b.first;
    }
};

class Graph
{
private:
    vector<string> names;             // ds ten cac dinh
    map<string, set<string>> adjList; // anh xa tu ten -> index
    vector<int> colored;
    set<int> colors;
    map<string, int> util;
    vector<pair<int, string>> vertex_sorted; // sort theo so dinh ke

public:
    void input(int v, int e)
    {
        for (int i = 0; i < v; i++)
        {
            string vertex;
            cin >> vertex;
            adjList[vertex];
            names.push_back(vertex);
        }

        for (int i = 0; i < e; i++)
        {
            string x, y;
            cin >> x >> y;
            adjList[x].insert(y);
            adjList[y].insert(x);
        }

        for (int i = 0; i < v; i++)
        {
            util[names[i]] = -1;
        }
        // for (auto vertex : names)
        // {
        //     vertex_sorted.push_back(make_pair(adjList[vertex].size(), vertex));
        // }
        // sort(vertex_sorted.begin(), vertex_sorted.end(), Compare());
        // for (int i = 0; i < names.size(); i++)
        // {
        //     names[i] = vertex_sorted[i].second;
        // }
    }

    void solve()
    {
        bool check = false;
        // string x;
        // cin >> x;
        map<string, set<string>> temp; // save adjacent vertex
        for (auto x : names)
        {
            for (auto y : names)
            {
                if (y != x)
                {
                    if (adjList[x].count(y) || adjList[y].count(x))
                    {
                        temp[x].insert(y);
                    }
                }
            }
        }
        for (auto vertex : names)
        {
            for (int i = 0; i < 10000; i++)
            {
                bool check = true;
                for (auto adjVertex : temp[vertex])
                {
                    if (i == util[adjVertex])
                    {
                        check = false;
                        break;
                    }
                }
                if (check)
                {
                    util[vertex] = i;
                    break;
                }
            }
        }
        for (auto vertex : names)
        {
            cout << util[vertex] << " ";
        }
    }
};

int main()
{
    int v, e;
    cin >> v >> e;
    Graph a;
    a.input(v, e);
    a.solve();
}