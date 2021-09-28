#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double get_angle(int x, int y, int l, int t, int e){
    int remain = e % t;
    double rad = 2 * M_PI * (remain * 1.0 / t);
    double cosine = cos(rad) * l / 2;
    double beta = abs(cosine - (l / 2));

    double sine = sin(rad) * l / 2;
    double alpha = sqrt(pow(y - sine * -1, 2) + pow(x, 2));

    return atan(beta / alpha);

}

int main(){
    int t, l, x, y, q;
    cin >> t >> l >> x >> y >> q;
    for(int i=0;i<q;++i){
        int e;
        cin >> e;
        printf("%.10lf\n", get_angle(x, y, l, t, e) / (2 * M_PI) * 360);
    }
}