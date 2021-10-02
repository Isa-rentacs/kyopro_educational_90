#include <iostream>
#include <map>
using namespace std;

int main(){
    int l=0, r=1, n, k;
    cin >> n >> k;
    int a[n] = {};

    map<int, int> counts;

    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    counts[a[0]] = 1;
    int ret = 1;

    while(r < n){
        // cerr << "(" << l << ", " << r << ")" << endl;
        // cerr << counts.size() << endl;
        if(counts.find(a[r]) != counts.end()){
            counts[a[r]]++;
            r++;
        }else{
            int size = counts.size();
            if(size < k){
                counts[a[r]]++;
                r++;
            }else{
                counts[a[l]]--;
                if(counts[a[l]] == 0){
                    counts.erase(a[l]);
                }
                l++;
            }
        }
        ret = max(ret, r - l);
    }
    cout << ret << endl;
}