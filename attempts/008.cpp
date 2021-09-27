#include <iostream>
#include <string>
using namespace std;

long long dp[100002][8];
const long long mod = 1000000007;
int main(){
    int n;
    string s;
    string atcoder = "atcoder";
    cin >> n >> s;

    dp[0][0] = 1;
    for(int i=1;i<=(int)s.length();++i){
        dp[i][0] = 1;
        for(int j=1;j<=7;++j){
            if(s[i-1] == atcoder[j-1]){
                dp[i][j] += dp[i-1][j-1] + dp[i-1][j];
                dp[i][j] %= mod;
            }else{
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= mod;
            }
            // cerr << dp[i][j] << " ";
        }
         // cerr << endl;
    }
    cout << dp[(int)s.length()][7] << endl;
}