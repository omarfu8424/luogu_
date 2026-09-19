#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using ll = long long;
using namespace std;


void read(string& num){
    char digit = getchar();
    while(digit>'9' || digit<'0')   digit = getchar();
    while(digit<='9' && digit>='0'){
        num.push_back(digit);
        digit = getchar();
    }
}

bool cmp(const string& a, const string& b){
    return a+b>b+a;
}

int main(){
    int n; scanf("%d", &n);
    vector<string> seg(n);
    for(int i=0; i<n; ++i){
        read(seg[i]);
    }
    sort(seg.begin(), seg.end(), cmp);
    for(auto& i: seg){
        cout << i;
    }

}