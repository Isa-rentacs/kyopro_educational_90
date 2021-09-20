#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, q;
    cin >> n;
    int a[n] = {};
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    sort(a, a+n);
    cin >> q;
    int b;
    for(int i=0;i<q;++i)
    {
        cin >> b;
        if (b >= a[n-1]){
            cout << b - a[n-1] << endl;
        } else if(b <= a[0]){
            cout << a[0] - b << endl;
        } else {
            auto it = lower_bound(a, a+n, b);
            int ans = std::min(abs(b - *(it-1)), abs(*(it) - b));
            cout << ans << endl;
        }
    }
}