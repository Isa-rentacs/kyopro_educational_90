#include <iostream>
#include <vector>

using namespace std;

long long mod_a[46];
long long mod_b[46];
long long mod_c[46];

long long dfs(vector<int> &states){
    if(states.size() == 2){
        int remain = 46 - states[0] - states[1];
        if(remain < 0) remain += 46;
        remain %= 46;
        return mod_a[states[0]] * mod_b[states[1]] * mod_c[remain];
    } else {
        long long ret = 0;
        for(int i=0;i<46;++i){
            states.push_back(i);
            ret += dfs(states);
            states.pop_back();
        }
        return ret;
    }
}

int main(){
    int n, tmp;
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> tmp;
        mod_a[tmp % 46]++;
    }
    for(int i=0;i<n;++i){
        cin >> tmp;
        mod_b[tmp % 46]++;
    }
    for(int i=0;i<n;++i){
        cin >> tmp;
        mod_c[tmp % 46]++;
    }
    vector<int> states;

    cout << dfs(states) << endl;

}