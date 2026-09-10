#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

long long getMinHeap(queue<int>& q1, queue<int>& q2);
int main(){
    int n;  cin >> n;
    vector<int> mass(n);
    for(int i = 0; i < n; ++i){
        cin >> mass[i];
    }
    sort(mass.begin(), mass.end());
    
    queue<int> q1, q2;
    for(int i : mass){
        q1.push(i);
    }
    
    long long res = 0;
    while(q1.size()+q2.size() > 1){
        int m = getMinHeap(q1, q2);
        int n = getMinHeap(q1, q2);
        res += m+n;
        q2.push(m+n);
    }

    cout << res;

    return 0;
}

long long getMinHeap(queue<int>& q1, queue<int>& q2){
    long long res = 0;
    if(q1.empty()){
        res = q2.front();
        q2.pop();
        return res;
    }
    if(q2.empty()){
        res = q1.front();
        q1.pop();
        return res;
    }
    if(q1.front() < q2.front()){
        res = q1.front();
        q1.pop();
        return res;
    }
    else{
        res = q2.front();
        q2.pop();
        return res;
    }
}