#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, k, a, b;
    cin >> n >> k;
    int score[n*2] = {};
    for(int i=0;i<n;++i){
        cin >> a >> b;
        score[i*2] = b;
        score[i*2+1] = a - b;
    }

    sort(score, score + n * 2, greater<int>());
    long long res = 0;
    for(int i=0;i<k;++i){
        res += score[i];
    }

    cout << res << endl;
}