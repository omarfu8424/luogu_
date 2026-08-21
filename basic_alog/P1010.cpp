#include <iostream>
#include <string>
using namespace std;

string convert(int n){
    if(n == 0) return "0";
    if(n == 1) return "2(0)";
    
    string res = "";
    bool first = true;
    
    for(int i = 14; i >= 0; i--){   //n <= 2*10^4，最多15位
        if(n & (1 << i)){   //第i位为1时
            if(!first) res += "+";
            first = false;
            
            if(i == 0) res += "2(0)";
            else if(i == 1) res += "2";
            else res += "2(" + convert(i) + ")";    //i>1时，递归调用convert函数
        }
    }
    
    return res;
}

int main(){
    int n;
    cin >> n;
    cout << convert(n) << endl;
    return 0;
}