#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
int n;
string s;
bool used[1000] = {false};
string num;

void output()
{
    for (int i = 0; i < 2 * n; i++)
    {
        cout << s[i];
    }
    cout << endl;
}

void backtrack(string solved, int open, int close)
{
    if (solved.length() == 2 * n)
    {
        s = solved;
        output();
        return;
    }
    if (open < n)
        backtrack(solved + "(", open + 1, close);
    if (close < open)
        backtrack(solved + ")", open, close + 1);
}

int main()
{
    cin >> n;

    backtrack("", 0, 0);
}