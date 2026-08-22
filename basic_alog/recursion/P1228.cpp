#include<iostream>
#include<vector>
using namespace std;

void carpet_1(std::vector<std::vector<int>>& m, int px, int py){
    m[px+1][py]   = 1;
    m[px+1][py+1] = 1;
    m[px][py+1]   = 1;
    printf("%d %d 1\n", px+1, py+1);
}

void carpet(std::vector<std::vector<int>>& m, int x1, int y1, int x2, int y2, int px, int py){  //[x1,x2)x[y1,y2)
    if(x1 == x2 && y1 == y2)    return;

    int mid_x = (x1+x2)>>1;
    int mid_y = (y1+y2)>>1;

    if(px < mid_x && py < mid_y){
        carpet_1(m, mid_x, mid_y);
        carpet(m, x1, mid_y, mid_x, y2, mid_x-1, mid_y);
        carpet(m, mid_x, mid_y, x2, y2, mid_x, mid_y);
        carpet(m, mid_x, y1, x2, mid_y, mid_x, mid_y-1);
    }
      
}

int main(){
    int _n;    cin >> _n;
    int _x, _y;   cin >> _x >> _y;
    
    int x = _x - 1;
    int y = _y - 1;
    int n = 1 << _n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    matrix[x][y] = 10;

    carpet(matrix, 0, 0, n, n, x, y);


    // for(int i=0; i<n; ++i)
    //     for(int j=0; j<n; ++j){
    //        cout << matrix[i][j] << " ";
    //        if(j == n-1) cout << endl;
    //     }
    return 0;
}