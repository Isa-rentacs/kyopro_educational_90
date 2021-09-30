#include <iostream>

using namespace std;

int val[1002][1002];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;++i){
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        val[lx][ly] += 1;
        val[rx][ly] += -1;
        val[lx][ry] += -1;
        val[rx][ry] += 1; 
    }

    for(int x=0;x<1001;++x){
        int tmp = 0;
        for(int y=0;y<1001;++y){
            tmp += val[x][y];
            val[x][y] = tmp;
        }
    }
    int res[n+1] = {};
    for(int y=0;y<1001;++y){
        int tmp = 0;
        for(int x=0;x<1001;++x){
            tmp += val[x][y];
            val[x][y] = tmp;
            res[val[x][y]]++;
        }
    }

    for(int i=1;i<=n;++i){
        cout << res[i] << endl;
    }    
}