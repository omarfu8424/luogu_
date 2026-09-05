#include <iostream>

using namespace std;
using ll = long long;

ll f[20][20];   //f[i][j]表示输入序列中还有i个元素未入栈，栈中有j个元素时的进出方案数
int main(){
    int n;  cin >> n;
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j <= n; ++j){
            if(i == 0)  f[i][j] = 1;     //所有元素都已入栈（输入序列已空），此时只有一种进出方案，即全部pop出去
            else if(j == 0) f[i][j] = f[i-1][j+1];  //栈空了，此时的进出方案等于可以push的方案数
            else    f[i][j] = f[i-1][j+1] + f[i][j-1];  //可以push和pop，二者相加
        }
    }
    cout << f[n][0];
    return 0;
}