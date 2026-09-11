#include<iostream>
#include<string>
#include<vector>
#include<memory>

using namespace std;

struct Node{
    string s_;
    int freq_;
    unique_ptr<Node> left_;
    unique_ptr<Node> right_;

    Node(string s, int f): s_(s), freq_(f), left_(nullptr), right_(nullptr){}
     
};
