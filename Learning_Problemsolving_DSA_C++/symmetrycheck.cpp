#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node*  right;
    Node(int x):data(x) , left(nullptr),right(nullptr){}
};
bool mirror(Node* l , Node* r){
    if(!l && !r) return true;
    if(!l || !r || l->data !=r->data){return false;}
    return(mirror(l->left,r->right) && mirror(l->right , r->left));
}
bool symmetry(Node* root){
    if(!root) return true;
    return mirror(root->left, root->right);
}
int main(){
    Node* root= new Node(1);
    root->left = new Node(5);
    root->right = new Node(5);
    root->left->left = new Node(2);
    root->right->right = new Node(2);
    if(symmetry(root)) cout << "true" << endl;
    else {cout <<"false " << endl;}
    return 0;
}
