#include<iostream>
#include<map>
using namespace std;
using ll = long long;



int main(){
    int n;  cin >> n;
    ll c; cin >> c;
    map<ll, ll> m;
    for(int i=0; i<n; ++i){
        ll x; cin >> x;
        m[x]++;
    }

    ll cnt = 0;
    for(auto& i: m){
        ll b = i.first;
        if(m.count(b+c)){
            cnt += i.second * m[b+c];
        }
    }
    cout << cnt;
    return 0;
}