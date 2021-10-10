#include <iostream>
using namespace std;

int main(){
    int n;
    long long sum = 0;
    cin >> n;
    int a[n] = {};
    for(int i=0;i<n;++i){
        cin >> a[i];
        sum += a[i];
    }
    if(sum % 10 != 0){
        cout << "No" << endl;
        return 0;
    }
    long long target = sum / 10;

    int begin = 0, end = 0;
    long long current = 0;
    bool start = true;
    while(true){
        if(current == target){
            cout << "Yes" << endl;
            break;
        }else if(current < target){
            current += a[end];
            end++;
            end %= n;
        }else if(current > target){
            current -= a[begin];
            begin++;
            begin %= n;
            if(begin == 0){
                cout << "No" << endl;
                break;
            }
        }
    }
}
