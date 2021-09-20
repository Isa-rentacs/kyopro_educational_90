#include <iostream>

using namespace std;

int main(){
    int n, b, k;
    cin >> n >> b >> k;
    int c[k] = {};
    int dp[2][b] = {};
    int prev = 0;
    int next = 1;
    for(int i=0;i<k;++i){
        cin >> c[i];
        dp[prev][c[i] % b] = 1;
    }

    
    for(int i=1;i<=17;++i){

    }
}