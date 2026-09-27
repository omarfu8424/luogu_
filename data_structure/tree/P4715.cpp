#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int country;
    int power;
};

bool cmp(const node& a, const node& b){
    return a.power < b.power;
}

int main(){
    int n; cin >> n;
    vector<node> v(1<<n);
    int index = 1;
    for(auto& i: v){
        i.country = index++;
        cin >> i.power;
    }

    sort(v.begin(), v.end(), cmp);
    cout << v[v.size()/2-1].country;
    return 0;
}