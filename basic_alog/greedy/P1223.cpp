#include <iostream>
#include <algorithm>

using namespace std;

struct people{
    int index = 0;
    int wtime = 0;
};

bool cmp(people a, people b){
    if(b.wtime-a.wtime > 0) return true;
    else return false;
}

int main(){
    int n;  cin >> n;
    people p[n];
    for(int i = 0; i < n; ++i){
        p[i].index = i+1;
        cin >> p[i].wtime;        
    }
    sort(p, p+n, cmp);

    double sum[n+1];
    sum[0] = 0;
    for(int i = 0; i < n; ++i){
        printf("%d ", p[i].index);
        if(i > 0){
            sum[i] = sum[i-1]+p[i-1].wtime;
        }
        sum[n] += sum[i];
    }
    
    printf("\n%.2lf", sum[n]/n);
    return 0;
}