#include <iostream>
using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    long long cnt = 0;
    for(int i = x; i <= y; ++i){
        cnt += i/z;
    }
    cout << cnt;
}