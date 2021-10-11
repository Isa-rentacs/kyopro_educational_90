#include <iostream>
#include <string>
using namespace std;

int main(){
    long long n;
    string s;
    cin >> n >> s;
    long long ans = 0;
    ans = n * (n + 1) / 2;
    long long consequtive_count = 0;
    char current_char = 0;
    for(int i=0;i<n;++i){
        if(i == 0 || s[i] == current_char){
            consequtive_count++;
            current_char = s[i];
        }else{
            ans -= (1 + consequtive_count) * consequtive_count / 2;
            consequtive_count = 1;
            current_char = s[i];
        }
    }
    ans -= (1 + consequtive_count) * consequtive_count / 2;
    cout << ans << endl;
}