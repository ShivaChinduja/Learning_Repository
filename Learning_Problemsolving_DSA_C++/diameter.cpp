#include<iostream>
#include <vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x):data(x), left(nullptr),right(nullptr){}
};
int diameter(Node* root,int& maxd){
    if(!root) return 0;
    int lht = diameter(root->left,maxd);
    int rht = diameter(root->right,maxd);
    if(lht+rht > maxd) maxd = lht+rht;
    return 1+max(lht,rht); 

}

int main(){
    int dia =0;
    Node* root = new Node(1);
    root->left = new Node(8);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(9);
    cout << diameter(root,dia) << endl;
    cout << "diameter" << dia << endl;
    return 0;
}