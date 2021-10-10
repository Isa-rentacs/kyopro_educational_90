#include <iostream>
#define MOD 1000000007ull
using namespace std;

int main(){
    unsigned long long n;
    unsigned long long k;
    cin >> n >> k;
    if(n == 1){
        cout << k << endl;
        return 0;
    }
    unsigned long long res = (k * (k-1)) % MOD;

    unsigned long long base = k-2;
    unsigned long long time = n-2;
    while(time > 0){
        if(time & 1ull){
            res *= base;
            res %= MOD;
        }
        time >>= 1ull;
        base *= base;
        base %= MOD;
    }
    cout << res << endl;
}