#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
typedef pair<int, int> Pair;
typedef pair<double, pair<int, int>> w_pair;

class cell
{
public:
    int x, y;
    double g, h;

    cell(int x, int y, double g, double h) : x(x), y(y), g(g), h(h) {}
    double f() const
    {
        return g + h;
    }
    bool operator>(const cell &x) const
    {
        return f() > x.f();
    }
};
bool check(int x, int y, int size)
{
    return x >= 0 && y >= 0 && x < size && y < size;
}

double heuristic(int x, int y, Pair dest)
{
    // euclid

    // double dis = (x - dest.first) * (x - dest.first) + (y - dest.second) * (y - dest.second);
    // return sqrt(dis);
    // manhattan

    // int dx = abs(x - dest.first);
    // int dy = abs(y - dest.second);
    // return dx + dy + min(dx, dy);
    // double dis = abs(x - dest.first) + abs(y - dest.second);
    // return dis;
    // another way
    return max(abs(x - dest.first), abs(y - dest.second));
    // return 0;
}

void a_star(vector<vector<int>> map, Pair start, Pair end)
{
    int size = map.size();
    vector<vector<bool>> closed(size, vector<bool>(size, false));
    int cnt = 0;
    vector<vector<int>> g(size, vector<int>(size, 100000));
    priority_queue<cell, vector<cell>, greater<cell>> open;
    g[start.first][start.second] = 0;
    open.push(cell(start.first, start.second, 0, heuristic(start.first, start.second, end)));
    vector<Pair> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    while (!open.empty())
    {
        cell current_cell = open.top();
        open.pop();

        int x = current_cell.x;
        int y = current_cell.y;
        if (closed[x][y])
        {
            continue;
        }
        closed[x][y] = true;
        cnt++;
        // in kq
        if (x == end.first && y == end.second)
        {
            cout << current_cell.g;
            return;
        }
        for (auto it : directions)
        {
            int nx = x + it.first;
            int ny = y + it.second;
            if (check(nx, ny, size) && map[nx][ny] == 0)
            {
                double temp_g = current_cell.g + 1;
                if (temp_g < g[nx][ny])
                {
                    g[nx][ny] = temp_g;
                    double h = heuristic(nx, ny, end);
                    open.push(cell(nx, ny, temp_g, h));
                }
            }
        }
    }
    cout << -1;
}
int main()
{
    int m, n;
    cin >> m >> n;
    Pair player, des;
    cin >> player.first >> player.second >> des.first >> des.second;
    vector<vector<int>> map(m, vector<int>(n));
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    a_star(map, player, des);
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}