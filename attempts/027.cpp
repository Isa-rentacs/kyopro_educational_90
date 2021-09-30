#include <iostream>
#include <set>
using namespace std;

int main(){
    set<string> sset;
    int n;
    string tmp;
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> tmp;
        if(sset.find(tmp) == sset.end()){
            cout << i+1 << endl;
        }
        sset.insert(tmp);
    }
}