#include <iostream>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int a[n] = {}, b[n] = {};
    for(int i=0;i<n;++i){
        cin >> a[i];
    }

    for(int i=0;i<n;++i){
        cin >> b[i];
    }

    int diff = 0;
    for(int i=0;i<n;++i){
        diff += abs(a[i] - b[i]);
    }

    if(diff <= k && (diff % 2) == (k % 2)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}