#include <iostream>
#include <string>
#include <stack>
#define ull unsigned long long
using namespace std;

ull str_to_oct(string str){
    ull base = 1;
    ull ret = 0;
    for(int i=0;i<str.size();++i){
        ret += (str[str.size() - i - 1] - '0') * base;
        base *= 8;
    }

    return ret;
}

string ull_to_nine(ull num){
    if(num == 0) return "0";
    string ret = "";
    stack<char> st;
    while(num > 0){
        int rem = num % 9;
        st.push(rem == 8 ? '5' : rem + '0');
        num /= 9;
    }
    while(!st.empty()){
        ret.push_back(st.top());
        st.pop();
    }

    return ret;
}

int main(){
    string n;
    int k;
    cin >> n >> k;
    ull val = str_to_oct(n);

    for(int i=0;i<k;++i){
        string next = ull_to_nine(val);
        if(i==k-1){
            cout << next << endl;
        }
        val = str_to_oct(next);
    }
}