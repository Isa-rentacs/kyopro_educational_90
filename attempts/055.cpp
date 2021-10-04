#include <iostream>
using namespace std;
int main(){
    int n, p, q;
    cin >> n >> p >> q;
    int a[n] = {};
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    int ret = 0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            for(int k=j+1;k<n;++k){
                for(int l=k+1;l<n;++l){
                    for(int m=l+1;m<n;++m){
                        unsigned long long tmp = 1;
                        tmp *= a[i];
                        tmp *= a[j];
                        tmp %= p;
                        tmp *= a[k];
                        tmp %= p;
                        tmp *= a[l];
                        tmp %= p;
                        tmp *= a[m];
                        tmp %= p;
                        if(tmp == q) ret++;
                    }
                }
            }
        }
    }
    cout << ret << endl;
}