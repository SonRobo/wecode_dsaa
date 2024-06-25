#include <iostream>
#include <string.h>
using namespace std;

int save_fibo[1000];

int fibo(int n) {
    if(save_fibo[n] != 0) return save_fibo[n];
    return save_fibo[n] = fibo(n-1) + fibo(n-2);

}

// int fibo(int n){
//     if(n <= 1) return 1;
//     return fibo(n-1) + fibo(n-2);
// }
int main() {
    memset(save_fibo, 0, sizeof(save_fibo));
    save_fibo[0] = 1; save_fibo[1] = 1;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << fibo(n) << endl;
    }

    return 0;
}