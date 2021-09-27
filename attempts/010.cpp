#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int n, q;
    cin >> n;
    vector<int> class1_num, class1_cumsum, class2_num, class2_cumsum;
    int class1_sum = 0;
    int class2_sum = 0;
    class1_num.push_back(-1);
    class1_cumsum.push_back(0);
    class2_num.push_back(-1);
    class2_cumsum.push_back(0);
    for(int i=0;i<n;++i){
        int c, p;
        cin >> c >> p;
        if(c == 1){
            class1_num.push_back(i+1);
            class1_sum += p;
            class1_cumsum.push_back(class1_sum);
        }else{
            class2_num.push_back(i+1);
            class2_sum += p;
            class2_cumsum.push_back(class2_sum);
        }
    }
    class1_num.push_back(1000000);
    class1_cumsum.push_back(class1_sum);
    class2_num.push_back(1000000);
    class2_cumsum.push_back(class2_sum);

    cin >> q;
    for(int i=0;i<q;++i){
        int l, r;
        cin >> l >> r;
        int index_l = lower_bound(class1_num.begin(), class1_num.end(), l) - class1_num.begin() - 1;
        int index_r = upper_bound(class1_num.begin(), class1_num.end(), r) - class1_num.begin() - 1;

        cout << class1_cumsum[index_r] - class1_cumsum[index_l] << " ";

        index_l = lower_bound(class2_num.begin(), class2_num.end(), l) - class2_num.begin() - 1;
        index_r = upper_bound(class2_num.begin(), class2_num.end(), r) - class2_num.begin() - 1;
        cout << class2_cumsum[index_r] - class2_cumsum[index_l] << endl;
    }
}