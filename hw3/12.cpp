#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solve(string expression)
{
    vector<int> result;
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
        {
            vector<int> left = solve(expression.substr(0, i));
            vector<int> right = solve(expression.substr(i + 1));
            for (int l : left)
            {
                for (int r : right)
                {
                    if (expression[i] == '+')
                    {
                        result.push_back(l + r);
                    }
                    else if (expression[i] == '-')
                    {
                        result.push_back(l - r);
                    }
                    else if (expression[i] == '*')
                    {
                        result.push_back(l * r);
                    }
                }
            }
        }
    }
    if (result.empty())
    {
        result.push_back(stoi(expression));
    }
    return result;
}
int main()
{
    string expression;
    cin >> expression;

    vector<int> result = solve(expression);
    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}