#include <iostream>

using namespace std;
int a[101][101];
int b[101][101];
int c[101][101];
int main(){
    int h, w;
    cin >> h >> w;

    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            cin >> a[i][j];
        }
    }

    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            cin >> b[i][j];
            c[i][j] = b[i][j] - a[i][j];
        }
    }
    long long ans = 0;
    bool impossible = false;
    for(int i=0;i<h-1;++i){
        for(int j=0;j<w-1;++j){
            if(c[i][j] != 0){
                ans += abs(c[i][j]);
                c[i+1][j] -= c[i][j];
                c[i][j+1] -= c[i][j];
                c[i+1][j+1] -= c[i][j];
                c[i][j] = 0;
            }
        }
    }
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            if(c[i][j] != 0){
                impossible = true;
            }
        }
    }

    cout << (impossible ? "No" : "Yes") << endl;
    if(!impossible){
        cout << ans << endl;
    }
}