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
set<string> date;
// void output(string num)
// {
//     cout << num << " ";
// }
bool check_month(string m)
{
    int month = stoi(m);
    return (month > 0 && month <= 12);
}
bool check_day(string d, string m, string y)
{
    int day = stoi(d);
    int year = stoi(y);
    int month = stoi(m);
    if (year < 1)
    {
        return false;
    }

    if (month == 2)
    {
        if (year % 3328 == 0)
        {
            return (day > 0 && day <= 30);
        }
        if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        {
            return (day > 0 && day <= 29);
        }
        return (day > 0 && day <= 28);
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return (day > 0 && day <= 30);
    }
    return (day > 0 && day <= 31);
}

// bool y_backtrack(int solved, string num)
// {
//     if (solved == 4)
//     {
//         // output(num);
//         if (m_backtrack(0, num.substr(4, 5)))
//         {
//             yy.insert(num);
//         }
//         return true;
//     }
//     for (int i = solved; i < 4; i++)
//     {
//         swap(num[i], num[solved]);
//         y_backtrack(solved + 1, num);
//         swap(num[i], num[solved]);
//     }
// }

// bool m_backtrack(int solved, string num)
// {
//     if (solved == 2)
//     {
//         // output(num);
//         if (check_month(num))
//         {
//             if (d_backtrack(0, num.substr(6, 2)))
//             {
//                 mm.insert(num);
//                 return true;
//             }
//         }
//         return false;
//     }
//     for (int i = solved; i < 2; i++)
//     {
//         swap(num[i], num[solved]);
//         m_backtrack(solved + 1, num);
//         swap(num[i], num[solved]);
//     }
// }

// bool d_backtrack(int solved, string num)
// {
//     if (solved == 2)
//     {
//         // output(num);
//         if (check_day(num))
//         {
//             dd.insert(num);
//             return true;
//         }
//         return false;
//     }
//     for (int i = solved; i < 2; i++)
//     {
//         swap(num[i], num[solved]);
//         d_backtrack(solved + 1, num);
//         swap(num[i], num[solved]);
//     }
// }

void backtrack(int solved, string num)
{
    if (solved == num.length())
    {
        string year = num.substr(0, 4);
        string month = num.substr(4, 2);
        string day = num.substr(6, 2);
        if (check_month(month) && check_day(day, month, year))
        {
            date.insert(year + " " + month + " " + day);
        }
        return;
    }

    for (int i = solved; i < num.length(); i++)
    {
        swap(num[i], num[solved]);
        backtrack(solved + 1, num);
        swap(num[i], num[solved]);
    }
}

int main()
{
    string y, m, d;
    cin >> y >> m >> d;
    // cout << "----------" << endl;
    // cout << y << "-" << m << "-" << d << endl;

    string num = y + m + d;
    backtrack(0, num);
    cout << date.size() << endl;
    for (auto it : date)
    {
        cout << it << endl;
    }
}