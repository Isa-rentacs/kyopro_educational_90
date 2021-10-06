#include <iostream>

using namespace std;

int main(){
    long long  n, q;
    cin >> n >> q;
    long long  prev, tmp;
    long long  a[n] = {};
    long long  hardness = 0;
    a[0] = 0;
    for(int i=0;i<n;++i){
        cin >> tmp;
        if(i != 0){
            a[i] = tmp - prev;
            hardness += abs(a[i]);
        }
        prev = tmp;
    }
    long long  l, r, v;
    for(int i=0;i<q;++i){
        cin >> l >> r >> v;
        l--;
        r--;
        if(l != 0){
            prev = a[l];
            a[l] += v;
            hardness += abs(a[l]) - abs(prev);
        }
        if(r != n-1){
            prev = a[r+1];
            a[r+1] -= v;
            hardness += abs(a[r+1]) - abs(prev);
        }
        cout << hardness << endl;
    }
}