#include <iostream>
#define MOD 1000000007
#define ll long long
using namespace std;

uint dp[2000002];

int main(){
    dp[0] = 1;
    int n, l;
    cin >> n >> l;

    for(int i=0;i<n;++i){
        dp[i+1] += dp[i];
        dp[i+l] += dp[i];
        dp[i+1] %= MOD;
        dp[i+l] %= MOD;
    }

    cout << dp[n] << endl;
}