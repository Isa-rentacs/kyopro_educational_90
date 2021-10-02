#include <iostream>
#include <algorithm>
using namespace std;

int a[1001][1001];
int r[11][11];
int main(){
    int n, m;
    cin >> n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin >> a[i][j];
        }
    }
    cin >> m;
    for(int i=0;i<m;++i){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        r[x][y] = 1;
        r[y][x] = 1;
    }

    int order[n] = {};
    for(int i=0;i<n;++i) order[i] = i;
    int res = 1 << 30;
    do{
        int tmp = 0;
        for(int i=0;i<n;++i){
            if(i != n-1 && r[order[i]][order[i+1]]){
                tmp = 1 << 30;
                break;
            }

            tmp += a[order[i]][i];
        }

        res = min(res, tmp);
    }while(next_permutation(order, order + n));

    cout << (res == (1 << 30) ? -1 : res) << endl;
}