#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

void carpet_1(std::vector<std::vector<int>>& m, int px, int py){
    m[px+1][py]   = 1;
    m[px+1][py+1] = 1;
    m[px][py+1]   = 1;
    printf("%d %d 1\n", px+1, py+1);
}
void carpet_2(std::vector<std::vector<int>>& m, int px, int py){
    m[px][py-1]   = 2;
    m[px+1][py-1] = 2;
    m[px+1][py]   = 2;
    printf("%d %d 2\n", px+1, py-1);
}
void carpet_3(std::vector<std::vector<int>>& m, int px, int py){
    m[px-1][py]   = 3;
    m[px-1][py+1] = 3;
    m[px][py+1]   = 3;
    printf("%d %d 3\n", px-1, px+1);
}
void carpet_4(std::vector<std::vector<int>>& m, int px, int py){
    m[px][py-1]   = 4;
    m[px-1][py-1] = 4;
    m[px-1][py]   = 4;
    printf("%d %d 4\n", px-1, py -1);
}


void carpet(std::vector<std::vector<int>>& m, int x1, int y1, int x2, int y2, int px, int py){  //[x1,x2)x[y1,y2)
    if(x2 - x1 ==1 && y2 - y1 == 1)    return;

    int mid_x = (x1+x2)>>1;
    int mid_y = (y1+y2)>>1;

    if(px < mid_x && py < mid_y){   //左上
        carpet_1(m, mid_x-1, mid_y-1);
        carpet(m, x1, mid_y, mid_x, y2, mid_x-1, mid_y);
        carpet(m, mid_x, mid_y, x2, y2, mid_x, mid_y);
        carpet(m, mid_x, y1, x2, mid_y, mid_x, mid_y-1);
    }
    if(px < mid_x && py >= mid_y){  //右上
        carpet_2(m, mid_x-1, mid_y);
        carpet(m, x1, y1, mid_x, mid_y, mid_x-1, mid_y-1);
        carpet(m, mid_x, y1, x2, mid_y, mid_x, mid_y-1);
        carpet(m, mid_x, mid_y, x2, y2, mid_x, mid_y);
    }
    if(px >= mid_x && py < mid_y){  //左下
        carpet_3(m, mid_x, mid_y-1);
        carpet(m, x1, y1, mid_x, mid_y, mid_x-1, mid_y-1);
        carpet(m, x1, mid_y, mid_x, y2, mid_x-1, mid_y);
        carpet(m, mid_x, mid_y, x2, y2, mid_x, mid_y);
    }
    if(px >= mid_x && py >= mid_y){ //右下
        carpet_4(m, mid_x, mid_y);
        carpet(m, mid_x, y1, x2, mid_y, mid_x, mid_y-1);
        carpet(m, x1, y1, mid_x, mid_y, mid_x-1, mid_y-1);
        carpet(m, x1, mid_y, mid_x, y2, mid_x-1, mid_y);
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


    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j){
           cout << setw(3) << matrix[i][j] << " ";
           if(j == n-1) cout << endl;
        }
    return 0;
}