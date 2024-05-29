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
    vector<int> colored;
    set<int> colors;
    map<string, int> util;

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
        }

        for (int i = 0; i < v; i++)
        {
            int color;
            cin >> color;
            colors.insert(color);
            colored.push_back(color);
            util[names[i]] = color;
        }
    }

    int find_color(string x)
    {

        int sol = -1;
        bool check = false;

        set<string> temp; // save adjacent vertex
        for (auto vertex : names)
        {
            if (vertex != x)
            {
                if (adjList[vertex].count(x) || adjList[x].count(vertex))
                {
                    temp.insert(vertex);
                }
            }
        }
        int currentColor = util[x];

        for (auto vertex : temp)
        {
            if (util[vertex] == currentColor)
            {
                check = true;
                break;
            }
        }

        if (!check and currentColor != -1)
        {
            // cout << "TRUE" << endl;
            return -2;
        }
        else
        {
            for (int color : colors)
            {
                if (color != -1)
                {
                    bool trueColor = true;
                    for (auto vertex : temp)
                    {
                        if (util[vertex] == color)
                        {
                            trueColor = false;
                            break;
                        }
                    }
                    if (trueColor)
                    {
                        sol = color;
                        return sol;
                    }
                }
            }

            for (int i = 0; i < 10000; i++)
            {
                bool check = true;
                for (auto vertex : temp)
                {
                    if (util[vertex] == i)
                    {
                        check = false;
                        break;
                    }
                }
                if (check)
                {
                    sol = i;
                    break;
                }
            }
        }

        for (int color : colors)
        {
            bool trueColor = true;
            for (auto vertex : temp)
            {
                if (util[vertex] == color)
                {
                    trueColor = false;
                    break;
                }
            }
            if (trueColor)
            {
                sol = color;
                break;
            }
        }

        if (sol == -1)
        {
            for (int i = 0; i < 10000; i++)
            {
                bool check = true;
                for (auto vertex : temp)
                {
                    if (util[vertex] == i)
                    {
                        check = false;
                        break;
                    }
                }
                if (check)
                {
                    sol = i;
                    break;
                }
            }
        }
        return sol;
    }

    void solve(int n)
    {
        while (n--)
        {
            string x;
            cin >> x;
            int result = find_color(x);
            if (result == -2)
            {
                cout << "TRUE" << endl;
            }
            else
            {
                cout << result << endl;
            }
        }
    }
};

int main()
{
    int v, e, n;
    cin >> v >> e >> n;
    Graph a;
    a.input(v, e);
    a.solve(n);
}