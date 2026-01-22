//detect a cycle in linked list using floyd (slow pointer and fast pointer)
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};
class Linkedlist{
    Node* head;
    void insertNode(Node*& head , int value){
        Node* trav = head;
        Node* temp = new Node(value);
        if(head==nullptr){
            head = temp;
            return;
        }
        while(trav->next){
            trav = trav->next;
        }
        trav->next = temp;
        
    }
    void print(Node* h){
        while(h){
            cout << h->data << "->";
            h = h->next;

        }
        cout << endl;
    }
    
    public:
    
    Linkedlist(){
        head = nullptr;
    }
    friend void intersectpoint(Linkedlist* , Linkedlist*);
    void insertN(int x){
        insertNode(head , x);
        print(head);
    }
    void createcycle(){
        Node* secondarynode = head->next;
        Node* tail = head;
        while(tail->next !=nullptr){
            tail = tail->next;
        }
        tail->next = secondarynode;
    }
    void detectcycle(){
        Node* trav = head;
        if(head == nullptr){cout << "No cycle detected"; return;}
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                cout << "Yes its detected" << endl;
                return;
            }
        }
        cout<< "No its not detected"<< endl;    
    }
    void oddeven(){
        
        if(!head || !head->next){
            cout << "nothing to sort" << endl;
        }
        Node* odd = head;
        Node* even = odd->next;
        while(odd){
            if(odd->data%2==0 && even->data%2!=0){
                cout << "Not in order" << endl;
                return;
            }
            odd = (even && even->next) ? even->next : nullptr;
            even = (odd && odd->next) ? odd->next : nullptr;

        }
        sort();

    }
    void sort(){
        Node* prev = nullptr;
        Node* current = head;
        Node* last = head;
        while(last->next){
            last = last->next;
        }
        Node* tail = last;
        Node* stop = tail;
        while(current !=stop){
            if(current->data%2==0){
                //evennumber put it to last;
                if(current==head){
                    head= current->next;
                    tail->next = current;
                    tail = current;
                    current->next = nullptr;
                    current = head;
                }
                else{
                    prev->next = current->next;
                    tail->next = current;
                    tail = current;
                    current = prev->next;
                    tail->next = nullptr;

                }
                
            }
            else{
                prev = current;
                current = current->next;
            }
        }
        print(head);
    }


    
};

void intersectpoint(Linkedlist* l1 , Linkedlist *l2){
    Node* head1 = l1->head;
    
    while(head1) {
        Node* head2 = l2->head;
        while(head2){
            if(head1->data == head2->data){
                cout << "Intersection found "<< head1->data << endl;
                return;
            }
            head2 = head2->next;
        }
        head1 = head1->next;
    }
    cout << "intersection not found" << endl;
}
int main(){
    Linkedlist* obj = new Linkedlist();
    Linkedlist* obj2 = new Linkedlist();
    obj->insertN(3);
    obj->insertN(4);
    obj->insertN(5);
    obj->insertN(6);
    obj->insertN(7);
    obj->insertN(8);
    obj->insertN(9);
    obj->insertN(10);
    obj->detectcycle();
    //obj->createcycle();
    obj->detectcycle();
    obj2->insertN(1);
    obj2->insertN(2);
    obj2->insertN(3);
    obj2->insertN(88);
    obj2->insertN(11);
    obj2->insertN(13);
    obj2->insertN(15);
    intersectpoint(obj , obj2);
    obj->oddeven();


    return 0;
}
