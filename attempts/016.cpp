#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long 

int main(){
    ll n, a[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    sort(a, a+3);
    ll ret = 1 << 30;
    for(int i=0;i<=9999;++i){
        ll base = i * a[2];
        ll remain = n - base;
        if(remain < 0){
            break;
        }else if(remain == 0){
            ret = std::min(ret, (ll)i);
        }else{
            for(int j=0;j<=9999;++j){
                ll small_remain = remain - j * a[0];
                if(small_remain < 0) break;
                if((small_remain % a[1]) == 0){
                    ret = std::min(ret, (ll)i + j + small_remain / a[1]);
                }
            }
        }
    }
    cout << ret << endl;
}