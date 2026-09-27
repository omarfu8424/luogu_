#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main(){
    int _h, _w;
    cin >> _h >> _w;

    ll cnt = 0;
    int m[_h][_w];
    for(int i = 0; i < _h; ++i){
        for(int j = 0; j < _w; ++j){
            cin >> m[i][j];
            if(j>0 && m[i][j] == m[i][j-1]){
                cnt++;
            }
        }
    }
    for(int j = 0; j < _w; ++j){
        for(int i = 0; i < _h; ++i){
            if(i>0 && m[i][j] == m[i-1][j]){
                cnt++;
            }
        }
    }

    for(int i = 0; i < _h; ++i){
        for(int j = 0; j < _w; ++j){
            for(int num = 1; num < 4; ++num){
                int ori = m[i][j];
                if(num != m[i][j]){
                    m[i][j] = num;
                    ll cnt_ = 0;
                    for(int i = 0; i < _h; ++i){
                        for(int j = 0; j < _w; ++j){
                            if(j>0 && m[i][j] == m[i][j-1]){
                                cnt_++;
                            }
                        }
                    }
                    for(int j = 0; j < _w; ++j){
                        for(int i = 0; i < _h; ++i){
                            if(i>0 && m[i][j] == m[i-1][j]){
                                cnt_++;
                            }
                        }
                    }
                    cnt = cnt_>cnt? cnt_: cnt;
                }
                m[i][j] = ori;
            }
        }
    }
    cout << cnt;
    return 0;
}