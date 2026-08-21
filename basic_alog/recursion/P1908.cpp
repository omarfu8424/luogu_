#include <iostream>
#include <vector>
#include <limits>
using namespace std;
using Rank = unsigned int;
using ll = long long;
void inversePair_merge(vector<int>& arr, ll& res, Rank lo, Rank mid, Rank hi){
    vector<int> sub_left(arr.begin()+lo, arr.begin()+mid);    Rank index_left = 0;  //[lo, mid)
    vector<int> sub_right(arr.begin()+mid, arr.begin()+hi);   Rank index_right = 0; //[mid, hi)
    sub_left.insert(sub_left.end(), numeric_limits<int>::max());
    sub_right.insert(sub_right.end(), numeric_limits<int>::max());

    for(Rank i = lo; i < hi; ++i){
        if(sub_left[index_left] <= sub_right[index_right]){
            arr[i] = sub_left[index_left++];
        }else{
            res += mid - lo - index_left;  //统计逆序对数量
            arr[i] = sub_right[index_right++];
        }
    }
}
void count_inversePair(vector<int>& arr, ll& res, Rank lo, Rank hi){
    if(hi - lo < 2) return;
    Rank mid = (hi + lo) >> 1;
    count_inversePair(arr, res, lo, mid);   count_inversePair(arr, res, mid, hi);
    inversePair_merge(arr, res, lo, mid, hi); 
}

int main(){
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        arr.push_back(x);
    }
    ll res = 0;
    count_inversePair(arr, res, 0, arr.size());

    cout << res << endl;
}