#include<iostream>
#include<stack>
using namespace std;
class Queue{
    stack<int>s1;
    stack<int>s2;
    public:
    void push(int x){
        
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        swap(s1,s2);
    }
    void pop(){
        s1.pop();
    }
    void front(){
        if(!s1.empty()){
            cout << s1.top()<< endl;
        }
    }
};
int main(){
    Queue q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.front();
    q1.pop();
    q1.front();
    return 0;
}