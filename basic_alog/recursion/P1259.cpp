/*  for n = 7
ooooooo*******--
oooooo--******o*
oooooo******--o*
ooooo--*****o*o*
ooooo*****--o*o*
oooo--****o*o*o*
oooo****--o*o*o*
ooo--***o*o*o*o*
ooo*o**--  *o*o*o*        <--后四行只能如此
o--*o**oo  *o*o*o*
o*o*o*--o  *o*o*o*
--o*o*o*o  *o*o*o*
*/

#include<iostream>
#include<vector>

using namespace std;


void print_chess(vector<char>& arr){
    for(char i : arr)   cout << i;
    cout << '\n';
}

int main(){
    int n;  cin >> n;
    
    string out[4] = {
        "ooo*o**--",
        "o--*o**oo",
        "o*o*o*--o",
        "--o*o*o*o",    
    };
    if(n < 3 || n > 100)   return 0;


    vector<char> arr((n+1) << 1);
    for(int i = 0; i < arr.size(); ++i){
        if(i < n)           arr[i] = 'o';
        else if(i < 2*n)    arr[i] = '*';
        else                arr[i] = '-';
    }
    print_chess(arr);

    int size = 2*n;
    int space = 2*n;
    while(size >= 8){
        arr[space] = arr[size/2 - 1];   arr[size/2 - 1] = '-';
        arr[space+1] = arr[size/2];     arr[size/2] = '-';
        print_chess(arr);

        for(int i = size/2 - 1; i+2 < size; ++i){
            arr[i] = '*';
        }

        if(size != 8){
            arr[size-2] = arr[size-1] = '-';
            print_chess(arr);
        }
        
        size -= 2;
        space = size;
    }

    string tail = "*";
    for(int i = 0; i < n-4; ++i)
        tail += "o*";

    for(int i = 0; i < 4; ++i){
        cout << out[i] << tail << '\n';
    }

    return 0;
}