#include<iostream>
using namespace std;

int main(){
    string s;
    int n;
    cin >> s >> n;
    if(n >= (int)s.size()){
        cout << 0;
        return 0;
    }

    string num;
    for(char c: s){
        while(n>0 && !num.empty() && num.back()>c){
            num.pop_back();
            n--;
        }
        num.push_back(c);
    }
    while(n>0 && !num.empty()){
        num.pop_back();
        n--;
    }

    int i = 0;
    while (i < (int)num.size() - 1 && num[i] == '0') i++;
    cout << num.substr(i);
    return 0;

}