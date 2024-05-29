#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

class Graph
{
private:
    vector<string> names;                                 // ds ten cac dinh
    unordered_map<string, unordered_set<string>> adjList; // anh xa tu ten -> index

public:
    void myProcess()
    {
        int ops = 1;
        while (ops)
        {
            cin >> ops;
            if (ops == 1) // them dinh
            {
                string vertex;
                cin >> vertex;
                if (adjList.count(vertex))
                {
                    cout << "DUP \n";
                }
                else
                {
                    adjList[vertex];
                    cout << "ADD \n";
                }
            }
            else if (ops == 2) // them canh
            {
                string x, y;
                cin >> x >> y;
                if (!adjList.count(x) || !adjList.count(y))
                {
                    if (!adjList.count(x))
                    {
                        adjList[x];
                    }
                    if (!adjList.count(y))
                    {
                        adjList[y];
                    }
                    adjList[x].insert(y);
                    cout << "ADD2 \n";
                }
                else if (adjList[x].count(y))
                {
                    cout << "DUP2 \n";
                }
                else
                {
                    adjList[x].insert(y);
                    cout << "ADD3 \n";
                }
            }
            else if (ops == 3) // kiem tra ke
            {
                string x, y;
                cin >> x >> y;
                if (!adjList.count(x) || !adjList.count(y))
                {
                    cout << "FALSE \n";
                }
                else
                {
                    if (adjList[x].count(y))
                    {
                        cout << "TRUE \n";
                    }
                    else
                    {
                        cout << "FALSE \n";
                    }
                }
            }
            else if (ops == 4) // so luong dinh ke
            {
                string x;
                cin >> x;
                if (adjList.count(x))
                {
                    cout << adjList[x].size() << endl;
                }
                else
                {
                    cout << "0 \n";
                }
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph G;
    G.myProcess();
    return 0;
}