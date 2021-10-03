#include <iostream>

using namespace std;

#define MOD 1000000007

unsigned int dp[100011];

int main(){
    int k;
    cin >> k;
    dp[0] = 1;

    for(int i=0;i<k;++i){
        for(int j=1;j<=9;++j){
            dp[i+j] += dp[i];
            dp[i+j] %= MOD;
        }
    }

    cout << (k % 9 == 0 ? dp[k] : 0) << endl;
}