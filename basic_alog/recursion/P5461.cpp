#include <iostream>
#include <vector>
using namespace std;

void pardon(std::vector<std::vector<int>>& m, int lo_x, int lo_y, int size){
    if(size == 2){
        m[lo_x][lo_y] = 0;
        return;
    }
    int mid = size >> 1;
    for(int i=0; i < mid; ++i)
        for(int j=0; j < mid; ++j)
            m[lo_x+i][lo_y+j] = 0;


    pardon(m, lo_x, lo_y+mid, mid);
    pardon(m, lo_x+mid, lo_y+mid, mid);
    pardon(m, lo_x+mid, lo_y, mid);
}

int main(){
    int num;    cin >> num;
    int n = 1 << num;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 1));
    pardon(matrix, 0, 0, n);
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j){
           cout << matrix[i][j] << " ";
           if(j == n-1) cout << endl;
        }
    return 0;
}