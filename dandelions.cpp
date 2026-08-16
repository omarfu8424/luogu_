#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
using ll = long long;

void decode(int x, int n, int &l, int &r){
    l = (l + x - 1)%n + 1;
    r = (r + x - 1)%n + 1;
    if(l > r)   swap(l, r);
}

int main(){
    int n, m, x = 0;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)   cin >> a[i];
    while(m--){
        int l, r;
        cin >> l >> r;
        decode(x, n, l, r);
        unordered_map<ll, int> freq;
        for (int i = l - 1; i < r; ++i) {
            freq[a[i]]++;
        }

        ll ans = a[l - 1];
        int maxCnt = 0;
        
        for (const auto& pair : freq) {
            ll val = pair.first;
            int cnt = pair.second;
            if (cnt > maxCnt || (cnt == maxCnt && val < ans)) {
                maxCnt = cnt;
                ans = val;
            }
        }
        cout << ans << endl;
        x++;
    }
}