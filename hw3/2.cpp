#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000000

int arr[MAX];
int len[MAX]; // save the smallest number of sequence has len i

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
        res = max(res, pos + 1);
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
    cout << solve(n) << endl;
}