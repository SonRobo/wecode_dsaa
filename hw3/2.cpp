#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000000

int arr[MAX];
int len[MAX]; // save the smallest number of sequence has len i
int trace[MAX];
int result[MAX];
int idx[MAX];

int binary_search(int x, int n)
{
    int pos = 0;
    int l = 1;
    int r = n;
    while (l <= r)
    {
        int mid = (r + l) / 2;
        if (len[mid] < x)
        {
            pos = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return pos;
}

int solve(int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int pos = binary_search(arr[i], res);
        len[pos + 1] = arr[i];
        idx[pos + 1] = i;
        trace[i] = pos > 0 ? idx[pos] : -1;
        res = max(res, pos + 1);
    }
    int x = idx[res];
    int l = res;
    while (x >= 0)
    {
        result[l] = arr[x];
        x = trace[x];
        l--;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x = solve(n);
    cout << x << endl;
    for (int i = 1; i <= x; i++)
    {
        cout << result[i] << " ";
    }
}