#include <string>
#include <iostream>
#include <vector>
using namespace std;

void dfs(int length, int depth, vector<int> &hist)
{
    if(depth < 0) return;
    if(depth > (length / 2)) return;

    if(hist.size() == length){
        if(depth != 0) return;
        for(const int &i : hist){
            cout << (i==0 ? "(" : ")");
        }
        cout << endl;
        return;
    }

    hist.push_back(0);
    dfs(length, depth + 1, hist);
    hist.pop_back();

    hist.push_back(1);
    dfs(length, depth - 1, hist);
    hist.pop_back();
}

int main(void){
    int n;
    cin >> n;
    if((n%2)==1)
    {
        return 0;
    }
    int depth = n/2;
    vector<int> vec;
//    vec.push_back(0);
    dfs(n, 0, vec);
}