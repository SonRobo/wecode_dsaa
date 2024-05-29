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
    vector<string> origin;

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
        origin = names;
        for (int i = 0; i < v; i++)
        {
            util[names[i]] = -1;
        }
        sort_vertex();
    }
    void sort_vertex()
    {
        vertex_sorted.clear();
        for (auto vertex : names)
        {
            int cnt = 0;
            for (auto x : adjList[vertex])
            {
                if (util[x] != -1)
                {
                    cnt++;
                }
            }
            vertex_sorted.push_back(make_pair(adjList[vertex].size() - cnt, vertex));
        }
        sort(vertex_sorted.begin(), vertex_sorted.end(), Compare());
        for (int i = 0; i < names.size(); i++)
        {
            names[i] = vertex_sorted[i].second;
        }
    }

    void solve()
    {
        // util[names[0]] = 0;
        // string x;
        // cin >> x;
        map<string, set<string>> temp; // save adjacent vertex
        for (auto x : names)
        {
            for (auto y : names)
            {
                if (y != x)
                {
                    if (adjList[x].count(y))
                    {
                        temp[x].insert(y);
                    }
                }
            }
        }

        while (!names.empty())
        {
            string current_vertex = names[0];
            for (int i = 0; i < 10000; i++)
            {
                bool check = true;
                for (auto adjVertex : temp[current_vertex])
                {
                    if (i == util[adjVertex])
                    {
                        check = false;
                        break;
                    }
                }
                if (check)
                {
                    util[current_vertex] = i;
                    break;
                }
            }
            names.erase(names.begin());
            sort_vertex();
        }
        for (auto vertex : origin)
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