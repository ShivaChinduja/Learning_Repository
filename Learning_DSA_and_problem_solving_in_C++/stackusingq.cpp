#include<iostream>
#include<queue>
using namespace std;
class Stack{
    queue<int> q1,q2;
    public:
    void push(int x){
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    void pop(){
        if(!q1.empty()){
            q1.pop();
        }
    }
    void top(){
        if(!q1.empty()){
            cout << q1.front() << endl;
        
        }
    }

};

int main(){
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.top();
    s1.pop();
    s1.pop();
    s1.top();
    return 0;
}