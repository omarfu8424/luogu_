#pragma once
#include <cstdio>
int read(){
    char digit = getchar();
    int res = 0;
    while(digit>'9' || digit<'0')   digit = getchar();
    while(digit<='9' && digit>='0'){
        res = res*10 + digit-'0';
        digit = getchar();
    }
    return res;
}