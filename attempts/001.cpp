#include <iostream>

using namespace std;

int main(){
    int n, l, k;
    cin >> n >> l >> k;
    int pos[n] = {};

    for (int i=0;i<n;++i){
        cin >> pos[i];
    }

    int left = 0;
    int right = (int)1e+9;
    while(right - left > 1){
        int mid = (right + left) / 2;
        int possible_cut_place = 0;
        int length_begin = 0;
        for(int i=0;i<n;++i){
            if(pos[i] - length_begin >= mid){
                possible_cut_place++;
                length_begin = pos[i];
            }
        }
        if(l - length_begin < mid)
        {
            possible_cut_place--;
        }

        if(possible_cut_place >= k)
        {
            left = mid;
        }else{
            right = mid;
        }
    }
    cout << left << endl;
}