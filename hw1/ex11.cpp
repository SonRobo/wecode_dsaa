#include <bits/stdc++.h>
using namespace std;

vector<int> optimal_sol;
int optimal_time = 1000000;

void backtrack(int solved, vector<int> job, vector<int> &machine, vector<int> &sol)
{
    if (solved == job.size())
    {
        int max_time = machine[0];
        for (int i = 1; i < machine.size(); i++)
        {
            if (machine[i] > max_time)
            {
                max_time = machine[i];
            }
        }
        if (max_time < optimal_time)
        {
            optimal_time = max_time;
            optimal_sol = sol;
        }
    }
    else
    {
        for (int i = 0; i < machine.size(); i++)
        {
            machine[i] += job[solved];
            sol[solved] = i;
            if (machine[i] < optimal_time)
            {
                backtrack(solved + 1, job, machine, sol);
            }
            machine[i] -= job[solved];
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> job(n);
    vector<int> machine(m, 0);
    vector<int> sol(n);
    for (int i = 0; i < n; i++)
    {
        cin >> job[i];
    }
    backtrack(0, job, machine, sol);
    for (int i : optimal_sol)
    {
        cout << i << ' ';
    }
    return 0;
}