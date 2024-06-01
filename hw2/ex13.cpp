#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
vector<vector<int>> board;
int n;

bool check(int row, int col)
{
    int t_row = row;
    int t_col = col;
    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }
    row = t_row;
    col = t_col;
    while (row < n && col >= 0)
    {
        if (board[row][col] == 1)
        {
            return false;
        }
        row++;
        col--;
    }

    return true;
}

bool backtrack(int col)
{
    if (col >= n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (check(i, col))
        {
            board[i][col] = 1;
            if (backtrack(col + 1))
            {
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}

int main()
{
    cin >> n;
    board.resize(n, vector<int>(n, 0));
    backtrack(0);
    for (auto x : board)
    {
        for (auto y : x)
        {
            cout << (y == 1 ? "X" : ".");
        }
        cout << endl;
    }

    return 0;
}