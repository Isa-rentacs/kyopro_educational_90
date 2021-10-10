#include <iostream>
using namespace std;

int main(){
    long long n;
    cin >> n;
    int num_factor = 0;
    long long int dividor = 2;
    long long tmp = n;
    while(dividor * dividor <= n){
        while((tmp % dividor) == 0){
            tmp /= dividor;
            num_factor++;
        }

        dividor++;
    }
    if(tmp != 1) num_factor++;
    long long base = 1;
    for(int i=0;i<50;++i){
        if(num_factor <= base){
            cout << i << endl;
            break;
        }
        base *= 2ll;
    }
}