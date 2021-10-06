#include <iostream>
#include <set>
#include <vector>
#include <map>
using namespace std;
unsigned char table[80001][10001];
int grid[8][10000];
int main(){
    int h, w;
    cin >> h >> w;
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            cin >> grid[i][j];
        }
    }

    for(int i=0;i<w;++i){
        for(int j=0;j<h;++j){
            table[grid[j][i]][i] |= 1 << j;
        }
    }

    int ret = 0;
    for(int i=1;i<(1 << h);++i){
        // i : pattern
        int pattern = i;
        int counter = 0;
        int bit_count = 0;
        vector<int> v;
        map<int, int> m;
        while(pattern > 0){
            if(pattern & 1){
                v.push_back(counter);
                bit_count++;
            }
            counter++;
            pattern >>= 1;
        }

        for(int j=0;j<w;++j){
            int tmp = -1;
            set<int> s;
            for(int k: v){
                s.insert(grid[k][j]);
            }
            if(s.size() == 1){
                m[grid[v[0]][j]]++;
            }
        }

        for(const pair<int,int>&p:m){
//            cerr << p.first << ": " << i << "(" << bit_count << ") * " << p.second << endl;
            ret = max(ret, bit_count * (p.second));
        }
    }

    cout << ret << endl;
}