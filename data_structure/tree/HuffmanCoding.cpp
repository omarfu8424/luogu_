#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include "../../_tool/memoryPool.h"

#define MAXN 2000
using namespace std;

struct Node;
struct cmp;
memoryPool<Node, MAXN> pool;
Node* root = nullptr;
vector<Node*> order;
int n = 0;

struct Node{
    string s_;
    string code_;
    long long freq_;
    Node* left_ = nullptr;
    Node* right_ = nullptr;
    Node(): s_(""), code_(""), freq_(0), left_(nullptr), right_(nullptr){}
};
struct cmp{
    bool operator()(const Node* a, const Node* b) const {
        return a->freq_ > b->freq_;
    }
};
priority_queue<Node*, vector<Node*>, cmp> pq;
bool readInput();
bool createTree();
void dfs(Node* cur, string& code);
void encode();

int main(){
    if(readInput() && createTree()){
        encode();
    }
    return 0;
}

bool readInput(){
    cin >> n;   if(n < 1) return false;

    for(int i = 0; i < n; ++i){
        Node* p = pool.allocate();  new(p) Node();
        cin >> p->s_ >> p->freq_;
        pq.push(p);
        order.push_back(p);
    }
    return true;
}

bool createTree(){
    while(pq.size() > 1){
        Node* l = pq.top();    pq.pop();
        Node* r = pq.top();    pq.pop();
        Node* parent = pool.allocate();
        if(parent == nullptr)   return false;
        new(parent) Node();
        parent->freq_ = l->freq_+r->freq_;
        parent->left_ = l;
        parent->right_ = r;
        pq.push(parent);
    }
    root = pq.top();
    return true;
}

void dfs(Node* cur, const string& code){
    if(cur == nullptr)  return;
    if(!cur->left_ && !cur->right_){    //reaching leaf
        cur->code_ = order.size()==1? "0": code;
    }
    dfs(cur->left_, code + "0");
    dfs(cur->right_, code + "1");
}
void encode(){
    dfs(root, "");
    for(int i = 0; i < order.size(); ++i){
        cout << order[i]->s_ << " " << order[i]->code_ << '\n';
    }
}