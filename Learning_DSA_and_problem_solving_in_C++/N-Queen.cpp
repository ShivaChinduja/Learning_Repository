//N-Queens problem
#include<iostream>
#include<vector>
#define N 5
using namespace std;
vector<vector<int>> Board(N,vector<int>(N,0));
bool issafe(int&  r , int& c){
    for(int i=0;i<c;i++){
        if(Board[r][i] == 1){return false;}
    }
    // lower diagnal
    for(int i=r,j=c; i<N && j>=0; i++,j--){
        if(Board[i][j]==1){return false;}
    }
    for(int i=r,j=c;i>=0 && j>=0;i--,j--){
        if(Board[i][j] ==1){return false;}
    }
    return true;
}
void print(vector<vector<int>>& Board){
    for(auto i: Board){
        for(auto j: i){
            if(j == 1){cout << "Q ";}
            else{cout << ". ";}
        }
        cout << endl;
    }
}
bool solveQueen(int col){
    if(col >= N){
        return true;
    }
    for(int row=0;row<N;row++){
        if(issafe(row,col)){
            Board[row][col] = 1;
            if(solveQueen(col+1)){return true;}
            Board[row][col]=0;
        }
    }
    return false;
}
class Node{
    public:
    int data;
    Node* next;
    Node(int d):data(d),next(nullptr){}
};
Node* reverse(Node* h){
    if(!h) return nullptr;
    Node* prev = nullptr;
    Node* current = h;
    Node* next = nullptr;
    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
void print(Node* h){
    Node* temp=h;
    while(temp){cout << temp->data << "->";temp=temp->next;}
    cout << endl;
}
int main(){
    /*if(solveQueen(0)){
        print(Board);
    }
    else{cout << "solution doesnot exists" << endl;}
    */
   Node* head = new Node(1);
   head->next = new Node(2);
   head->next->next = new Node(3);
   head->next->next->next= new Node(4);
   print(head);
   Node* newhead = reverse(head);
   print(newhead);
   
    return 0;
}
