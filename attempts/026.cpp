#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<vector<int>> edges(n, vector<int>());
    int visited[n] = {};
    int src, dst;
    for(int i=0;i<n-1;++i){
        cin >> src >> dst;
        edges[src-1].push_back(dst-1);
        edges[dst-1].push_back(src-1);
    }

    for(int i=0;i<n;++i){
        visited[i] = -1;
    }
    deque<int> state;
    state.push_back(0);
    visited[0] = 0;
    vector<int> even;
    vector<int> odd;
    while(!state.empty()){
        int current_node = state.front();
        state.pop_front();
        int current_visited = visited[current_node];
        if(current_visited == 0){
            even.push_back(current_node);
        }else{
            odd.push_back(current_node);
        }
        for(int nxt: edges[current_node]){
            if(visited[nxt] == -1){
                visited[nxt] = 1 - current_visited;
                state.push_back(nxt);
            }
        }
    }
    cerr << even.size() << endl;
    if(even.size() >= n/2){
        for(int i=0;i<n/2;++i){
            cout << even[i] + 1<< " \n"[i==(n/2-1)];
        }
    }else{
        for(int i=0;i<n/2;++i){
            cout << odd[i] + 1 << " \n"[i==(n/2-1)];
        }
    }
}