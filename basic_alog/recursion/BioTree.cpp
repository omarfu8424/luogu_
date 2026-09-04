/*

    ////
   /\
  /  \
 /\  /\
/\/\/\/\
*/


#include<iostream>
#include<cstring>
using namespace std;
int n;
char a[3000][3000];
int h=1,w=2;
int main(){
	cin>>n;

    //initialize
	memset(a,' ',sizeof(a));
    a[0][0] = '/';
    a[0][1] = '\\';

    //fill
    while(n-- > 1){
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                a[i+h][j] = a[i+h][j+w] = a[i][j];
                a[i][j] = ' ';
            }            
        }

        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                if((i + j == h - 1) || (j - i) == h)
                    a[i][j+h] = a[i+h][j];
                else
                    a[i][j+h] = ' ';
            }
        }

        //update
        w *= 2;
        h *= 2;
    }

    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            cout << a[i][j];
            if(j+1 == w)    cout << '\n';
        }
    }
	return 0;
}

