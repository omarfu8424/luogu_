#include <iostream>
#include <cstring>

using namespace std;
int main(){
    int D, I;
    while(cin >> D >> I){
        int k = 1;
        for(int i = 0; i < D-1; ++i){
            if(I%2 == 1){
                k = 2*k;    //go left
                I = (I+1)/2;//be the (I+1)/2 th ball in the left subtree
            }
            else{
                k = 2*k+1;  //go right
                I = I/2;    //be the I/2 th ball in the right subtree
            }
            
        }
        printf("%d\n", k);
    }
    return 0;
}