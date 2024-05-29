#include <iostream>
#include <string>
#include <vector>
using namespace std;

void backtrack(string s, string solved, int dot)
{
    int n = s.size();
    if (n == 0 && dot == 4)
    {
        cout << solved.substr(0, solved.length() - 1);
        cout << endl;
        return;
    }
    if (dot == 4)
        return;
    for (int i = 1; i <= 3; ++i)
    {
        if (n >= i && stoi(s.substr(0, i)) <= 255 && (i == 1 || i == 2 && s[0] != '0' || i == 3 && s[0] != '0' && stoi(s.substr(0, i)) <= 255))
        {
            backtrack(s.substr(i), solved + s.substr(0, i) + '.', dot + 1);
        }
    }
}

int main()
{
    string s;
    cin >> s;
    backtrack(s, "", 0);
    return 0;
}
