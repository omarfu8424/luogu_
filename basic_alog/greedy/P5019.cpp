#include<iostream>
using namespace std;
int depth[100001];
int main(){
    int n = 0;  cin >> n;
    int res = 0;
    for(int i=1; i<=n; ++i){
        cin>>depth[i];
        if(depth[i]>depth[i-1])
            res += depth[i]-depth[i-1];    
    }
    cout << res;
    return 0;
}