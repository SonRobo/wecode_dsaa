#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <algorithm>

using namespace std;
vector<vector<int>> sudoku;

bool check(int row, int col, int num)
{
    for (int i = 0; i <= 8; i++)
    {
        if (sudoku[row][i] == num)
        {
            return false;
        }
    }
    for (int i = 0; i <= 8; i++)
    {
        if (sudoku[i][col] == num)
        {
            return false;
        }
    }
    // check each 3x3

    row -= row % 3;
    col -= col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudoku[row + i][col + j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool backtrack(int row, int col)
{
    if (row == 8 && col == 9)
    {
        return true;
    }
    if (col == 9)
    {
        row++;
        col = 0;
    }

    if (sudoku[row][col] > 0)
    {
        return backtrack(row, col + 1);
    }

    for (int i = 1; i <= 9; i++)
    {
        if (check(row, col, i))
        {
            sudoku[row][col] = i;
            if (backtrack(row, col + 1))
            {
                return true;
            }
        }
        sudoku[row][col] = 0;
    }

    return false;
}
int main()
{

    sudoku.resize(9, vector<int>(9, 0));

    for (auto &x : sudoku)
    {
        for (auto &y : x)
        {
            string temp;
            cin >> temp;
            if (temp == "X")
            {
                continue;
            }
            y = stoi(temp);
        }
        cout << endl;
    }

    backtrack(0, 0);
    for (auto x : sudoku)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}