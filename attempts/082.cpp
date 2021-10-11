#include <iostream>
#define MOD 1000000007
using namespace std;
#define ll long long
#define ull unsigned long long
ll calc(ull x){
    int res = 0;
    ull base = 10;
    int count_digits = 1;
    while(true){
        if(x < base){
            break;
        }
        count_digits++;
        base *= 10;
    }
    ull all_base = 1;
    for(int i=1;i<count_digits;++i){
        ull begin = all_base;
        ull end = all_base * 10ull - 1;
        ull count = (end - begin + 1);
        //ull addendum = ((begin + end) % MOD * count) / 2;
        ull addendum = begin + end;
        if(addendum % 2 == 0){
            addendum /= 2;
        }else{
            count /= 2;
        }
        addendum %= MOD;
        addendum *= count % MOD;
        addendum %= MOD;
        addendum *= i;
        addendum %= MOD;
        res += addendum;
        res %= MOD;
        all_base *= 10;
        // cerr << i << " " << begin << " " << end << endl;
    }
    ll begin = base / 10;
    ll end = x;
    ll count = (end - begin + 1);
    // ll addendum = ((begin + end) % MOD * count) / 2;
    ull addendum = begin + end;
    if(addendum % 2 == 0){
        addendum /= 2;
    }else{
        count /= 2;
    }
    addendum %= MOD;
    addendum *= count % MOD;
    addendum %= MOD;
    addendum *= count_digits;
    addendum %= MOD;

    res += addendum;
    res %= MOD;
    // cerr << count_digits << " " << begin << " " << end << endl;
    // cerr << res << endl;
    return res;
}

int main(){
    ll l, r;
    cin >> l >> r;
    ll res = calc(r) - calc(l - 1);
    cout << (res < 0 ? res + MOD : res) << endl; 

}