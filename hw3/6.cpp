#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binary_search(const vector<pair<pair<int, int>, int>> &subject, int i)
{
    int l = 0, r = i - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (subject[mid].first.second < subject[i].first.first)
        {
            if (mid + 1 <= r && subject[mid + 1].first.second < subject[i].first.first)
            {
                l = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}

long long solve(const vector<pair<pair<int, int>, int>> &subject, int n)
{
    vector<long long> f(n);
    vector<pair<pair<int, int>, int>> sorted_subject = subject;
    sort(sorted_subject.begin(), sorted_subject.end(), [](const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b)
         { return a.first.second < b.first.second; });
    f[0] = sorted_subject[0].second;

    for (int i = 1; i < n; i++)
    {
        long long sum = sorted_subject[i].second;
        int idx = binary_search(sorted_subject, i);
        if (idx != -1)
        {
            sum += f[idx];
        }
        f[i] = max(sum, f[i - 1]);
    }
    return f[n - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> subject(n);
    for (int i = 0; i < n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        subject[i] = make_pair(make_pair(a, b), c);
    }
    cout << solve(subject, n) << endl;
    return 0;
}