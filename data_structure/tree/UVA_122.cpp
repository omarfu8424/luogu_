#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include "../../_tool/memoryPool.h"

#define MAXN 256
using namespace std;

struct Node;
char in[MAXN];
Node* root = nullptr;
bool failed = false;
memoryPool<Node, MAXN> pool;

struct Node{
    bool hasValue_ = false;
    int value_ = -1;
    Node* left_ = nullptr;
    Node* right_ = nullptr;

    Node(): hasValue_(false), left_(nullptr), right_(nullptr){}
};
void freeNode(Node* n){
        if(n == nullptr) return;    //reaching leaf-node
        freeNode(n->left_);
        freeNode(n->right_);
        pool.deallocate(n);
    }
void addNode(int value, char* way);
bool readInput(){
    failed = false;
    root = pool.allocate();
    for(;;){
        if(scanf("%s", in) != 1)    return false;
        if(strcmp(in, "()") == 0)    break;
        int value;
        sscanf(in+1, "%d", &value);
        addNode(value, strchr(in, ',')+1);
    }
    return true;
}
bool printTree(vector<int>& ans);

int main(){
    if(readInput() && !failed){
        vector<int> ans;
        if(printTree(ans))
            for(int i : ans)
                printf("%d ", i);
    }
    if(failed)   printf("invalid\n");
    freeNode(root);
    return 0;
}

void addNode(int value, char* way){
    Node* p = root;
    for(int i = 0; way[i] != '\0'; ++i){
        if(way[i] == 'L'){
            if(p->left_ == nullptr){
                p->left_ = new Node();
            }
            p = p->left_;
        }
        else if(way[i] == 'R'){
            if(p->right_ == nullptr){
                p->right_ = new Node();
            }
            p = p->right_;            
        }
    }
    if(p->hasValue_)   failed = true;
    p->value_ = value;
    p->hasValue_ = true;
}
bool printTree(vector<int>& ans){
    queue<Node*> q;
    ans.clear();
    q.push(root);
    while(!q.empty()){
        Node* p = q.front();    q.pop();
        if(!p->hasValue_){
            failed = true;
            return false;
        }
        ans.push_back(p->value_);
        if(p->left_ != nullptr)     q.push(p->left_);
        if(p->right_ != nullptr)    q.push(p->right_);
    }
    return true;
}