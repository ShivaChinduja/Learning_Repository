#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    vector<Node*> neighbors;
    Node(int x):data(x){}

};
Node* clonee(Node* n,unordered_map<Node*,Node*>& visited){
    if(!n) return nullptr;
    if(visited[n]) return visited[n];
    Node* clone = new Node(n->data);
    visited[n] = clone;
    for(auto nei : n->neighbors){
        clone->neighbors.push_back(clonee(nei,visited));
    }
    return clone;
}
Node* clonegraph(Node* n){
    unordered_map<Node*,Node*> visited;
    return clonee(n , visited);
}
int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->neighbors = {n2,n4};
    n2->neighbors = {n1,n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n3, n1};
    Node* clone = clonegraph(n1);
    cout << clone->data << " ";
    for(auto i: clone->neighbors){
        cout << i->data << " " ;
    }
}