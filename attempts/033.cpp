#include <iostream>

using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    if(h == 1 || w == 1){
        cout << h * w << endl;
    }else{
        cout << (h / 2 + h % 2) * (w / 2 + w % 2) << endl;
    }
}