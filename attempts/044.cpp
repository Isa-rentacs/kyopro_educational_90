#include <iostream>

using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    int a[n] = {};
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    int base = 0;
    int t, x, y;
    for(int i=0;i<q;++i){
        cin >> t >> x >> y;
        if(t == 1){
            int tmp = a[(base + x - 1) % n];
            a[(base + x - 1) % n] = a[(base + y - 1) % n];
            a[(base + y - 1) % n] = tmp;
        }else if(t == 2){
            base += n - 1;
            base %= n;
        }else{
            cout << a[(base + x - 1) % n] << endl;
        }
    }
}