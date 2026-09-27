#include <iostream>
using namespace std;


int n, r;
char board[1000][1000];


int power_2(int x){
    return x*x;
}


int main(){
    cin >> n >> r;
    int p = n/2;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(power_2(i-p)+power_2(j-p) <= power_2(r))
                board[i][j] = '#';
            else
                board[i][j] = '.';
            cout << board[i][j];
        }
        cout << '\n';
    }
    return 0;
}