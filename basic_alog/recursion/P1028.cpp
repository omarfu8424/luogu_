#include<iostream>
#include<unordered_map>

using ll = long long;
using namespace std;

unordered_map<int, ll> memo;
ll count_array(int n);

int main(){
    int n;  cin >> n;
    memo[1] = 1;
    cout << count_array(n);
    return 0;
}

ll count_array(int n){
    if(n == 1)  return 1;
    
    if(memo.find(n) != memo.end()){
        return memo[n];
    }

    ll res = 0;
    if((n&1) == 1)  res = count_array(n-1);
    else    res = count_array(n-1) + count_array(n >> 1);

    memo[n] = res;
    return res;
}