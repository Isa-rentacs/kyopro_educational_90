#include <iostream>

using namespace std;

int main(){
    long long a, b, c;
    cin >> a >> b >> c;
    long long c_to_b = 1;
    for(int i=0;i<b;++i){
        c_to_b *= c;
    }

    cout << (a < c_to_b ? "Yes" : "No") << endl;
}