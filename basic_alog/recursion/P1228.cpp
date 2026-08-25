#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;
namespace Color {
    const std::string RESET = "\033[0m";
    const std::string RED = "\033[41m";      // 红色背景
    const std::string GREEN = "\033[42m";    // 绿色背景
    const std::string YELLOW = "\033[43m";   // 黄色背景
    const std::string BLUE = "\033[44m";     // 蓝色背景
    const std::string WHITE = "\033[47m";    // 白色背景
}

// 获取数字对应的颜色
std::string getColor(int num) {
    switch(num) {
        case 1: return Color::RED;
        case 2: return Color::GREEN;
        case 3: return Color::YELLOW;
        case 4: return Color::BLUE;
        default: return Color::WHITE;
    }
}

void printColoredPattern(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << getColor(val) << "  " << Color::RESET;
        }
        std::cout << std::endl;
    }
}

void carpet_1(std::vector<std::vector<int>>& m, int px, int py){
    m[px+1][py]   = 1;
    m[px+1][py+1] = 1;
    m[px][py+1]   = 1;
    printf("%d %d 1\n", px+2, py+2);
}
void carpet_2(std::vector<std::vector<int>>& m, int px, int py){
    m[px][py-1]   = 2;
    m[px+1][py-1] = 2;
    m[px+1][py]   = 2;
    printf("%d %d 2\n", px+2, py);
}
void carpet_3(std::vector<std::vector<int>>& m, int px, int py){
    m[px-1][py]   = 3;
    m[px-1][py+1] = 3;
    m[px][py+1]   = 3;
    printf("%d %d 3\n", px, py+2);
}
void carpet_4(std::vector<std::vector<int>>& m, int px, int py){
    m[px][py-1]   = 4;
    m[px-1][py-1] = 4;
    m[px-1][py]   = 4;
    printf("%d %d 4\n", px, py);
}


void carpet(std::vector<std::vector<int>>& m, int x1, int y1, int x2, int y2, int px, int py){  //[x1,x2)x[y1,y2)
    if(x2 - x1 == 1 && y2 - y1 == 1)    return;

    int mid_x = (x1+x2)>>1;
    int mid_y = (y1+y2)>>1;

    if(px < mid_x && py < mid_y){   //左上
        carpet_1(m, mid_x-1, mid_y-1);
        carpet(m, x1, y1, mid_x, mid_y, px, py);
        carpet(m, x1, mid_y, mid_x, y2, mid_x-1, mid_y);
        carpet(m, mid_x, mid_y, x2, y2, mid_x, mid_y);
        carpet(m, mid_x, y1, x2, mid_y, mid_x, mid_y-1);
    }
    else if(px < mid_x && py >= mid_y){  //右上
        carpet_2(m, mid_x-1, mid_y);
        carpet(m, x1, mid_y, mid_x, y2, px, py);
        carpet(m, x1, y1, mid_x, mid_y, mid_x-1, mid_y-1);
        carpet(m, mid_x, y1, x2, mid_y, mid_x, mid_y-1);
        carpet(m, mid_x, mid_y, x2, y2, mid_x, mid_y);
    }
    else if(px >= mid_x && py < mid_y){  //左下
        carpet_3(m, mid_x, mid_y-1);
        carpet(m, mid_x, y1, x2, mid_y, px, py);
        carpet(m, x1, y1, mid_x, mid_y, mid_x-1, mid_y-1);
        carpet(m, x1, mid_y, mid_x, y2, mid_x-1, mid_y);
        carpet(m, mid_x, mid_y, x2, y2, mid_x, mid_y);
    }
    else if(px >= mid_x && py >= mid_y){ //右下
        carpet_4(m, mid_x, mid_y);
        carpet(m, mid_x, mid_y, x2, y2, px, py);
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
    carpet(matrix, 0, 0, n, n, x, y);
    // printColoredPattern(matrix);
    
    return 0;
}