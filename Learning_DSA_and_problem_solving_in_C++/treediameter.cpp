#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x):data(x),left(nullptr),right(nullptr){}
};
int diameter(Node* root,int& maxd){
    if(!root) return 0;
    int le = diameter(root->left, maxd);
    int ri = diameter(root->right,maxd);
    if(le+ri > maxd) maxd = le+ri;
    return 1+max(le,ri);
}
int main(){
    int maxd =0;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    diameter(root,maxd);
    cout << maxd << endl;
    return 0;
}