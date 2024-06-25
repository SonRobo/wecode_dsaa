#include <iostream>
using namespace std;
#define MAX 1000000

int arr[MAX];
long long save[MAX]; // save sum from 0 to i

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        save[i] = save[i - 1] + arr[i];
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << save[b] - save[a - 1] << "\n";
    }
}