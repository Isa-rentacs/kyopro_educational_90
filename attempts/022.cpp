#include <iostream>

using namespace std;
#define ull unsigned long long 
ull gcd(ull a, ull b){
    if(a%b == 0){
        return b;
    }else{
        return gcd(b, a%b);
    }
}

int main(){
    ull a,b,c;
    cin >> a >> b >> c;
    ull _gcd = gcd(gcd(a, b), c);
    a /= _gcd;
    b /= _gcd;
    c /= _gcd;
    cout << (ull)(a + b + c - 3) << endl;
}