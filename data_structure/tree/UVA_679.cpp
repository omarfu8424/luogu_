/*
有一棵二叉树，最大深度为 D，且所有叶子的深度都相同。所有结点从上到下从左到
右编号为 1, 2, 3,…, 2D-1。在结点 1 处放一个小球，它会往下落。每个内结点上都有一个开
关，初始全部关闭，当每次有小球落到一个开关上时，状态都会改变。当小球到达一个内
结点时，如果该结点上的开关关闭，则往左走，否则往右走，直到走到叶子结点，(题意是小球经过结点后,结点状态才改变)
一些小球从结点 1 处依次开始下落，最后一个小球将会落到哪里呢？

输入叶子深度 D 和小球个数 I，
输出第 I 个小球最后所在的叶子编号。假设 I 不超过整棵树的叶子个数。D≤20。输入最多包含 1000 组数据。
*/

#include <iostream>
#include <cstring>

using namespace std;
int main(){
    int D, I;
    int flip[1<<20]; //store switching data

    while(cin >> D >> I){
        memset(flip, 0, sizeof(int)*(1<<D));

        int k;
        int size = (1<<D) - 1;

        for(int i = 1; i <= I; ++i){
            k = 1;
            while(true){
                flip[k] = !flip[k];
                if(flip[k] == 1){k = 2*k;}
                else{k = 1+2*k;}
                if(k > size){break;}
            }            
        }
        printf("%d\n", k/2);
    }
    return 0;
}