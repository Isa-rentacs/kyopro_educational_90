#include <iostream>

using namespace std;

int r[2001] = {};
int c[2001] = {};
int in[2001][2001] = {};


int main(){
    int h, w;
    cin >> h >> w;
    int tmp = 0;
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            cin >> tmp;
            r[i] += tmp;
            c[j] += tmp;
            in[i][j] = tmp;
        }
    }

    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j)
        {
            cout << r[i] + c[j] - in[i][j];
            if(j!=w-1){
                cout << " ";
            }
        }
        cout << endl;
    }
}