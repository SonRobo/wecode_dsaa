#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, temp;
    cin >> n >> m;
    vector<vector<int>> time(m, vector<int>(n));
    vector<int> machine_time(m, 0);
    vector<int> job(n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            if(temp == -1) 
            {
                temp *= - 100000;
            }
            time[i][j] = temp;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int min_machine = 0;
        for (int j = 1; j < m; j++)
        {
            if (machine_time[j] + time[j][i] < machine_time[min_machine] + time[min_machine][i])
            {
                min_machine = j;
            }
        }
        machine_time[min_machine] += time[min_machine][i];
        job[i] = min_machine;
    }

    for (int i = 0; i < n; i++)
    {
        cout << job[i] << ' ';
    }

    return 0;
}
