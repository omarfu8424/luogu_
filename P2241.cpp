#include <iostream>
using namespace std;

int main(){
    int n, m, i, j;
    cin >> n >> m;
    long long sum_t, sum_s, r;
    sum_s = sum_t = r = 0;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            r = (n-i+1)*(m-j+1);
            if(i == j)  sum_s += r;
            else sum_t += r;
        }
    }
    cout << sum_s << " " << sum_t;
    return 0;
}