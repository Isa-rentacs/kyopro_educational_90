#include <iostream>
#include <string>
using namespace std;

int table[26][100001];

int main(){
    string s;
    int n, k;
    cin >> n >> k >> s;

    for(int i=0;i<26;++i){
        for(int j=0;j<100001;++j){
            table[i][j] = 1 << 30;
        }
    }

    for(int i=s.length()-1;i>=0;--i){
        for(int j=0;j<26;++j){
            if((s[i] - 'a') == j){
                table[j][i] = i;
            }else{
                table[j][i] = table[j][i+1];
            }
        }
    }

    string ans = "";
    int current_pos = 0;
    for(int i=0;i<k;++i){
        for(int j=0;j<26;++j){
            if(table[j][current_pos] + (k-i) <= s.length()){
                ans += ('a' + j);
                current_pos = table[j][current_pos] + 1;
                break;
            }
        }
    }
    cout << ans << endl;
}