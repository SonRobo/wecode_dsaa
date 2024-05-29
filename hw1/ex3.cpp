#include <iostream>
using namespace std;

int n;
int s[10];
bool used[10] = {false};

void output()
{
    for (int i = 1; i <= n; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}

void backtrack(int solved)
{
    if (solved == n + 1)
    {
        output();
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
        {
            s[solved] = i;
            used[i] = true;
            backtrack(solved + 1);

            used[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    backtrack(1);
}