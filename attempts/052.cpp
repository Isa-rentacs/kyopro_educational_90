#include <iostream>
#include <numeric>
#define MOD 1000000007
using namespace std;

int main(){
    int n;
    cin >> n;
    int mod[n] = {};
    int tmp[6] = {};
    unsigned long long ret = 1;
    for(int i=0;i<n;++i){
        for(int j=0;j<6;++j){
            cin >> tmp[j];
        }
        ret *= accumulate(tmp, tmp+6, 0);
        ret %= MOD;
    }
    cout << ret << endl;
}