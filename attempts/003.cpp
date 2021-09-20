#include <iostream>
#include <vector>
#include <deque>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>());

    for(int i=0;i<n-1;++i){
        int a, b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    // DFS from 0
    bool visited[n] = {};
    visited[0] = true;
    int max_depth = 0;
    int edge_node = 0;
    deque<pair<int,int>> q;
    q.push_back(make_pair(0, 0));
    while(!q.empty()){
        pair<int,int> current_node = q.front();
        q.pop_front();
        if(current_node.second > max_depth){
            edge_node = current_node.first;
            max_depth = current_node.second;
        }
        for(auto& next: edges[current_node.first]){
            if(!visited[next]){
                visited[next] = true;
                q.push_back(make_pair(next, current_node.second + 1));
            }
        }
    }

    q.push_back(make_pair(edge_node, 0));
    fill(visited, visited + n, 0);
    max_depth = 0;
    while(!q.empty()){
        pair<int,int> current_node = q.front();
        q.pop_front();
        if(current_node.second > max_depth){
            edge_node = current_node.first;
            max_depth = current_node.second;
        }
        for(auto& next: edges[current_node.first]){
            if(!visited[next]){
                visited[next] = true;
                q.push_back(make_pair(next, current_node.second + 1));
            }
        }
    }

    cout << max_depth + 1 << endl;
}