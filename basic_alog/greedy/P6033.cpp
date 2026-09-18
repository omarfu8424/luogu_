#include<queue>
#include<iostream>
#include<vector>

using namespace std;
using ll = long long;

vector<int> cnt(100001);
inline int read(){
    char digit = getchar();
    int res = 0;
    while(digit>'9' || digit<'0')   digit = getchar();
    while(digit<='9' && digit>='0'){
        res = res*10 + digit-'0';
        digit = getchar();
    }
    return res;
}

ll Min(vector<ll>& q, vector<ll>& m, int& p_q, int& p_m){
    if(p_q!=q.size() && (p_m == m.size() || q[p_q] < m[p_m])){
        return q[p_q++];
    }
    else{
        return m[p_m++];
    }
}
int main(){
    int n = read();
    for(int i=0; i<n; ++i){
        int x = read();
        cnt[x]++;
    }

    vector<ll> q, merge;
    int p_q = 0;
    int p_m = 0;
    ll res = 0;

    for(int i=1; i<100001; ++i){
        if(!cnt[i]) continue;
        else
            while(cnt[i]--)
                q.push_back(i);

    }
    while(q.size()-p_q + merge.size()-p_m > 1){
        ll a = Min(q, merge, p_q, p_m);
        ll b = Min(q, merge, p_q, p_m);
        merge.push_back(a+b);
        res += a+b;
    }
    printf("%lld", res);
    return 0;  

}