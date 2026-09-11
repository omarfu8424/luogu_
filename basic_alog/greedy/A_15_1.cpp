#include<iostream>
#include<vector>


using namespace std;

int main(){
    int n; cin >> n;
    vector<int> p(n+1);
    p[0] = 0;
    for(int i = 1; i <= n; ++i){
        cin >> p[i];
    }
    vector<int> r(n+1);   //the maximum of profit that a stick with length (n) can reach
    r[0] = 0;
    for(int i = 1; i <= n; ++i){
        r[i] = -1;
        for(int j = 1; j <= i; ++j){
            r[i] = r[i]>p[j]+r[i-j] ? r[i] : p[j]+r[i-j];
        }
    }
    cout << r[n];
    return 0;
}