#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
using ll = long long;
 

int m,n,p,q;
vector<vector<ll>> board(30, vector<ll>(30));
//board[i][j] contain the number of moving-strategies that allow the chess to move from (i,j) to (m,n)
int h = board.size();
int w = board[0].size();


int power_2(int x){return x * x;}
bool meetHorse(int x, int y){
    if((x == p && y == q) || power_2(x-p) + power_2(y-q) == 5) return true;
    else return false;
}
bool cantGoRight(int x, int y){return (y+1 > n || meetHorse(x, y+1));}
bool cantGoDown(int x, int y){return (x+1 > m || meetHorse(x+1, y));}


int main(){    
    cin >> m >> n >> p >> q; 

    board[m][n] = 1;
    for(int x = m; x >= 0; --x){
        for(int y = n; y >= 0; --y){
            if(x == m && y == n) continue;
            if(meetHorse(x,y)){
                board[x][y] = 0;
                continue;
            }
            if(cantGoRight(x,y) && cantGoDown(x,y)) board[x][y] = 0;
            else if(cantGoDown(x,y))    board[x][y] = board[x][y+1];
            else if(cantGoRight(x,y))   board[x][y] = board[x+1][y];
            else    board[x][y] = board[x+1][y] + board[x][y+1];
        }
    }
    cout << board[0][0] << '\n';

    for(int i = 0; i <= m; ++i){
        for(int j = 0; j <= n; ++j){
            cout << setw(5) << board[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}