#include <iostream>
#include <map>
using namespace std;

class Node{
public:
    Node* parent;
    pair<int,int> pos;

    Node(pair<int,int> pos):parent(nullptr), pos(pos){
        parent = this;
    }

    void set_parent(Node *node){
        parent = node;
    }
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void update(Node *start, Node *new_parent){
    Node* current = start;
    Node* next = nullptr;
    while(1){
        next = current->parent;
        current->parent = new_parent;
        current = next;

        if(current == current->parent){
            current->parent = new_parent;
            break;
        }
    }
}

Node* get_root(Node* start){
    Node* ret = start;
    while(ret->parent != ret){
        ret = ret->parent;
    }

    return ret;
}

Node* board[2002][2002];

int main(){
    int h, w, q;
    cin >> h >> w >> q;
    int t, x, y, xa, ya, xb, yb;
    for(int i=0;i<h+2;++i){
        for(int j=0;j<w+2;++j){
            board[h][w] = nullptr;
        }
    }

    for(int i=0;i<q;++i){
        cin >> t;
        if(t == 1){
            cin >> x >> y;
            board[x][y] = new Node(make_pair(x, y));
            for(int i=0;i<4;++i){
                if(board[x+dx[i]][y+dy[i]] != nullptr){
                    update(board[x+dx[i]][y+dy[i]], board[x][y]);
                }
            }
        }else{
            cin >> xa >> ya >> xb >> yb;
            if(board[xa][ya] != nullptr && 
               board[xb][yb] != nullptr && 
               get_root(board[xa][ya]) == get_root(board[xb][yb])){
                   cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }

}