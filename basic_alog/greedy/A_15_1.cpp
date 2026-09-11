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
    vector<int> s(n+1);   //the length of the first stick that we cut from a stick with length (n)
    r[0] = 0;
    for(int i = 1; i <= n; ++i){
        r[i] = -1;
        for(int j = 1; j <= i; ++j){
            if(p[j]+r[i-j] > r[i]){
                r[i] = p[j]+r[i-j];
                s[i] = j;
            }
        }
    }
    cout << r[n] << '\n';
    while (n>0){
        printf("(%d) ", s[n]);
        n -= s[n];
    }
    
    return 0;
}