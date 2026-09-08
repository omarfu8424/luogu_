#include<iostream>
#include<algorithm>

using namespace std;

struct exam{
    int start = 0;
    int end = 0;
};

bool cmp(exam a, exam b){
    return (a.end < b.end);
}

int main(){
    int n;  cin >> n;
    exam e[n];
    for(int i = 0; i < n; ++i){
        cin >> e[i].start >> e[i].end;
    }
    sort(e, e+n, cmp);

    int endTime = 0;
    int count = 0;
    for(int i = 0; i < n; ++i){
        if(e[i].start >= endTime){
            count++;
            endTime = e[i].end;
        }
        else    continue;
    }

    cout << count;
    return 0;
}