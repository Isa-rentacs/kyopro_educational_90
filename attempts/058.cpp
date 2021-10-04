#include <iostream>

using namespace std;

int next_table[64][100000];

int calc(int n){
    int tmp = n;
    int a[5] = {};
    a[0] = n / 10000;
    n -= a[0] * 10000;
    a[1] = n / 1000;
    n -= a[1] * 1000;
    a[2] = n / 100;
    n -= a[2] * 100;
    a[3] = n / 10;
    n -= a[3] * 10;
    a[4] = n;

    return (tmp + a[0] + a[1] + a[2] + a[3] + a[4]) % 100000;
}

int main(){
    int n;
    unsigned long long k;
    for(int i=0;i<100000;++i){
        next_table[0][i] = calc(i);
    }

    for(int j=1;j<64;++j){
        for(int i=0;i<100000;++i){
            next_table[j][i] = next_table[j-1][next_table[j-1][i]];
        }
    }
    cin >> n >> k;

    int current = n;
    for(int i=0;i<64;++i){
        if((k & (1ull << i))){
            current = next_table[i][current];
        }
    }
    cout << current << endl;
}