#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int visited[1002][1002];
int dx[4] = {1, 0, -1 , 0};
int dy[4] = {0, 1, 0, -1};
int board[1002][1002]; // 0: can't enter

int main(){
    int h, w;
    cin >> h >> w;

    int rs, cs, rt, ct;
    cin >> rs >> cs >> rt >> ct;

    string s;
    for(int i=1;i<=h;++i){
        cin >> s;
        for(int j=1;j<=w;++j){
            if(s[j-1] == '.'){
                board[i][j] = 1;
            }
        }
    }
    deque<pair<pair<int,int>, pair<int,int>>> q;
    // setup initial states
    for(int i=0;i<4;++i){
        if(board[rs+dy[i]][cs+dx[i]]){
            q.push_back(make_pair(make_pair(rs, cs), make_pair(i, 0)));
            visited[rs][cs] = true;
        }
    }

    while(!q.empty()){
        auto state = q.front();
        q.pop_front();
        int current_r = state.first.first;
        int current_c = state.first.second;
        int current_dir = state.second.first;
        int current_turn = state.second.second;
        // cerr << "(" << current_r << ", " << current_c << "), " << current_dir << ", " << current_turn << endl;

        while(board[current_r + dy[current_dir]][current_c + dx[current_dir]]){
            current_r += dy[current_dir];
            current_c += dx[current_dir];
            if(visited[current_r][current_c]){
                continue;
            }
            visited[current_r][current_c] = true;
            if(current_r == rt && current_c == ct){
                cout << current_turn << endl;
                return 0;
            }

            int next_left = (current_dir + 1) % 4;
            int next_left_r = current_r + dy[next_left];
            int next_left_c = current_c + dx[next_left];

            int next_right = (current_dir + 3) % 4;
            int next_right_r = current_r + dy[next_right];
            int next_right_c = current_c + dx[next_right];
            if(board[next_left_r][next_left_c] && !visited[next_left_r][next_left_c]){
                q.emplace_back(
                    make_pair(
                        make_pair(current_r, current_c),
                        make_pair(next_left, current_turn + 1)
                    )
                );
            }
            if(board[next_right_r][next_right_c] && !visited[next_right_r][next_right_c]){
                q.emplace_back(
                    make_pair(
                        make_pair(current_r, current_c),
                        make_pair(next_right, current_turn + 1)
                    )
                );
            }
        }
    }
}

