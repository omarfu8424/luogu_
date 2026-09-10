#include<iostream>
#include<algorithm>


using namespace std;

int main(){
    int n;  cin >> n;
    int mass[n];
    for(int i = 0; i < n; ++i){
        cin >> mass[i];
    }
    if(n < 2){cout << 0;  return 0;}
    
    // n >= 2
    sort(mass, mass+n);
    int sum[n+1];
    sum[0] = 1<<30;
    sum[n] = 0;

    for(int i = 0, index = 0; i < n-1;){
        int massOf2 = mass[i]+mass[i+1];
        if(massOf2 <= sum[index]+mass[i]){
            sum[index] = massOf2;
            sum[n] += sum[index];
            i += 2;
            index++;
        }
        else{
            sum[index] = sum[index-1]+mass[i];
            sum[n] += sum[index];
            i++;
            index++;
        }
    }
    cout << sum[n];

    return 0;
}