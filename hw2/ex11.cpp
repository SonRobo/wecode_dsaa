#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
set<string> yy;
set<string> mm;
set<string> dd;
// void output(string num)
// {
//     cout << num << " ";
// }
void y_backtrack(int solved, string num)
{
    if (solved == 4)
    {
        // output(num);
        yy.insert(num);
        return;
    }
    for (int i = solved; i < 4; i++)
    {
        swap(num[i], num[solved]);
        y_backtrack(solved + 1, num);
        swap(num[i], num[solved]);
    }
}

void m_backtrack(int solved, string num)
{
    if (solved == 2)
    {
        // output(num);
        mm.insert(num);
        return;
    }
    for (int i = solved; i < 2; i++)
    {
        swap(num[i], num[solved]);
        m_backtrack(solved + 1, num);
        swap(num[i], num[solved]);
    }
}

void d_backtrack(int solved, string num)
{
    if (solved == 2)
    {
        // output(num);
        dd.insert(num);
        return;
    }
    for (int i = solved; i < 2; i++)
    {
        swap(num[i], num[solved]);
        d_backtrack(solved + 1, num);
        swap(num[i], num[solved]);
    }
}

int main()
{
    string y, m, d;
    cin >> y >> m >> d;
    // cout << "----------" << endl;
    // cout << y << "-" << m << "-" << d << endl;

    sort(y.begin(), y.end());

    sort(m.begin(), m.end());

    sort(d.begin(), d.end());

    // cout << y << "-" << m << "-" << d << endl;
    y_backtrack(0, y);
    m_backtrack(0, m);
    d_backtrack(0, d);

    int n = yy.size() * mm.size() * dd.size();
    cout << n << endl;
    for (auto year : yy)
    {
        for (auto month : mm)
        {
            for (auto day : dd)
            {
                cout << year << " " << month << " " << day << endl;
            }
        }
    }
}