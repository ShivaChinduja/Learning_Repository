#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x):data(x),left(nullptr),right(nullptr){}
};
void dfs(Node* root){
    if(!root) return;  
    dfs(root->left);
    cout<< root->data << "->";
    dfs(root->right);
}
void bfs(Node* root){
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        cout << current->data << "-->";
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
    }

}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    dfs(root);
    cout << "\nbfs\n";
    bfs(root);
    return 0;
}
