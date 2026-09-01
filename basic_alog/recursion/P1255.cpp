#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using boost::multiprecision::cpp_int;

cpp_int count_stairs(int n);

int main(){
    int n;  cin >> n;
    cpp_int p, pp;
    p = 1;
    pp = 0;
    while (n-- > 0) {
        p = p + pp;
        pp = p - pp;        
    }
    cout << p << '\n';
    return 0;
    
}

cpp_int count_stairs(int n){
    if(n <= 2){return n;}
    
    
    return count_stairs(n-1) + count_stairs(n-2);
}