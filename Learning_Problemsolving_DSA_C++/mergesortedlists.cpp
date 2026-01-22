#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node():next(nullptr){}
    Node(int x):data(x),next(nullptr){}
};
void print(Node* head){
    while(head){cout<< head->data<< "->" ;head=head->next;}
    cout << endl;
}
Node* mergesortedlist(Node* l1 , Node* l2){
    if(!l1 && !l2){return nullptr;}
    Node* dummy = new Node();
    Node* trav = dummy;
    while(l1 && l2){
        if(l1->data < l2->data){
            trav->next = l1;
            l1=l1->next;
        }
        else{
            trav->next = l2;
            l2=l2->next;
        }
        trav=trav->next;
    }
    if(l1){trav->next = l1;}
    if(l2){trav->next = l2;}
    return dummy->next;
}
int main(){
    Node* l1 = new Node(1);
    l1->next = new Node(3);
    l1->next->next = new Node(5);
    l1->next->next->next = new Node(7);
    Node* l2 = new Node(2);
    l2->next = new Node(4);
    l2->next->next = new Node(6);
    l2->next->next->next = new Node(8);
    cout << "L1: " ;
    print(l1);
    cout << "L2: " ;
    print(l2);
    Node* res = mergesortedlist(l1,l2);
    cout << "Merged : " ;
    print(res);
    return 0;
}