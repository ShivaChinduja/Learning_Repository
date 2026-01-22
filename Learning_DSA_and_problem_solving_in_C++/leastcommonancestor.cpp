#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x): data(x),left(nullptr), right(nullptr){}
};
Node* lca(Node* root,int x,int y){
    if(!root) return root;
    if(root->data == x || root->data == y) return root;
    Node* leftlca = lca(root->left , x,y);
    Node* rightlca = lca(root->right , x,y);
    if(leftlca && rightlca){
        //ancestor found
        return root;
    }
    return leftlca?leftlca:rightlca;

}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    Node* ans = lca(root,9,8);
    if(ans) cout << ans->data << endl;
    else cout << "No such Nodes" << endl;
    return 0;
}
