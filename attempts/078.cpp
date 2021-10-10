#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, m, a, b;;
    cin >> n >> m;
    vector<int> edges[n];

    for(int i=0;i<m;++i){
        cin >> a >> b;
        --a;
        --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int res = 0;
    for(int i=0;i<n;++i){
        sort(edges[i].begin(), edges[i].end());
        if(lower_bound(edges[i].begin(), edges[i].end(), i) - edges[i].begin() == 1){
            res++;
        }
    }
    cout << res << endl;
}