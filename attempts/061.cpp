#include <iostream>
#include <queue>

using namespace std;

int main(){
    deque<int> deque;
    int q;
    cin >> q;
    for(int i=0;i<q;++i){
        int t, x;
        cin >> t >> x;
        if(t == 1){
            deque.push_front(x);
        }else if(t==2){
            deque.push_back(x);
        }else{
            cout << deque[x-1] << endl;
        }
    }
}