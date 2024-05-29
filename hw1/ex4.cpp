#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
int n;
string s;
bool used[10000] = {false};
string num;

void output()
{
    for (int i = 0; i < num.length(); i++)
    {
        cout << s[i];
    }
    cout << endl;
}

void backtrack(int solved)
{
    if (solved == num.length())
    {
        output();
        return;
    }
    for (int i = 0; i < num.length(); i++)
    {
        if (!used[int(num[i])])
        {
            s[solved] = num[i];
            used[int(num[i])] = true;
            backtrack(solved + 1);

            used[int(num[i])] = false;
        }
    }
}

int main()
{
    cin >> n;
    num = to_string(n);
    sort(num.begin(), num.end());
    reverse(num.begin(), num.end());
    s = string(num.length(), '0');

    backtrack(0);
}
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
int n;
string s;
bool used[10000] = {false};
string num;

void output()
{
    for (int i = 0; i < num.length(); i++)
    {
        cout << s[i];
    }
    cout << endl;
}

void backtrack(int solved)
{
    if (solved == num.length())
    {
        output();
        return;
    }
    for (int i = 0; i < num.length(); i++)
    {
        if (!used[int(num[i])])
        {
            s[solved] = num[i];
            used[int(num[i])] = true;
            backtrack(solved + 1);

            used[int(num[i])] = false;
        }
    }
}

int main()
{
    cin >> n;
    num = to_string(n);
    sort(num.begin(), num.end());
    reverse(num.begin(), num.end());
    s = string(num.length(), '0');

    backtrack(0);
}