#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> jobs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].first;
        jobs[i].second = i;
    }
    sort(jobs.begin(), jobs.end());
    reverse(jobs.begin(), jobs.end());
    vector<int> sol(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mintime;
    for (int i = 0; i < m; i++)
    {
        mintime.push({0, i});
    }
    for (auto &job : jobs)
    {
        auto [time, machine] = mintime.top();
        mintime.pop();
        sol[job.second] = machine;
        mintime.push({time + job.first, machine});
    }
    for (auto &x : sol)
    {
        cout << x << ' ';
    }
    return 0;
}
