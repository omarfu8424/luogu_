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
    vector<node> v1(1<<(n-1));
    vector<node> v2(1<<(n-1));
    int index = 1;
    for(auto& i: v1){
        i.country = index++;
        cin >> i.power;
    }
    for(auto& i: v2){
        i.country = index++;
        cin >> i.power;
    }

    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);

    int second = v1.back().power < v2.back().power? v1.back().country: v2.back().country;
    cout << second;
    return 0;
}